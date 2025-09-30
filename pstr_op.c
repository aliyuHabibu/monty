#include "monty.h"

/**
 * pstr_op - Function to print char rep from top of stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the command
 *
 * Return: Nothing.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
		putchar(10);
	current = *stack;
	if (current->next == NULL)
	{
		if (current->n >= 65 && current->n <= 90)
		{
			printf("%c", current->n);
			return;
		}
		else if (current->n >= 97 && current->n <= 122)
		{
			printf("%c", current->n);
			return;
		}
		else if (current->n == 0 || current->prev == NULL)
			exit(EXIT_SUCCESS);
	}
	pstr_op(&(current->next), line_number);
	if (current->n >= 65 && current->n <= 90)
	{
		printf("%c", current->n);
		return;
	}
	else if (current->n >= 97 && current->n <= 122)
	{
		printf("%c", current->n);
		return;
	}
	else if (current->n == 0 || current->prev == NULL)
	{
		putchar(10);
		exit(EXIT_SUCCESS);
	}
}
