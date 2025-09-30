#include "monty.h"

/**
 * add_op - Function to add the second to the last and the top/last elements
 * @stack: Double pointer to the head of the stack
 * @line_number: line_number of the operation
 *
 * Return: Nothing.
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int sum;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next->next == NULL)
	{
		sum = current->next->n + current->n;
		current->n = sum;
		free(current->next);
		current->next = NULL;
		return;
	}
	else
		add_op(&(current->next), line_number);
}
