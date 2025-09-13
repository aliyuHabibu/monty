#include "monty.h"

/**
 * push_op - Function that performs the push operation
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the operation
 *
 * Return: Nothing.
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Could not allocate\n");
		exit(EXIT_FAILURE);
	}

	new->n = args;
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		current = *stack;
		while (current != NULL)
		{
			if (current->next == NULL)
				break;
			current = current->next;
		}
		new->prev = current;
		current->next = new;
		new->next = NULL;
	}
	(void)line_number;
}
