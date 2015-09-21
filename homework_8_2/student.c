//Michael Yen
#include "rsvp.h"

int read_students (char *path, Student **s);

int read_students (char *path, Student **s) {
	FILE *fp;
	char buff[100];
	int init_size = 10, i = 0, length;

	fp = fopen (path, "r");

	initialize_student (s, init_size);

	if (!fp) {
		puts ("File could not be opened");
		exit (1);
	} //If the file could not be opened
	else {
		while (fgets (buff, 99, fp)) {
			char *p;
			int n = 0;

			if (i == init_size) {
				resize_student (s, init_size);
				init_size = init_size * 2;
			} //If 10 student slots are filled, resize the student array

			//Save the student last name
			p = strtok (buff, ",");
			length = strlen (p);
			(*s)[i].last_name = malloc (sizeof (char) * length);
			strcpy ((*s)[i].last_name, p);

			//Save the student first name
			p = strtok (NULL, ",");
			length = strlen (p);
			(*s)[i].first_name = malloc (sizeof (char) * length);
			strcpy ((*s)[i].first_name, p);

			//Save the student SID
			p = strtok (NULL, ", ");
			strcpy ((*s)[i].SID, p);

			while ((p = strtok (NULL, ",\n")) != NULL) {
					(*s)[i].CRNS[n] = atoi (p);
					(*s)[i].num_classes = ++n;
			} //While there are still CRNS to add

			i++;
		} //While there are still lines to be read
	} //Else the file could be opened

	return i;
} //read_students ()


