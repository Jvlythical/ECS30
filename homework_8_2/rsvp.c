// MIchael Yen
#include "rsvp.h"

void display_info (Course *c, Student *s, int size, int stu_size);
int get_choice ();

int main (int argc, char *argv[]) 
{
	Course *c;
	Student *s;
	int size, student_size;

	size = read_courses (argv[1], &c);

	student_size = read_students (argv[2], &s);
	display_info (c, s, size, student_size);

	return 0;
} //main()

void display_info (Course *c, Student *s, int size, int student_size) 
{
	int choice;

	while (1) 
	{
		choice = get_choice ();

		if (choice == 0) 
		{	
			break;
		} //If the user no longer wants to continue
		else 
		{	
			if (choice == 1) 
			{			
				find_CRN (c, s, size, student_size);
			} //If the choice is find by CRN
			else if (choice == 2)
			{
				find_subject (c, size);	
			} //Else the choice is find by subject
			else if (choice == 3) 
			{
				add_course (&s, c, student_size, size);
			}
			else 
			{
				remove_course (&s, student_size);
			}
		} //Else the user wants to continue
	} //While the user still wants to continue
} //display_info()

int get_choice () 
{
	int choice;

	while (1) 
	{
		puts ("RSVP Menu");
		puts ("1. Find by CRN.");
		puts ("2. Find by subject.");
		puts ("3. Add course.");
		puts ("4. Remove course.");
		printf ("%s", "Your choice(0 - 4): ");
		scanf ("%i", &choice);
	
		if (choice >= 0 && choice <= 4) 
		{
			break;
		} //If a valid choice is chosen, break out of the loop
		else 
		{		
			puts ("Your choice is outside the acceptable range. Please try again.\n");
		}
	} //Keep prompting the user until a valid choice is chosen
	
	return choice;
} //get_choice()


