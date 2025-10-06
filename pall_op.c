#include "monty.h"

/**
 * pall_op - Function to print the value of stack from top
 * @stack: Double pointer to the head of the stack
 * @line_number: line number
 *
 * Return: Nothing.
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
		return;
	current = *stack;
	if (current == NULL)
		return;
	pall_op(&(current->next), line_number);
	printf("%d\n", current->n);
}
