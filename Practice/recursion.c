#include <stdio.h>

char *strrchr (const char *str, char c);

int main () {
	char *p;

	p = strrchr ("hi my name is bob", 'i');
	printf ("%s", p);

	return 0;
}

char *strrchr (const char *str, char c) {
	if (str[0] == '\0') {
		return NULL;
	}

	if (str[0] == c && strrchr (str + 1, c) == NULL) {
		return str;
	}

	return strrchr (str + 1, c);
}
