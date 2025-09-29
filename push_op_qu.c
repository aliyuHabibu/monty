#include "monty.h"

/**
 * push_op_qu - Function to push inform of que
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the command
 *
 * Return: Nothing.
 */
void push_op_qu(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = args;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	(void)line_number;
}
