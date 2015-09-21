#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
	char s[5];
	char t[5] = "Hi";

	if (isupper (strncpy (s, t, 1))) {
		puts ("1");
	}


	return 0;
}
