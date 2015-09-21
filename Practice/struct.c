#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int CRN;
	char subj[4];
	char crse[6];
} Course;

void create_crse (Course **crse);

int main () {
	Course *c;

	create_crse (&c);

	c[0].CRN = 10;
	c[0].subj[0] = 'k';

	printf ("%c", c[0].subj[0]);

	return 0;
}

void create_crse (Course **crse) {
	*crse = malloc (sizeof (Course) * 10);
	(*crse)[1].subj[0] = 'm';
	printf ("%c", ((*crse)[1].subj[0]));
}


