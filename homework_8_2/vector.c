//Michael Yen
#include "rsvp.h"

#define SUBJ_SIZE 4
#define CRSE_SIZE 6
#define SIZE_MULT 2

void initialize (Course **c, int size);
int initialize_student (Student **s, int size);
void resize (Course **c, int size);
int resize_student (Student **s, int size);
void deallocate (Course *c);
void deallocate_student (Student *s);

void initialize (Course **c, int size) 
{
	*c = malloc (sizeof (Course) * size);
} //initialize ()

int initialize_student (Student **s, int size) 
{
	*s = malloc (sizeof (Student) * size);

	return size;
} //initialize_student ()

void resize (Course **c, int size) 
{
	Course *new_c;
	int i, n;
	int new_size = size * SIZE_MULT;
	
	initialize (&new_c, new_size);
	
	for (i = 0; i < size; i++) 
	{
		new_c[i].CRN = (*c)[i].CRN;
		
		for (n = 0; n < SUBJ_SIZE; n++) 
		{
			new_c[i].subj[n] = (*c)[i].subj[n];
		} //Size of each subj

		for (n = 0; n < CRSE_SIZE; n++) 
		{
			new_c[i].crse[n] = (*c)[i].crse[n];
		} //Size of each course
	} //While the current size has not been reached

	deallocate (*c);

	*c = new_c;
} //resize ()

int resize_student (Student **s, int size) {
	Student *new_s;
	int i, n, length; 
	int new_size = size * SIZE_MULT;

	initialize_student (&new_s, new_size);

	for (i = 0; i < size; i++) {
		//Copy the first name
		length = strlen ((*s)[i].first_name);
		new_s[i].first_name = malloc (sizeof (char) * length);
		strcpy (new_s[i].first_name, (*s)[i].first_name);

		//Copy the last_name
		length = strlen ((*s)[i].last_name);
		new_s[i].last_name = malloc (sizeof (char) * length);
		strcpy (new_s[i].last_name, (*s)[i].last_name);

		//Copy the student SID
		strcpy (new_s[i].SID, (*s)[i].SID);

		for (n = 0; n < 5; n++) {
			new_s[i].CRNS[n] = (*s)[i].CRNS[n];
		} //For if the student still has courses to be copied

		new_s[i].num_classes = (*s)[i].num_classes;
	} //For if there are still students to be copied

	deallocate_student (*s);
	*s = new_s;

	return new_size;
}

void deallocate (Course *c) 
{
	free (c);
} //deallocate()

void deallocate_student (Student *s) {
	free (s);
} //deallocate_student ()
