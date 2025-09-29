#include "monty.h"

/**
 * set_args - Function to get args from an array of the line
 * @str: Pointer to the array
 * Return: Nothing.
 */
int args;
void set_args(char *str, unsigned int line_number)
{
	char num[BUFFER];
	int n, s, len;

	s = 4;
	n = 0;
	len = str_len(str);
	while (s <= len)
	{
		num[n] = str[s];
		n++;
		s++;
	}
	s = atoi(num);
	if (num[0] != '0' && s == 0)
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
	else
		args = atoi(num);
	clear_array(num);
}
