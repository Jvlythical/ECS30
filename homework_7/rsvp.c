//Michael Yen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void display_info (int *ar1, char **ar2, char **ar3, int size);
int get_choice ();

int main (int argc, char *argv[]) {
	char **subj, **crse;
	int *CRN, size;

	size = read_courses (argv[1], &CRN, &subj, &crse);
	display_info (CRN, subj, crse, size);

	return 0;
} //main()

void display_info (int *ar1, char **ar2, char **ar3, int size) {
	int choice;

	while (1) {
		choice = get_choice();

		if (choice == 0) {
			break;
		} //If the user no longer wants to continue
		else {	
			if (choice == 1) {
				find_CRN(ar1, ar2, ar3, size);
			} //If the choice is find by CRN
			else {
				find_subject(ar1, ar2, ar3, size);	
			} //Else the choice is find by subject
		} //Else the user wants to continue
	} //While the user still wants to continue
} //display_info()

int get_choice () {
	int choice;

	while (1) {
		puts ("");
		puts ("RSVP Menu");
		puts ("1. Find by CRN.");
		puts ("2. Find by subject.");
		printf ("%s", "Your choice (0 - 2): ");
		scanf ("%i", &choice);
	
		if (choice == 0 || choice == 1 || choice == 2) {
			break;
		} //If a valid choice is chosen, break out of the loop
		else {
			puts ("Your choice is outside the acceptable range. Please try again.");
		}
	} //Keep prompting the user until a valid choice is chosen
	
	return choice;
} //get_choice()


