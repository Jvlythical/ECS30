#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void allocate_memory (char ***board, int rows, int columns);
void choose_side (char *hum, char *com);
void human_move (char ***board, int *last_move);
void computer_move (char ***board, int *last_move);
int winner (char ***board);
void congrat_winner ();

int main () {
	char hum, com;
	char **board;
	int last_move = 0;

	allocate_memory (&board, 4, 4);
	
	while (!winner(&board)) {
		choose_side (&hum, &com);
		human_move (&board, &last_move);
		computer_move (&board, &last_move);
	}

	return 0;
}

void allocate_memory (char ***board, int rows, int columns) {
	int i, n;

	for (i = 0; i < rows; i++) {
		for (n = 0; n < columns; n++) {
			board[i][n] = malloc (sizeof (char) * 3);
		}
	}
}

void choose_side (char *hum, char *com) {

	while (1) {
	puts ("Would you like to be X or O: ");
	scanf ("%c", hum);

		if (*hum == 'O') {
			*com = 'X';
			break;
		}

		if (*com == 'X') {
			*com = 'O';
			break;
		}
	}
}

void human_move (char ***board, int *last_move) {
	int move;

	puts ("Please enter a number: ");
	scanf ("%i", &move);

	
}
