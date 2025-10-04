#include "monty.h"

/**
 * rotl_op - Function that rotate the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the command
 *
 * Return: Nothing.
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new;
	int lstNum;

	if (*stack == NULL)
		exit(EXIT_SUCCESS);
	current = *stack;
	lstNum = 0;
	if (current->next == NULL)
		exit(EXIT_SUCCESS);

	while (current != NULL)
	{
		if (current->next->next == NULL)
		{
			lstNum = current->next->n;
			break;
		}
		current = current->next;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_SUCCESS);
	new->n = lstNum;
	new->prev = NULL;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
	current->next = NULL;
	free(current->next);
	(void)line_number;
}
