#include "monty.h"

/**
 * swap_op - Function to swap value with the top stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the operation
 *
 * Return: Nothing.
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int n;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next->next == NULL)
	{
		n = current->next->n;
		current->next->n = current->n;
		current->n = n;
		return;
	}
	else
		swap_op(&(current->next), line_number);
}
