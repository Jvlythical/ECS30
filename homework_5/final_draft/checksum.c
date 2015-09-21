#include <stdio.h>

char calc_checksum (char *str);

int main () {
	char buff[200];
	char checksum;
	
	do {
		printf ("%s", "Line: ");
		fgets (buff, 200, stdin);
		
		if (buff[0] = '.') {
			break;
		}
		else {
			checksum = calc_checksum (buff);

			printf ("Checksum: %c\n", checksum);
		}
	}
	while (1);

	return 0;
}

char calc_checksum (char *str) {
	char checksum;
	int i = 0;
	int sum = 0;

	while (str[i] != '\n') {
		sum = sum + str[i];
		i++;
	}

	checksum = sum % 64 + ' ';

	return checksum;
}
