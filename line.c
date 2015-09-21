//Michael Yen
#include <stdio.h>
#include <math.h>

int get_problem();
void get2_pt (int *x1, int *y1, int *x2, int *y2);
void get_pt_slope (double *m, int *x, int *y);
void slope_intcpt_prom2_pt (int x1, int y1, int x2, int y2, double *m, double *y_intcpt);
double intcpt_from_pt_slope (int x, int y, double m);
void display2_pt (int x1, int y1, int x2, int y2);
void display_pt_slope (int x, int y, double m);
void display_slope_intcpt (double m, double y_intcpt);

int main () 
{
	int prob, x1, y1, x2, y2;
	int validated = 1;
	double m, y_intcpt;

	while (validated) 
	{
		prob = get_problem ();
	
		if (prob == 1) 
		{
			get2_pt (&x1, &y1, &x2, &y2);
			slope_intcpt_prom2_pt (x1, y1, x2, y2, &m, &y_intcpt);
			display2_pt (x1, y1, x2, y2);
			display_slope_intcpt (m, y_intcpt);
		} //If the user wants 2 point form
		else if (prob == 2) 
		{
			get_pt_slope (&m, &x1, &y1);
			y_intcpt = intcpt_from_pt_slope (y1, y1, m);
			display_pt_slope (x1, y1, m);
			display_slope_intcpt (m, y_intcpt);
		} //Else if the user wants point slope form
		else 
		{
			break;
		} //Else the input is not valid

		printf ("%s", "Do another conversion (Y or N)=> ");
		scanf ("\n%c", &validated);
		
		if (validated == 'N') 
		{
			validated = 0;
		} //If the user doesn't want to continue
		else 
		{
			validated = 1;
		} //Else the user doesn't not want to continue

		printf ("%s", "\n");
	} //While the user wants to continue
	
	return 0;
} 

int get_problem () 
{
	int prob;

	puts ("Select the form that you would like to convert to slope-intercept form!: ");
	puts ("1) Two-point form (you know two points on the line)"); 
	puts ("2) Point-slope form (you know the line's slope and one point)");
	printf ("%s", "=> ");

	scanf ("%i", &prob);

	return prob;
}

void get2_pt ( int *x1, int *y1, int *x2, int *y2) 
{
	printf ("%s", "\nEnter the x-y coordinates of the first point separated by a space=> ");
	scanf ("%i %i", x1, y1);
  
  printf ("%s", "Enter the x-y coordinates of the first point separated by a space=> ");
	scanf ("%i %i", x2, y2);
}

void get_pt_slope (double *m, int *x, int *y) 
{
	printf ("%s", "\nEnter the slope=> ");
	scanf ("%lf", m);

	printf ("%s", "Enter the x-y coordinants of the point separated by a space=> ");
	scanf ("%i %i", x, y);
}

void slope_intcpt_prom2_pt (int x1, int y1, int x2, int y2, double *m, double *y_intcpt) 
{
	*(m) = (double) (y2 - y1) / (double) (x2 - x1);
	*(y_intcpt) = (double) (0 - x1) * (*m) + y1;
}

double intcpt_from_pt_slope (int x, int y, double m) 
{
	double y_intercept;

	y_intercept = m * (0 - x) + y;

	return y_intercept;
}

void display2_pt (int x1, int y1, int x2, int y2) 
{
	puts ("\nTwo-point form");
	printf ("%6s%.2lf- %.2lf)\n", "(", (double) y2, (double) y1);
	puts (" m = -------------");
	printf ("%6s%.2lf - %.2lf)\n", "(", (double) x2, (double) x1);
}

void display_pt_slope (int x, int y, double m) 
{
	puts ("\nPoint-slope form");
	printf ("  y - %.2lf = %.2lf(x - %.2lf)\n", (double) y, m, (double) x);
}

void display_slope_intcpt (double m, double y_intcpt) 
{
	puts ("\nSlope-intercept form");

	if (y_intcpt < 0) 
{
		printf ("  y = %.2lfx - %.2lf\n", m, fabs (y_intcpt));
	}
	else 
{ 
		printf ("  y = %.2lfx + %.2lf\n", m, y_intcpt);
	}
}
