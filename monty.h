
#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

#define LIMIT " \n"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pall_stack(stack_t **head, unsigned int counter);
void push_stack(stack_t **head, unsigned int counter);
void pint(stack_t **head, unsigned int counter);
void pop_stack(stack_t **head, unsigned int counter);
void swap_stack(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void stack_add(stack_t **head, unsigned int counter);
void stack_sub(stack_t **head, unsigned int counter);
void stack_div(stack_t **head, unsigned int counter);
void stack_mul(stack_t **head, unsigned int counter);
void stack_mod(stack_t **head, unsigned int counter);
void choose_function(stack_t **head, char *token, unsigned int counter);
void free_all(stack_t **head);
#endif

