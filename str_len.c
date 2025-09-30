#include "monty.h"

/**
 * str_len - Function to get the length of a given string
 * @s: string to get the length
 * Return: The number of string counted
 */
int str_len(char *s)
{
	int n = 0;

	if (*s != '\0')
	{
		n++;
		n = n + str_len(s + 1);
	}
	return (n);
}
