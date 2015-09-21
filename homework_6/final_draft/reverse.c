#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	char buff[100];
	char *p,  **new_str;
	int i, counter = 0;

	printf ("%s", "Input: ");
	fgets (buff, 100, stdin);

	for (i = 0; i < strlen(buff); i++) {
		if (buff[i] == ' ') {
			counter++;
		}
	}

	new_str = malloc (counter * sizeof(char));
	
	for (i = 0; i <= counter; i++) {
		new_str[i] = malloc (30 * sizeof(char));
		
		if (i == 0) {
			p = strtok (buff, "\n ");
			new_str[i] = p;
		}
		else {
			p = strtok (NULL, "\n ");
			new_str[i] = p;
		}
	}

	printf ("Reversed:");

	for (i = counter; i >= 0; i--) {
		printf (" %s", new_str[i]);
	}

	printf ("%s", "\n");

	return 0;
}
