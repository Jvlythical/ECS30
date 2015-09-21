//Michael 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char argv[]) 
{
	FILE *fp;
	char buffer[100];
	int i = 0;
	int n = 0;
	double num = 0, largest = 0, avg = 0, sd = 0;
	double smallest = 100000000;

	fp = fopen (argv[1], "r");

	while (fgets (buffer, 100, fp) != NULL) 
	{
		char *p;
		double temp;

		if (i == 0) 
		{
			num = strtod (buffer, NULL);
		} //If the line read is the first
		else 
		{
			while (n < num) 
			{
				if (n == 0) 
				{
					p = strtok (buffer, " ");
				} //If this is the first call to strtok
				else 
				{
					p = strtok (NULL, " ");
				} //Subsequent calls to strtok

				temp = strtod (p, NULL);

				if (temp > largest) 
				{
					largest = temp;
				} //If temp is larger than the largest number, it is now the largest
			
				if (temp < smallest) 
				{				
					smallest = temp;
				} //If temp is smaller than the cur smallest number, it is now the smallest

				n++;
			
			avg = avg + temp;
			sd = sd + temp * temp;
			} //While there are still numbers  
		} //If the line being read is not the first

		i++;
	} //While there are still lines to read

	//Average is equal to the sume of the numbers divided by the number of numbers
	avg = avg / num;
	sd = sqrt (sd / num - avg * avg);

	printf ("Smallest: %.2lf", smallest);
	printf ("\nLargest: %.2lf", largest);
	printf ("\nAverage: %.2lf", avg);
	printf ("\nStandard deviation: %.2lf\n", sd);

	return 0;
}
