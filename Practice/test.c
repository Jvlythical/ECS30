#include <stdio.h>

void test (double **d);

int main () {
	double d[6][6];

	test(d);

	return 0;
}


void test (double **d) {
	puts ("hi");	
}
