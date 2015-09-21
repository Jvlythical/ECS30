#ifndef STDLIB_H
	#define STDLIB_H
#endif

#define SUBJ_SIZE 4
#define CRSE_SIZE 6
#define SIZE_MULT 2

void initialize (int **p1, char ***p2, char ***p3, int size);
void resize (int **ar1, char ***ar2, char ***ar3, int size);
void deallocate (int *ar1, char **ar2, char **ar3, int size);

void initialize (int **p1, char ***p2, char ***p3, int size) {
	int i;

	(*p1) = malloc (sizeof (int) * size);
	(*p2) = malloc (sizeof (char *) * size);
	(*p3) = malloc (sizeof (char *) * size);
	
	for (i = 0; i < size; i++) {
		(*p2)[i] = malloc (sizeof (char) * SUBJ_SIZE);	
		(*p3)[i] = malloc (sizeof (char) * CRSE_SIZE);
	}
}

void resize (int **ar1, char ***ar2, char ***ar3, int size) {
	char **new_ar2, **new_ar3;
	int i, n, *new_ar1;
	int new_size = size * SIZE_MULT;
	
	initialize (&new_ar1, &new_ar2, &new_ar3, new_size);
	
	for (i = 0; i < size; i++) {
		new_ar1[i] = (*ar1)[i];
		
		for (n = 0; n < SUBJ_SIZE; n++) {
			new_ar2[i][n] = (*ar2)[i][n];
		}

		for (n = 0; n < CRSE_SIZE; n++) {
			new_ar3[i][n] = (*ar3)[i][n];
		}
	}

	deallocate (*ar1, *ar2, *ar3, size);

	*ar1 = new_ar1;
	*ar2 = new_ar2;
	*ar3 = new_ar3;
}

void deallocate (int *ar1, char **ar2, char **ar3, int size) {
	int i;
	
	free (ar1);

	for (i = 0; i < size; i++) {	
			free (ar2[i]);
			free (ar3[i]);
	}
}
