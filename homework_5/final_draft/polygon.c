#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 20

int get_corners (FILE *fpi, double *x, double *y, int max_size);
void output_corners (FILE *fpo, double *x, double *y, int size);
double polygon_area (double *x, double *y, int size);

int main () {
	FILE *fpi, *fpo;
	int size;
	double area;
	double x[20];
	double y[20];
	
	fpi = fopen ("data.txt", "r");
	fpo = fopen ("data2.txt", "a+");
	size = get_corners (fpi, x, y, MAX_SIZE);
	output_corners (fpo, x, y, size);
	area = polygon_area (x, y, size);

	printf ("The area is %.1lf\n", area);

	return 0;
}

int get_corners (FILE *fpi, double *x, double *y, int max_size) {
	int i = 0;
	double x_cor = 0;
	double y_cor = 0;

	while (fscanf (fpi, "%lf %lf", &x_cor, &y_cor) != EOF) {
		*(x + i) = x_cor;
		*(y + i) = y_cor;

		i++;
	}

	return i;
}

void output_corners (FILE *fpo, double *x, double *y, int size) {
	int i;

	for (i = 0; i < size; i++) {
		fprintf (fpo, "%.1lf ", x[i]);
		fprintf (fpo, "%.1lf\n", y[i]);
	}
}

double polygon_area (double *x, double *y, int size) {
	int i = 0;
	double area = 0;
	
	for (i = 0; i < size - 2; i++) {
		area = area + (x[i + 1] + x[i]) * (y[i + 1] - y[i]);
	}

	area = fabs(area / 2);

	return area;
}


