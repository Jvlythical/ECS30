#include <stdio.h>
#include <stdlib.h>

int read_file (const char *path, int ***p);
void show_table (int ***p, int *order);
void sort (int ***p, int *order);
void declare_winner (int *order);

int main () {
	FILE *fp;
	int **buff;
	int valid;
	int order[] = {0, 1, 2, 3, 4};

	valid = read_file ("election1.txt", &buff);

	sort (&buff, order);
	show_table (&buff, order);
	declare_winner (order);

	return 0;
}

int read_file (const char *path, int ***p) {
	FILE *fp;
	int i;
	int v[5];
	int rows = 6, columns = 5;

	fp = fopen (path, "r");
	*p = malloc (rows * sizeof (int *));
	
	for (i = 0; i < rows; i++) {
		p[0][i] = malloc (columns * sizeof (int));
	}

	i = 0;
	while (fscanf (fp, "%i %i %i %i %i", v, v + 1, v + 2, v + 3, v + 4) != EOF) {
		int n;

		for (n = 0; n < columns; n++) {
			p[0][i][n] = v[n];
		} //Iterate through each row

		i++;
	}

	return 1;
}

void show_table (int ***p, int *order) {
	int i, n;

	for (i = 0; i < 2; i++) {
		for (n = 0; n < 5; n++) {
			if (i ==0 && n == 0) {
				printf ("%9s", " ");
			}	
			else if (i == 0 && n > 0) {
				printf ("%11s", "Candidate");
			} //If the row is the first and column is the second
			else {
				if (n == 0 && i == 1) {
					printf ("%8s", "Precinct");
				} 
				else if (n == 1) {
					printf ("%8c", order[n] + 64);
				}
				else {	
					printf ("%11c", order[n] + 64);
				}
			} //Row is not the first row
		}
		printf ("%s", "\n");
	}

	for (i = 0; i < 6; i++) {
		for (n = 0; n < 5; n++) {
			if (i == 5 && order[n] == 0) {
				printf ("%s", "Total: ");
			}
			else if (i == 5 && n == 1 && p[0][i][order[n]] > 999) {	
				printf ("%10i", p[0][i][order[n]]); 
			}
			else if (i == 5) {	
				printf ("%11i", p[0][i][order[n]]); 
			}
			else if (n == 0) {
				printf ("%4i", p[0][i][order[n]]); 
			}
			else if (n == 1) {
				printf ("%13i", p[0][i][order[n]]); 
			}
			else {	
				printf ("%11i", p[0][i][order[n]]); 
			}
		}

		printf ("%s", "\n");
	}
}

void sort (int ***p, int *order) {
	int i, n, total;

	for (i = 1; i < 5; i++) {
		total = 0;

		for (n = 0; n < 5; n++) {
			total = total + p[0][n][i];
		 } //Iterate through the rows

		p[0][5][i] = total;
	} //Iterate through the columns

	for (i = 2; i < 5; i++) {
		int n = i - 1;
		int cur = p[0][5][n + 1];

		while (n > 0 && cur > p[0][5][n]) {
			int temp = order[n + 1];

			order[n + 1] = order[n--];
			order[n + 1] = temp;
		}
	}
}

void declare_winner (int *order) {
	printf ("\nCandidate %c is the winner.\n", order[1] + 64); 
}
