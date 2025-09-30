#include "monty.h"

/**
 * mul_op - Function to add the second to the last and the top/last elements
 * @stack: Double pointer to the head of the stack
 * @line_number: line_number of the operation
 *
 * Return: Nothing.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int mul;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next->next == NULL)
	{
		mul = current->n * current->next->n;
		current->n = mul;
		free(current->next);
		current->next = NULL;
		return;
	}
	else
		mul_op(&(current->next), line_number);
}
