#include <stdio.h>

void test (FILE *fp) {
	char buff[100];
	fgets (buff, 199, fp);
	printf ("%s", buff);
}

int main () {
	FILE *fp;
	char buff[200];

	fp = fopen ("final.txt", "r");

	fgets (buff, 199, fp);

	test (fp);

	return 0;
}
