#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int windows;
	double area;
	char name[20];
}	Rooms;

typedef struct {
	char name[80];
	double price;
	int num_rooms;
	Rooms *room;
} House;

void read_file (char *path, House *house);
void sort (House *house);
void show_results (House house);

int main (int argc, char *argv[]) {
	House house;

	if (argc > 2) {
		puts ("Too many arguments!");
		exit (1);
	}
	else {
		read_file (argv[1], &house);
		sort (&house);
		show_results (house);
	}

	return 0;
}

void read_file (char *path, House *house) {
	Rooms room;
	FILE *fp;
	char buff[80], *p;
	int i = 0, n = 0;

	fp = fopen (path, "r");

	if (!fp) {
		puts ("File could not be opened!");
		exit (1);
	}
	else {
		while (fgets (buff, 79, fp)) {
			if (i == 0) {
				p = strtok (buff, "\n");
				strcpy (house->name, buff);
			}
			else if (i == 1) {
				p = strtok (buff, " ");
				house[0].price = atof (p);
				p = strtok (NULL, "\n");
				house->num_rooms = atoi (p);
				house->room = malloc (sizeof (Rooms) * house->num_rooms);
			}
			else {
				p = strtok (buff, ":");
				room.windows = atoi (p);
				p = strtok (NULL, ":");
				room.area = atof (p);
				p = strtok (NULL, "\n");
				strcpy (room.name, p);

				house->room[n] = room;
				n++;
			}

			i++;
		}
	}
}

void sort (House *house) {
	Rooms temp;
	int i, n;
	
	for (i = 0; i < house->num_rooms; i++) {
		n = i - 1;

		while (n >= 0 && house->room[n].area > house->room[n + 1].area){
			temp = house->room [n + 1];
			house->room [n + 1] = house->room [n];
			house->room [n] = temp;

			n--;
		}
	}
}

void show_results (House house) {
	int i;

	for (i = 0; i < house.num_rooms; i ++) {
		printf ("%lf\n", house.room[i].area);
	}
}
