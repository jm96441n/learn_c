#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Address {
	int id;
	int set;
	char *name;
	char *email;
};

struct Database {
	int max_rows;
	int max_data;
	struct Address *rows;
};

struct Connection {
	FILE *file;
	struct Database *db;
};

// Implemented using a single global database connection
struct Connection *conn; 


void Address_print(struct Address *addr)
{
	printf("%d %s %s \n", addr->id, addr->name, addr->email);
}

void Database_close();

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	Database_close();
	exit(1);
}

void Database_write()
{
	rewind(conn->file);
	int rc = 1;
	// take a chunk of data the size of 1 int, from the address
	// 'conn->db->max_data' points to and write it to 'conn->file'.
	rc = fwrite(&conn->db->max_data, sizeof(int), 1, conn->file);

	// repeat for max rows
	rc = fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file);

	// Since 'rows' is stored in the struct as a pointer to an array of
	// undetermined length, we can't just dump it straight into a file,
	// because all that will do is the _address_ the pointer points
	// to. So instead, we have to save each entry in it manually,
	// explicitly stating how big each one is along the way

	// Calculate the size of each of the strings in the Address structs.
	int string_size = sizeof(char) * conn->db->max_data;

	int i = 0;

	for(i = 0; i < conn->db->max_rows; i++) {
		struct Address *addr = &conn->db->rows[i];
		
		// Same as with 'max_data' and 'max_rows', we're just taking
		// an 'int'-sized chunk of data from the address each member points
		// to, and saving it to the file.
		fwrite(&addr->id, sizeof(int), 1, conn->file);
		fwrite(&addr->set, sizeof(int), 1, conn->file);

		// Here however, since the string members are already pointers
		// to addresses, we don't need to get their addresses; all we 
		// need to know is how big they are (which we figured out
		// before entering the loop)
		fwrite(addr->name, string_size, 1, conn->file);
		rc = fwrite(addr->email, string_size, 1, conn->file);
	}
	if (rc != 1) 
		die("Failed to write database.");
	
	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database.");
}

void Database_load()
{
	int rc = 1;
	// Read data in from 'conn->file' that's the size of 1 int,
	// and store it at the address 'conn->db->max_data' points to
	rc = fread(&conn->db->max_data, sizeof(int), 1, conn->file);

	// repeat for 'conn->db->max_rows'
	rc = fread(&conn->db->max_rows, sizeof(int), 1, conn->file);

	if (rc != 1)
		die("Failed to load database.");
	
	// Since  we don't know what size the rows array might be,
	// we need to calculate the amount of memory it needs,
	// so that we can allocate it and store stuff in there.
	int string_size = sizeof(char) * conn->db->max_data;

	// times two because there are two string fields and 2 int fields
	int address_size = (sizeof(int) * 2) + (string_size * 2);
	int rows_size = address_size * conn->db->max_rows;
	conn->db->rows = malloc(rows_size);

	// 'rows' is an array of arbitrarily sized structs, so we can't just read 
	// it in one big chunk. Instead we have to break it down
	// and manually populate it by reading and storing each of the fields
	// for each address

	int i = 0;
	for (i = 0; i < conn->db->max_rows; i++) {
		struct Address *addr = &conn->db->rows[i];

		// Since the first two members of 'Address' aren't pointers
		// just read in the int data and store in the same addresses
		// as the members themselves

		fread(&addr->id, sizeof(int), 1, conn->file);
		fread(&addr->set, sizeof(int), 1, conn->file);

		// For the strings however, since they are pointers (to char arrays),
		// we need to first allocate the memory that they're going to be pointing to,
		// so that we can use it to store the strings from the file
		addr->name = malloc(string_size);
		fread(addr->name, string_size, 1, conn->file);

		addr->email = malloc(string_size);
		rc = fread(addr->email, string_size, 1, conn->file);
	}

	if (rc != 1) 
		die("Failed to load database");
}

void Database_create()
{
	int i = 0;
	int max_data = conn->db->max_data;
	int max_rows = conn->db->max_rows;
	
	// Calculate and allocate the amount of memory needed for the rows array
	int string_size = sizeof(char) * max_data;
	int address_size = (sizeof(int) * 2) + (string_size * 2);
	int rows_size = address_size * max_rows;
	conn->db->rows = malloc(rows_size);

	for (i = 0; i < max_rows; i++) {
		// make a prototype to initialize it
		struct Address addr = { .id = i, .set = 0 };
	
		// Don't forget to allocate memory for the strings!
		addr.name = malloc(sizeof(char) * max_data);
		addr.email = malloc(sizeof(char) * max_data);

		conn->db->rows[i] = addr;
	}
}

void Database_set(int id, const char *name, const char *email)
{
	int max_data = conn->db->max_data;
	struct Address *addr = &conn->db->rows[id];

	if (addr->set)
		die("Already set, delete it first");
	
	addr->set = 1;
	
	// Get some memory to copy the strings into
	addr->name = malloc(sizeof(char) * max_data);
	addr->email = malloc(sizeof(char) * max_data);
	
	char *res = strncpy(addr->name, name, max_data);
	addr->name[max_data-1] = '\0';

	if(!res)
		die("Name copy failed");
	
	res = strncpy(addr->email, email, max_data);
	addr->email[max_data-1] = '\0';

	if(!res)
		die("Email copy failed");
}

void Database_get(int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set");
	}
}

void Database_delete(int id)
{
	struct Address addr = {.id = id, .set = 0};
	
	// Yep we need to allocate memory for these strings here too;
	// just like we did when we first initialized all the Addresses
	addr.name = malloc(sizeof(char) * conn->db->max_data);
	addr.email = malloc(sizeof(char) * conn->db->max_data);

	conn->db->rows[id] = addr;
}

void Database_list()
{
	int i = 0;
	struct Database *db = conn->db;
	
	printf("MAX DATA: %d\n", db->max_data);
	printf("MAX ROWS: %d\n", db->max_rows);
	
	for (i = 0; i < db->max_rows; i++) {
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

void Database_open(const char *filename, char mode)
{
	// initialize the global connection
	conn = malloc(sizeof(struct Connection));
	if(!conn)
		die("Memory Error");

	conn->db = malloc(sizeof(struct Database));
	if (!conn->db) 
		die("Memory error");
	
	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
		
		if (conn->file) {
			Database_load();
		}
	}

	if(!conn->file)
		die("Failed to open the file");
	
}

void Database_close()
{
	if (conn) {
		// We malloc'd a whole lot of strings up until now,
		// so that means we gotta 'free' em up too
		int i = 0;
		
		for(i = 0; i < conn->db->max_rows; i++) {
			free(conn->db->rows[i].name);
			free(conn->db->rows[i].email);
		}

		// Not to mention the actual array they were stored in
		if(conn->db->rows) free(conn->db->rows);
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
		die("USAGE: ./ex17 <dbfile> <action> [action params]");
	
	char *filename = argv[1];
	char action = argv[2][0];
	
	Database_open(filename, action);

	int id = 0;
	
	if (action != 'c' && action != 'f' && argc > 3) {
		id = atoi(argv[3]);

		if (id >= conn->db->max_rows) 
			die("There are not that many records.");
	}
	
	switch (action) {
		case 'c':
			if (argc != 5) 
				die("Need to supply MAX_ROWS and MAX_DATA");

			Database_create();
			Database_write();
			break;
		
		case 'g':
			if (argc != 4)
				die("Need an id to get");
			
			Database_get(id);
			break;
	
		case 's':
			if (argc != 6)
				die("Need id, name, email to set");

			Database_set(id, argv[4], argv[5]);
			Database_write();
			break;
		case 'd':
			if (argc != 4)
				die("Need id to delete");

			Database_delete(id);
			Database_write();
			break;
		
		case 'l':
			Database_list();
			break;
		
		default:
			die("Invalid action:\n\tc = create\n\tg=get\n\ts=set\n\td=del\n\tl=list\n");
	}

	Database_close();

	return 0;
}
