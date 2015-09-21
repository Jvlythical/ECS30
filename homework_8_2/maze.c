//Michael Yen
#include <stdio.h>
#include <string.h>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

int find_path (char maze[8][10], int row, int col, int prev);

int main (int argc, char *argv[]) 
{
	FILE *fp;
	char maze[8][10], buff[10];
	int i = 0;

	//Open file for reading
	fp = fopen (argv[1], "r");

	while (fgets(buff, 10, fp)) 
	{
		strcpy (maze[i], buff);
		maze[i][8] = '\0';

		i++;
	} //Read the file into a buffer

	if(!find_path (maze, 0, 1, 1)) 
	{
		puts ("No path was found.");
	} //Else maze was not successful

	return 0;
}

int find_path (char maze[8][10], int row, int col, int prev) 
{
	if (prev > 1 && row == 0  && col == 1) 
	{
		return 0;
	} //If the maze winds up back at the start, no path was found

	if (row == 7 && col == 7) 
	{
		printf ("(%i, %i)\n", row, col);
		return 1;
	} //Return condition, if row 7 is reached, maze is successful

	//Depending on which side the maze counter came from,
	//check for a 'O' in a clock wise fashion
	//e.g. If prev is equal to up, then check right, then down, then left, then up

	switch (prev) 
	{
		case UP: 
			if (maze[row][col + 1] == 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col + 1, LEFT);
			} //Check right
			else if (maze[row + 1][col] == 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row + 1, col, UP);
			} //Check down
			else if (maze[row][col - 1] == 'O' && col != 0) 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col - 1, RIGHT);
			} //Check left
			else if (maze[row - 1][col] == 'O' && row != 0) 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row - 1, col, DOWN);
			} //Check up
			else 
			{
				return 0;
			} //Else dead end
			break;
		case RIGHT: 	
			if (maze[row + 1][col] == 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row + 1, col, UP);
			} //Check down
			else if (maze[row][col - 1] == 'O' && col != 0) 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col - 1, RIGHT);
			} //Check left
			else if (maze[row - 1][col] == 'O' && row != 0)
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row - 1, col, DOWN);
			}	//Check up
			else if (maze[row][col + 1] == 'O')
			{	
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col + 1, LEFT);
			} //Check right
			else 
			{
				return 0;
			} //Else dead end
			break;
		case DOWN: 
			if (maze[row][col - 1] == 'O' && col != 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col - 1, RIGHT);
			} //Check left
			else if (maze[row - 1][col] == 'O' && row != 0) 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row - 1, col, DOWN);
			} //Check up
			else if (maze[row][col + 1] == 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col + 1, LEFT);
			} //Check right
			else if (maze[row + 1][col] == 'O')
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row + 1, col, UP);
			} //Check down
			else 
			{
				return 0;
			} //Else dead end
			break;
		case LEFT: 	
			if (maze[row - 1][col] == 'O' && row != 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row - 1, col, DOWN);
			} //Check up
			else if (maze[row][col + 1] == 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col + 1, LEFT);
			} //Check right
			else if (maze[row + 1][col] == 'O') 
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row + 1, col, UP);
			} //Check down
			else if (maze[row][col - 1] == 'O' && col != 0)
			{
				printf ("(%i, %i)\n", row, col);
				return find_path (maze, row, col - 1, RIGHT);
			} //Check left
			else 
			{
				return 0;
			} //Else dead end
			break;
		default: 
			return 0;
	} //switch depending on what the previous location was
} //find_path()
