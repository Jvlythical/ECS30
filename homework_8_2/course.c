//Michael Yen
#include "rsvp.h"

int read_courses (char *path, Course **c);
int read_students (char *path, Student **s);
void find_CRN (Course *c, Student *s, int course_size,  int stu_size);
void find_subject (Course *c, int size); 

int read_courses (char *path, Course **c) 
{
	FILE *fp;
	char buff[250];
	int n = 0, init_size = 100;
	
	fp = fopen (path, "r");

	if (!fp) 
	{
		puts ("The file could not be opened =(");
		exit (1);
	} //If the file could not be opened, print the error

	initialize (c, init_size);

	while (fgets(buff, 249, fp)) 
	{
		char temp_str[10];
		int i = 0, k, temp_num, valid = 1;

		if (n == init_size) 
		{
			resize (c, init_size);
			init_size = init_size * 2;
		} //If the number of elements match the size of the 3 parallel arrays, resize it

		for (i = 0; i < 5; i++) 
		{
			if (!isdigit (buff[i])) 
			{	
				valid = 0;
				break;
			}
		} //Check to see if the first 5 elements are numbers
		
		while (!isalnum (buff[i]) && valid) 
		{
			i++;
		} //Find the next alnum char

		for (k = i; k < i + 2; k++) 
		{	
			if (!isalpha (buff[i]) || !valid) 
			{
				valid = 0;
				break;
			}
		} //If the next 3 characters is not alpha, line is not valid

		if (valid) 
		{	
			//Convert CRN to int and store it
			strncpy (temp_str, buff, 5);
			temp_str[5] = '\0';
			temp_num = atoi (temp_str);
			(*c)[n].CRN = temp_num;

			//Store the subject
			strncpy ((*c)[n].subj, buff + i, 3);
			strncpy ((*c)[n].crse, buff + i + 4, 5);
		
			(*c)[n].subj[3] = '\0';

			for (k = 0; k < 5; k++) 
			{	
				if (!isdigit ((*c)[n].crse[k]) && !isalpha ((*c)[n].crse[k])) 
				{ 
					(*c)[n].crse[k] = '\0';
					break;
				} //Find the end of the str and add a null byte
			} //Iterate through the str
			n++;
		} //If the current line is still valid, store the subject values

		valid = 1;
	} //While there are still lines to be read

	return n;
} //Opens the file, parses it, and stores the result in 3 parallel arrays

void find_CRN (Course *c, Student *s, int course_size,  int stu_size) 
{
	int CRN, subj = 0, i, n;

	printf ("%s", "Please enter a CRN: ");
	scanf ("%i", &CRN);

	for (i = 0; i < course_size; i++) 
	{	
		int cur_CRN = c[i].CRN;
		
		if (cur_CRN == CRN) 
		{
			subj++;
			break;
		}
	} //While there are still elements to be matched against

	if (subj == 0) 
	{	
		printf ("CRN %i not found. \n\n", CRN);
	} //If the CRN was not found
	else 
	{	
		printf ("%s %s\n", c[i].subj, c[i].crse);	
		
		for (i = 0; i < stu_size; i++) 
		{
			for (n = 0; n < s[i].num_classes; n++) 
			{
				if (s[i].CRNS[n] == CRN) 
				{
					printf ("%s %s\n", s[i].last_name, s[i].first_name);
					break;
				} //If the CRN of the student  matches
			} //Check all the CRN of a student
		} //Check all the students to see if their CRN match

		printf ("\n");
	} //Else the CRN aas found
} //find_CRN ()

void find_subject (Course *c, int size) 
{
	char subj[6];
	int i, ch, crse = 0;

	printf ("%s", "Please enter a subject: ");

	//Flush out stdin before reading from it
	while ((ch = getchar()) != '\n' && ch != EOF);
	fgets (subj, 5, stdin);
	subj[strlen(subj) - 1] = '\0';

	for (i = 0; i < size; i++) 
	{	
		if (strcmp (subj, c[i].subj) == 0) 
		{
			printf ("%i ", c[i].CRN);
			printf ("%s ", c[i].subj);
			printf ("%s\n", c[i].crse);

			crse++;
		} //If the subject matches
	} //While there are still courses to be printed

	if (crse == 0) 
	{
		printf ("No courses were found for %s.\n\n", subj);
	} //If no courses were found print message
	else 
	{
		puts ("");
	} //Else course was not found
} //find_subject()

void add_course (Student **s, Course *c, int size_stu, int size_course) 
{
	char SID[12]; 
	int CRN, i, n, validate = 0;
	Student stu;

	puts ("Add Course");
	printf ("Please enter the SID of the student: ");
	scanf ("%s", SID);

	for (n = 0; n < size_stu; n++) 
	{
		if (strcmp (SID, (*s)[n].SID) == 0) 
		{
			stu = (*s)[n];
			break;
		} //If the input SID and student SID are the same
	} //For if there are still students to compare SID to
	
	if (stu.num_classes != 5) 
	{
		printf ("Please enter the CRN: ");
		scanf ("%i", &CRN);

		for (i = 0; i < size_course; i++) 
		{
			if (CRN == c[i].CRN) 
			{
				validate = 1;
				break;
			}
		} //For if there are courses left to be compared to

		if (validate) 
		{
			(*s)[n].CRNS[stu.num_classes] = CRN;
			(*s)[n].num_classes++;
			
			printf ("\n");
		} //If the course exists
		else 
		{ 
			printf ("There is no course with CRN #%i\n\n", CRN);
		} //Else the course does not exist
	} //If the student course number is less than 5
	else 
	{
		printf ("You are already taking 5 courses.\n\n");
	} //Else student is already taking 5 courses
} //add_course ()

void remove_course (Student **s, int stu_size) 
{
	char SID[12];
	int CRN, i, n;

	puts ("Remove course");
	printf ("Please enter the SID of the student: ");
	scanf ("%s", SID);

	for (n = 0; n < stu_size; n++) 
	{
		if (strcmp(SID, (*s)[n].SID) == 0) 
		{
			break;
		} //If the SID are the same, break
	}

	printf ("Current course: ");

	for (i = 0; i < (*s)[n].num_classes; i++) 
	{
		printf ("%i ", (*s)[n].CRNS[i]);
	} //For if there are still student courses to print

	printf ("\nPlease enter the CRN: ");
	scanf ("%i", &CRN);
	printf ("\n");
	
	for (i = 0; i < (*s)[n].num_classes; i++) 
	{
		if (CRN == (*s)[n].CRNS[i]) 
		{
			int last_index = (*s)[n].num_classes - 1;

			(*s)[n].CRNS[i] = (*s)[n].CRNS[last_index];

			(*s)[n].num_classes--;
		} //If the CRN is one of the student's saved CRNS
	} //For if the student still has courses to be checked
} //remove_course ()
