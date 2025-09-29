#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1
#define BUFFER 1024

extern int args;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instructions_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * Function that takes in a pointer to a character, and return a pointer to
 * a funcction that takes a stack and line number and returns void
 */
void (*sk(char *s, unsigned int l))(stack_t **stack, unsigned int line_number);
void (*qu(char *s, unsigned int l))(stack_t **stack, unsigned int line_number);

/* Miccelenaneous Functions handling test chases */
void read_and_exec_file(char *file);
int str_len(char *s);
void clear_array(char *str);
void set_args(char *str, unsigned int line_number);
void handle_comment(char *buffer, char *array, int *n);
void handle_indicator(char *str, int *indicator);
void check_file_name(char *file_name, int fd);
void handle_two_node(stack_t **stack);
void check_exec_op(int id, char *s, stack_t *h, unsigned int line);
/*bool str_cmp(char *s1, char *s2);*/

/* Opcode Functons */
void push_op_sk(stack_t **stack, unsigned int line_number);
void push_op_qu(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void rotl_op(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
