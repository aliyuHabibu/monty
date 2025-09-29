#include "monty.h"
/**
 * read_and_exec_file - Function to read opcode from opcode file
 * @file: file to read from
 * Return: The opcode with arguemnt if any.
 */
void read_and_exec_file(char *file)
{
	stack_t *head = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	char buffer[BUFSIZE], code[BUFFER];
	int fdno_o, n, ind;
	unsigned int line = 1;

	fdno_o = open(file, O_RDONLY);
	check_file_name(file, fdno_o);
	n = 0;
	ind = 1;
	while (read(fdno_o, buffer, BUFSIZE) > 0)
	{
		if (code[0] == 35)
			handle_comment(buffer, code, &n);
		else if (*buffer == 10)
		{
			if (strcmp(code, "stack") == 0)
				ind = 1;
			else if (strcmp(code, "queue") == 0)
				ind = 0;
			else
			{
				if (ind == 1)
					func = sk(code, line);
				else
					func = qu(code, line);
				if (func == NULL)
				{
					fprintf(stderr, "L<%d>: unknown instruction <opcode>\n", line);
					exit(EXIT_FAILURE);
				}
				func(&head, line++);
			}
			clear_array(code);
			n = 0;
		}
		else if (*buffer != 32)
			code[n++] = *buffer;
	}
	close(fdno_o);
}
