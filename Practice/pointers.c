#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test (char ***p);
void test2 (int **p);

int main () {
	char **p;
	int *p2;

	test2 (&p2);
	p2[1] = 2;

	printf ("%i", p2[1]);

	return 0;
}

void test (char ***p) {
	int i;

	(*p) = (char **) malloc (sizeof (char *) * 10);
	
	for (i = 0; i < 10; i++) {
		(*p)[i] = (char *) malloc (sizeof (char) * 10);
	}

	strncpy ((*p)[1], "bye", 5);
	//printf ("%c", *p[1][0]);
}

void test2 (int **p) {
	(*p)= malloc (10 * sizeof(int));

}
