#include "monty.h"

/**
 * check_file_name - Function to check file name
 * @file_name: name of the file
 * @fd: file descriptor to check
 *
 * Return: Nothing.
 */
void check_file_name(char *file_name, int fd)
{
	if (file_name == NULL || fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}
