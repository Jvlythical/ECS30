#include <stdio.h>
#include <string.h>

void find_common_suffix (char *str1, char *str2, char *suffix);

int main () {
	char str1[100], str2[100], suffix[100];

	printf ("%s", "Please input a word: ");
	fgets (str1, 100, stdin);

	printf ("%s", "Please input another word: ");
	fgets (str2, 100, stdin);
	
	find_common_suffix (str1, str2, suffix);
	
	printf ("Longest common suffix: %s", suffix);

	return 0;
}

void find_common_suffix (char *str1, char *str2, char *suffix) {
	int i = 0;
	int length1, length2, length3;

	length1 = strlen (str1);
	length2 = strlen (str2);

	while (str1[length1 - 1 - i] == str2[length2 - 1 - i]) {
		suffix[i] = str1[length1 - 1 - i];

		i++;
	}

	suffix[i] = '\0';

	length3 = strlen(suffix);

	for (i = 0; i < length3 / 2; i++) {
		char temp = suffix[length3 - 1 - i];
		
		suffix[length3 - 1 - i] = suffix[i];
		suffix[i] = temp;
	}
}
