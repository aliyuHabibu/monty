#include "monty.h"

/**
 * clear_array - Function to clear the array before reading another line
 * @str: Pointer to the string or array to clear
 * Return: Nothing.
 */
void clear_array(char *str)
{
	int n, i;

	n = str_len(str);

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
