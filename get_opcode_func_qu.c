#include "monty.h"

/**
 * qu - Function that takes a string and return the func opcode
 * @s: Pointer to the character given
 * @l: line number of the opcode
 *
 * Return: a function pointer to the appropriate function
 */
void (*qu(char *s, unsigned int l))(stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = {
		{"pchar", pchar_op},
		{"push", push_op_qu},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"pstr", pstr_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{NULL, NULL}
	};

	void (*func)(stack_t **stack, unsigned int line_number);
	int n;

	n = str_len(s);
	if (n > 4)
	{
		if (strcmp(s, "pchar") == 0)
			func = inst[0].f;
		else
		{
			set_args(s, l);
			func = inst[1].f;
		}
	}
	else
	{
		n = 0;
		while (inst[n].opcode)
		{
			if ((strcmp(inst[n].opcode, s)) == 0)
			{
				if (strcmp(inst[n].opcode, "push") == 0)
				{
					fprintf(stderr, "L<%d>: usage: push integer\n", l);
					exit(EXIT_FAILURE);
				}
				func = inst[n].f;
				break;
			}
			else if (inst[n + 1].opcode == NULL)
				func = NULL;
			n++;
		}
	}
	return (func);
}
