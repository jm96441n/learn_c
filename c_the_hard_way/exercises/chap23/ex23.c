#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count)
{
	int i = 0;

	for(i = 0; i < count; i++) {
		to[i] = from[i];
	}

	return i;
}

int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		switch (count % 8) {
			case 0:
				do {
					*to++ = *from++;
					case 7:
					*to++ = *from++;
					case 6:
					*to++ = *from++;
					case 5:
					*to++ = *from++;
					case 4:
					*to++ = *from++;
					case 3:
					*to++ = *from++;
					case 2:
					*to++ = *from++;
					case 1:
					*to++ = *from++;
				} while (--n > 0);
		}
	}

	return count;
}

int zeds_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		switch (count % 8) {
			case 0:
again: *to++ = *from++;

				case 7:
			*to++ = *from++;
				case 6:
			*to++ = *from++;
				case 5:
			*to++ = *from++;
				case 4:
			*to++ = *from++;
				case 3:
			*to++ = *from++;
				case 2:
			*to++ = *from++;
				case 1:
			*to++ = *from++;
			if (--n > 0)
				goto again;
		}
	}

	return count;
}

int valid_copy(char *data, int count, char expects)
{
	int i = 0;
	for (i = 0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	char from[5] = { 'a' };
	char to[5] = { 'c' };
	int rc = 0;

	// setup the from to have some stuff
	memset(from, 'x', 5);
	// set it to a failure mode
	memset(to, 'y', 5);
	check(valid_copy(to, 5, 'y'), "Not initialized right.");

	// use normal copy to
	rc = normal_copy(from, to, 5);
	check(rc == 5, "Normal copy failed: %d", rc);
	check(valid_copy(to, 5, 'x'), "Normal copy failed.");

	// reset
	memset(to, 'y', 5);

	// duffs version
	rc = duffs_device(from, to, 5);
	check(rc == 5, "Duff's device failed: %d", rc);
	check(valid_copy(to, 5, 'x'), "Duff's device copy failed.");

	// reset
	memset(to, 'y', 5);

	// zeds version
	rc = zeds_device(from, to, 5);
	check(rc == 5, "Zed's device failed: %d", rc);
	check(valid_copy(to, 5, 'x'), "Zed's device failed copy.");

	return 0;
error:
	return 1;
}

