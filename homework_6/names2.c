//Michael Yen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 3

int read_names(FILE *fp, char ***person);
int *sort(char ***person, int num_names);
void write_names(char ***person, int *order, int num_names);
void free_memory (char ***person);

int main (int argc, char *argv[]) {
	FILE *fp;
	char **person[MAX_SIZE];
	int num_names, *order;

	fp = fopen (argv[1], "r");
	num_names = read_names(fp, person);
	order = sort(person, num_names);
	write_names (person, order, num_names);

	free_memory(person);
	fclose(fp);

	return 0;
} //main()

int read_names(FILE *fp, char ***person) {	
	char buff[81];
	int num_names = -1, i = 0;

	while (fgets(buff, 80, fp)) {
		int n, k;

		if (i == 0) {
			num_names = strtod(buff, NULL);

			for (n = 0; n < MAX_SIZE; n++) {
				person[n] = malloc (sizeof(char *) * num_names);
				
				for (k = 0; k < num_names; k++) {
					person[n][k] = malloc (sizeof(char) * 16);
				} //Allocate space the name
			} //Allocate space for the three arrays: lastname, firstname, and middle name

		} //If i = 0, initialize the 3-D array
		else {
			for (n = 0; n < MAX_SIZE; n++) {
				if (n == 0) {
					int length;
					
					strcpy(person[n][i - 1], strtok (buff, " \n"));
					length = strlen (person[n][i - 1]);

					if ((int) person[n][i - 1][length - 1] < 65) {
						person[n][i - 1][length - 1] = '\0';
					}
				}
				else {
					int length;
					
					strcpy(person[n][i - 1], strtok (NULL, " \n"));
					length = strlen (person[n][i - 1]);

					if ((int) person[n][i - 1][length - 1] < 65) {
						person[n][i - 1][length - 1] = '\0';
					}
				}
			}
		} //Else the lines are names; begin storing values

		i++;
	} //While there are still names to be read

	return num_names;
}

int *sort(char ***person, int num_names) {
	int i, *order;
	char **last_name = person[0];
	char **first_name = person[1];

	order = malloc (sizeof(int) * num_names);
	
	for (i = 0; i < num_names; i++) {
		order[i] = i;		
	}

	for (i = 1; i < num_names; i++) {
		int j = i - 1;

		while (j >= 0) {
			if (strcmp (last_name[j], last_name[j + 1]) > 0) {	
				int temp = order[j + 1];

				order[j + 1] = order[j--];
				order[j + 1] = temp;
			} //If the first last name is the greater than the second
			else if (strcmp (last_name[j], last_name[j + 1]) == 0) {
				if (strcmp (first_name[j], first_name[j + 1]) > 0) {		
					int temp = order[j + 1];

					order[j + 1] = order[j--];
					order[j + 1] = temp;
				} //If the first first name is greater than the second
			} //If the last names are the same
			else {
				break;
			} //Else break out of the loop
		} //While out of order
	}

	return order;
}

void write_names(char ***person, int *order, int num_names) {
	int n = 0, k;

	for (n = 0; n < num_names; n++) {
		printf ("%s", "\n");

		for (k = 0; k < MAX_SIZE; k++) {
			if (k == 0) {
				printf ("%-17s  ", person[k][order[n]]);		
			}
			else if (k == 1) {
				printf ("%-17s  ", person[k][order[n]]);		
			}
			else {
				printf ("%-17s  ", person[k][order[n]]);		
			}
		}
	}

	printf ("%s", "\n");
}

void free_memory (char ***person) {
	int i;

	for (i = 0; i < MAX_SIZE; i++) {
		free(person[i]);
	}
}
