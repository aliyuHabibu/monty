#include "monty.h"

/**
 * main - Entry point of my code
 * @ac: number of args
 * @av: pointer to array of args
 *
 * Return: Always success.
 */
int main(int ac, char *av[])
{
	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_and_exec_file(av[1]);
	exit(EXIT_SUCCESS);
}
