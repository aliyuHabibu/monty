#include "monty.h"

/**
 * pop_op - Function to remove the top node or stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number which indicate the operation
 *
 * Return: Nothing.
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->next == NULL)
	{
		free(current);
		*stack = NULL;
		return;
	}
	else if (current->next->next == NULL)
	{
		free(current->next);
		current->next = NULL;
		return;
	}
	else
		pop_op(&(current->next), line_number);
}
