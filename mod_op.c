#include "monty.h"

/**
 * mod_op - Function to add the second to the last and the top/last elements
 * @stack: Double pointer to the head of the stack
 * @line_number: line_number of the operation
 *
 * Return: Nothing.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int mod;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next->next == NULL)
	{
		if (!(current->next->n))
		{
			fprintf(stderr, "L<%d>: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		mod = current->n % current->next->n;
		current->n = mod;
		free(current->next);
		current->next = NULL;
		return;
	}
	else
		mod_op(&(current->next), line_number);
}
