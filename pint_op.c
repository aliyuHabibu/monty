#include "monty.h"

/**
 * pint_op - Function to print the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number the opcode is
 *
 * Return: Nothing.
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	}
	current = *stack;
	if (current->next == NULL)
	{
		printf("%d\n", current->n);
		return;
	}
	else if (current->next->next == NULL)
	{
		printf("%d\n", current->next->n);
		return;
	}
	else
		pint_op(&(current->next), line_number);
}
