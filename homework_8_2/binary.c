//Michael Yen
#include <stdio.h>
#include <string.h>

void display (char *str, int cur_index, int max_size);

int main () 
{
	char bin_num[80];
	int i, validate = 0,  max_size;

	printf ("Binary number: ");
	scanf ("%s", bin_num);

	max_size = strlen (bin_num);

	for (i = 0; i < max_size; i++) 
	{
		if (bin_num[i] == 'x') 
		{
			validate = 1;
			break;
		}
	} //For while there are still letters, find the first x

	if (validate) { 
		display (bin_num, i, max_size);
	}
	else {
		printf ("%s\n", bin_num);
	}

	return 0;
}

void display (char *str, int cur_index, int max_size) 
{
	char str1[80], str2[80];
	int k, i = cur_index;

	if (cur_index == -1) 
	{
		printf ("%s\n", str);
	} //If no more x's print the str
	else 
	{
		str[i] = '0';
		strcpy (str1, str);
		str[i] = '1';
		strcpy (str2, str);

		for (k = i + 1; k < max_size; k++) 
		{
			if (str[k] == 'x') 
			{
				cur_index = k;
				break;
			} //If an x is found, break
		} //Iterate through through the str

		if (cur_index == i) 
		{
			cur_index = -1;
		} //If the cur_index did not change -> no more x's

		//Divide the paths into a binary tree like structure
		display (str1, cur_index, max_size);
		display (str2, cur_index, max_size);
	} //Else there are still x's to be replaced
} //display()
