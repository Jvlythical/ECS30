#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char crn[6];
	char subj[4];
	char crse[6];
} course;

typedef struct {
	int length;
	course *course_record;
} course_table;

course_table *read_courses ();
void find_crn (course_table *course_table);

course_table *read_courses () {	
	FILE *fp;
	char buff[250];
	int n = 0;
	course_table *t;

	//Allocate memory for a course_table object
	t = malloc (sizeof (course_table));

	//Allocate memory for 5000 course_record
	t->course_record = malloc (sizeof (course_record) * 5000);
	fp = fopen ("test.txt", "r");

	if (!fp) {
		puts ("The file could not be opened =(");
		exit(1);
	}

	while (fgets (buff, 249, fp)) {
		int i, valid = 1;
		course_record r;

		for (i = 0; i < 5; i++) {
			if (!isdigit (buff[i])) {
				valid = 0;
				break;
			}
		} //Check to see if the first 5 elements are numbers

		if (valid) {
			strncpy (r.crn, buff, 5);
			r.crn[5] = '\0';
			//printf ("%s\n", r.crn);
		}

		while (!isalnum(buff[i]) && valid) {
			i++;
		} //Continue until a number or letter is found

		for (i = i; i < 3; i++) {
			if (!isalpha (buff[i])) {
				valid = 0;
				break;
			}
		} //Check to see if there are three consecutive letters

		if (valid) {
			strncpy (r.subj, buff + i, 3);
			strncpy (r.crse, buff + i + 4, 4);
			r.subj[3] = '\0';
			r.crse[5] = '\0';

			t->course_record[n] = r;
			t->length = n + 1;

			n++;
		}


		valid = 1;
	}
	
	return t;
}

void find_CRN(course_table *t) {
	int CRN, subj = 0, i;
	int length = t->length;

	printf ("%s", "Please enter a CRN: ");
	scanf ("%i", &CRN);

	for (i = 0; i < length; i++) {	
		int cur_CRN = strtod(t->course_record[i].crn, NULL);
		
		if (cur_CRN == CRN) {
			subj++;
			break;
		}
	}

	if (subj == 0) {
		printf ("CRN %i not found. \n", CRN);
	}
	else {
		printf ("%s %s\n\n", t->course_record[i].subj, t->course_record[i].crse);
	}
}


void find_subject (course_table *t) {
	char subj[6];
	int i, c, crse  = 0, length = t->length;

	printf ("%s", "Please enter a subject: ");

	//Flush out stdin before reading from it
	while ((c = getchar()) != '\n' && c != EOF);
	fgets (subj, 5, stdin);
	subj[strlen(subj) - 1] = '\0';

	for (i = 0; i < length; i++) {	
		if (strcmp (subj, t->course_record[i].subj) == 0) {
			printf ("%s ", t->course_record[i].crn);
			printf ("%s ", t->course_record[i].subj);
			printf ("%s\n", t->course_record[i].crse);

			crse++;
		}
	}

	if (crse == 0) {
		printf ("No courses were found for %s\n", subj);
	}
}
