#include "monty.h"

/**
 * handle_comment - Function that handles comments
 * @buffer: Pointer to character read at that instance
 * @array: pointer or array of characters at a line
 * @n: index or character
 *
 * Return: Nothing.
 */
void handle_comment(char *buffer, char *array, int *n)
{
	if (*buffer == 10)
	{
		clear_array(array);
		*n = 0;
	}
	else
		array[*n++] = *buffer;
}
