#ifndef STDIO_H
	#define STDIO_H
#endif

#ifndef CYTPE_H
	#define CYTPE_H
#endif

#ifndef STDLIB_H
	#define STDLIB_H
#endif

#include <stdio.h>

int read_courses (char *path, int **ar1, char ***ar2, char ***ar3);
void find_CRN (int *ar1, char **ar2, char **ar3, int size);
void find_subject (int *ar1, char **ar2, char **ar3, int size);

int read_courses (char *path, int **ar1, char ***ar2, char ***ar3) {
	FILE *fp;
	char buff[250];
	int n = 0, init_size = 100;
	
	fp = fopen (path, "r");

	if (!fp) {
		puts ("The file could not be opened =(");
		exit (1);
	} //If the file could not be opened, print the error

	initialize (ar1, ar2, ar3, init_size);

	while (fgets(buff, 249, fp)) {
		char temp_str[10];
		int i = 0, k, temp_num, valid = 1;

		if (n == init_size) {
			resize (ar1, ar2, ar3, init_size);
			init_size = init_size * 2;
		} //If the number of elements match the size of the 3 parallel arrays, resize it

		for (i = 0; i < 5; i++) {
			if (!isdigit (buff[i])) {
				valid = 0;
				break;
			}
		} //Check to see if the first 5 elements are numbers

		//if (valid) {
		//	strncpy (temp_str, buff, 5);
			//temp_str[5] = '\0';
			//temp_num = atoi (temp_str);
			//(*ar1)[n] = temp_num;
		//} //If 

		while (!isalnum (buff[i]) && valid) {
			i++;
		} //Find the next alnum char

		for (k = i; k < i + 2; k++) {
			if (!isalpha (buff[i]) || !valid) {
				valid = 0;
				break;
			}
		} //If the next 3 characters is not alpha, line is not valid

		if (valid) {
			//Convert CRN to int and store it
			strncpy (temp_str, buff, 5);
			temp_str[5] = '\0';
			temp_num = atoi (temp_str);
			(*ar1)[n] = temp_num;

			//Store the subject
			strncpy ((*ar2)[n], buff + i, 3);
			strncpy ((*ar3)[n], buff + i + 4, 5);
		
			(*ar2)[n][3] = '\0';

			for (k = 0; k < 5; k++) {
				if (!isdigit ((*ar3)[n][k]) && !isalpha ((*ar3)[n][k])) { 
					(*ar3)[n][k] = '\0';
					break;
				} //Find the end of the str and add a null byte
			} //Iterate through the str
			n++;
		} //If the current line is still valid, store the subject values

		valid = 1;
	} //While there are still lines to be read

	return n;
} //Opens the file, parses it, and stores the result in 3 parallel arrays

void find_CRN (int *ar1, char **ar2, char **ar3, int size) {
	int CRN, subj = 0, i;

	printf ("%s", "Please enter a CRN: ");
	scanf ("%i", &CRN);

	for (i = 0; i < size; i++) {	
		int cur_CRN = ar1[i];
		
		if (cur_CRN == CRN) {
			subj++;
			break;
		}
	} //While there are still elements to be matched against

	if (subj == 0) {
		printf ("CRN %i not found. \n", CRN);
	} //If the CRN was not found
	else {
		printf ("%s %s\n\n", ar2[i], ar3[i]);
	} //Else the CRN aas found
}

void find_subject (int *ar1, char **ar2, char **ar3, int size) {
	char subj[6];
	int i, c, crse  = 0;

	printf ("%s", "Please enter a subject: ");

	//Flush out stdin before reading from it
	while ((c = getchar()) != '\n' && c != EOF);
	fgets (subj, 5, stdin);
	subj[strlen(subj) - 1] = '\0';

	for (i = 0; i < size; i++) {	
		if (strcmp (subj, ar2[i]) == 0) {
			printf ("%i ", ar1[i]);
			printf ("%s ", ar2[i]);
			printf ("%s\n", ar3[i]);

			crse++;
		} //If the subject matches
	} //While there are still courses to be printed

	if (crse == 0) {
		printf ("No courses were found for %s.\n", subj);
	} //If no courses were found print message
} //find_subject()
