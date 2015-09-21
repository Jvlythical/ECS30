#include "rsvp.h"

void display_info (table *t);
int get_choice ();

int main () {
	table *t;
	
	t = read_courses ();
	display_info (t);

	return 0;
}

void display_info (table *t) {
	int choice;

	while (1) {
		choice = get_choice();

		if (choice == 0) {
			break;
		}
		else {	
			if (choice == 1) {
				find_CRN(t);
			}
			else {
				find_subject(t);	
			}
		}
	}
}

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
		}
		else {
			puts ("Your choice is outside the acceptable range. Please try again.");
		}
	}
	
	return choice;
}


