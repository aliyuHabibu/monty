#include "monty.h"

/**
 * rotr_op - Function to reverse node in the d linked list
 * @stack: Double pointer to the head of the nodes
 * @libe_number: line number of the command
 *
 * Return: Nothing.
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new;

	if (*stack == NULL)
		exit(EXIT_FAILURE);

	current = *stack;
	if (current->next == NULL)
		exit(EXIT_SUCCESS);

	while (current->next != NULL)
	{
		current = current->next;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_SUCCESS);
	new->n = (*stack)->n;
	new->prev = current;
	new->next = NULL;
	current->next = new;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(void)line_number;
}
