//Michael Yen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIELS 1
#define COORS 2
#define BUD 3
#define IRON_CITY 4;

typedef struct 
{
	char *name;
	int id;
	int inventory;
} beer;

int main () 
{
	FILE *fp;
	char buffer[100];
	int i = 0, id = 0, inventory = 0;
	beer piels, coors, bud, iron_city;
	beer type_beers[4] = {
		piels, 
		coors, 
		bud, 
		iron_city
	};

	type_beers[0].name = "Piels:";
	type_beers[0].id = PIELS;
	type_beers[1].name = "Coors:";
	type_beers[1].id = COORS;
	type_beers[2].name = "Bud:";
	type_beers[2].id = BUD;
	type_beers[3].name = "Iron City:";
	type_beers[3].id = IRON_CITY;

	fp = fopen ("beer.txt", "r");
	
	while (fgets(buffer, 100, fp) != NULL) 
	{
		char *p;
		
		if (*(buffer) == '\n') 
		{
			continue;
		} //If the line is not blank

		if (i == 0) 
		{
			int n = 0;
			int num_beers = sizeof(type_beers)/sizeof(beer);

			while (n < num_beers) 
			{

				if (n == 0) 
				{
					p = strtok (buffer, " ");	
				} //If the line is before the first " " delimiter
				else 
				{
					p = strtok (NULL, " ");
				} //Else the line is past the first " " delimiter
				
				//Convert the data to type int and store it
				type_beers[n].inventory = strtol (p, NULL, 10);
				n++;
			}

		} //If the data file is on the first line
		else 
		{	
			p = strtok (buffer, " ");
			id = strtol(p, NULL, 10);

			p = strtok (NULL, " ");
			inventory = strtol (p, NULL, 10);
			
			type_beers[id - 1].inventory = type_beers[id - 1].inventory + inventory;
		} //Else input data from the subsequent lines

		i++;
	} //While there are still entries in the file

	for (i = 0; i < 4; i++) 
	{
		printf ("%-12s", type_beers[i].name);
		printf ("%4i\n", type_beers[i].inventory);
	} //If there are still data entries, print them

	return 0;
}
