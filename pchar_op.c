#include "monty.h"

/**
 * pchar_op - Function to print the char rep at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the command
 *
 * Return: Nothing
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->next == NULL)
	{
		if (current->n >= 65 && current->n <= 90)
			printf("%c\n", current->n);
		else if (current->n >= 97 && current->n <= 122)
			printf("%c\n", current->n);
		else
		{
			fprintf(stderr, "L<%d>: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
		pchar_op(&(current->next), line_number);
}
