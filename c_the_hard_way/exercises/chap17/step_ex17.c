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
	int max_data;
	int max_rows;
	struct Address *rows; 
};

struct Connection {
	FILE *file;
	struct Database *db;
};

// Implement global connection
struct Connection *conn;

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// forward declaration
void Database_close();

void die(const char *message)
{
	if(errno){
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	Database_close();
	exit(1);
}

void Database_load()
{
	int rc = 0;
	int i = 0;

	fread(&conn->db->max_data, sizeof(int), 1, conn->file);
	rc = fread(&conn->db->max_rows, sizeof(int), 1, conn->file);

	if(rc != 1)
		die("Failed to load database");
	
	int string_size = sizeof(char) * conn->db->max_data;
	int address_size = (sizeof(int) * 2) + (string_size * 2);
	int rows_size = address_size * conn->db->max_rows;

	conn->db->rows = malloc(rows_size);

	for(i = 0; i < conn->db->max_rows; i++) {
		struct Address *addr = &conn->db->rows[i];

		fread(&addr->id, sizeof(int), 1, conn->file);
		fread(&addr->set, sizeof(int), 1, conn-> file);
		
		addr->name = malloc(string_size);
		fread(addr->name, string_size, 1, conn->file);
		
		addr->email = malloc(string_size);
		rc = fread(addr->email, string_size, 1, conn->file);
	}

	if(rc != 1)
		die("Failed to load database.");
}

void Database_open(const char *filename, char action)
{
	conn = malloc(sizeof(struct Connection));
	if(!conn)
		die("Memory error.");
	
	conn->db = malloc(sizeof(struct Database));
	
	if(!conn->db)
		die("Memory error.");
	
	if(action == 'c'){
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) 
			Database_load();
	}

	if (!conn->file)
		die("Failed to open the file.");
};

void Database_create()
{
	int max_rows = conn->db->max_rows;
	int max_data = conn->db->max_data;
	int i = 0;

	int string_size = sizeof(char) * max_data;
	int address_size = (sizeof(int) * 2) + (string_size * 2);
	int rows_size = address_size * max_rows;
	conn->db->rows = malloc(rows_size);

	for(i = 0; i < max_rows; i++) {
		struct Address addr = {.id = i, .set = 0};

		addr.name = malloc(string_size);
		addr.email = malloc(string_size);

		conn->db->rows[i] = addr;
	}
}	

void Database_write()
{
	rewind(conn->file);
	int rc = 1;
	rc = fwrite(&conn->db->max_data, sizeof(int), 1, conn->file);
	rc = fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file);

	if(rc != 1)
		die("Failed to write to database");
	
	int string_size = sizeof(char) * conn->db->max_data;
	int i = 0;
	for(i = 0; i < conn->db->max_rows; i++) {
		struct Address *addr = &conn->db->rows[i];
		
		fwrite(&addr->id, sizeof(int), 1, conn->file);
		fwrite(&addr->set, sizeof(int), 1, conn->file);

		fwrite(addr->name, string_size, 1, conn->file);
		rc = fwrite(addr->email, string_size, 1, conn->file);
	}
	if (rc != 1)
		die("Failed to write to the database");
	
	rc = fflush(conn->file);

	if (rc == -1)
		die("Could not flush database");
}

void Database_set(int id, const char *name, const char *email)
{
	int max_data = conn->db->max_data;
	struct Address *addr = &conn->db->rows[id];
	printf("%d %s %s\n", id, name, email);
	if(addr->set)
		die("Already set, delete it first.");
	
	addr->set = 1;

	addr->name = malloc(sizeof(char) * max_data);
	addr->email = malloc(sizeof(char) * max_data);

	char *res = strncpy(addr->name, name, max_data);
	addr->name[max_data - 1] = '\0';
	
	if(!res) {
		die("Name copy failed");
	} else {
		printf("Name Copied!\n");
	}
		
	res = strncpy(addr->email, email, max_data);
	addr->email[max_data - 1] = '\0';

	if(!res) {
		die("Email copy failed");
	} else {
		printf("Email Copied!\n");
	}
	printf("Address: ");
	Address_print(addr);
}

void Database_list()
{
	struct Database *db = conn->db;
	printf("MAX_DATA: %d\n", db->max_data);
	printf("MAX_ROWS: %d\n", db->max_rows);

	int i = 0;

	for(i = 0; i < db->max_rows; i++) {
		struct Address *cur = &db->rows[i];
		
		if(cur->set) {
			Address_print(cur);
		}
	}
}

void Database_get(int id) 
{
	struct Address *addr = &conn->db->rows[id];
	if (addr->set) {
    	Address_print(addr);
	} else {
		die("An address with that id does not exist");
	}
}

void Database_delete(int id)
{
	struct Address addr = { .id = id, .set = 0 };
	addr.name = malloc(sizeof(char) * conn->db->max_data);
	addr.email = malloc(sizeof(char) * conn->db->max_data);
	conn->db->rows[id] = addr;
}

void Database_find(char *search_term)
{
	int max_rows = conn->db->max_rows;
	// int max_data = conn->db->max_data;

	int i = 0;
	for(i = 0; i < max_rows; i++) {
		struct Address *addr = &conn->db->rows[i];
		if(strcmp(addr->name, search_term) == 0 || strcmp(addr->email, search_term) == 0){ 		
			Address_print(addr);
			return;
		}
	}
	printf("No address found with either name or email: %s\n", search_term);
}

void Database_close()
{
	if(conn) {
		int i = 0;
		for(i = 0; i < conn->db->max_rows; i++) {
			free(conn->db->rows[i].name);
			free(conn->db->rows[i].email);
		}
	
		if(conn->db->rows) free(conn->db->rows);
		if(conn->db) free(conn->db);
		if(conn->file) fclose(conn->file);
		free(conn);
	}
}

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	char action = argv[2][0];
	int id = 0;

	if (argc < 3)
		die("USAGE: ./step_ex17 <dbfile> <action> [action params]");
	
	if(argc > 3 && action != 'c' && action != 'f') {
		id = atoi(argv[3]);	
	}

	Database_open(filename, action);

	switch(action) {
		case 'c':
			if(argc != 5)
				die("MAX_DATA and MAX_ROWS required");
			conn->db->max_data = atoi(argv[3]);
			conn->db->max_rows = atoi(argv[4]);
			Database_create();
			Database_write();
			break;
		case 's':
			if (argc != 6) 
				die("Need id, name, email to set");
			Database_set(id, argv[4], argv[5]);
			Database_write();
			break;
		case 'g':
			if(argc != 4)
				die("Need id to get");
			Database_get(id);
			break;
		case 'l':
			Database_list();
			break;
		case 'd':
			Database_delete(id);
			Database_write();
			break;
		case 'f':
			Database_find(argv[3]);
			break;
		default:
			die("Invalid action: \n\tc=create,\n\tg=get,\n\ts=set,\n\tl=list,\n\td=delete");
			break;
	}
	Database_close();

	return 0;
}
