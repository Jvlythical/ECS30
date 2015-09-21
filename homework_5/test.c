#include <stdio.h>

int main () {
	FILE *fp;
	char buff[50];
	int test;
	double test2;

	fp = fopen ("data.txt", "r");
	while (fscanf (fp, "%i%lf", &test, &test2) != EOF) {
		printf ("%i %lf", test, test2);
	}


	
	return 0;
}
