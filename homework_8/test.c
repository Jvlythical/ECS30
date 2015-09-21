#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char p;
} test;

typedef struct {
	test *p;
} test2;

int main () {
	test2 *t2;
	test *t;

	t2 = malloc (sizeof (test2));
	t = malloc (sizeof(test));
	
	t->p = 'a';
	t2->p = t;

	printf ("%c", t2->p[0].p);

	return 0;
}
