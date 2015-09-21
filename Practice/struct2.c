#include <stdio.h>

typedef struct {
	int (*funcp) ();
} test_s;

int test();

int main () {
	test_s t;
	t.funcp = &test;
	t.funcp();

	return 0;
}

int test() {
	puts ("hi");
	
	return 1;
}
