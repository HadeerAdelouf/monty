#include "monty.h"
/**
 * choose_function - Select function for needing
 * @head: Head of the list
 * @token: Parameters for entry
 * @counter: Number of the line
 *
 * Return: Void - Nothing
 **/
void choose_function(stack_t **head, char *token, unsigned int counter)
{
	instruction_t selector[] = {
		{"pall", pall_stack},
		{"push", push_stack},
		{"pint", pint},
		{"swap", swap_stack},
		{"pop", pop_stack},
		{"nop", nop},
	};

	int move = 0;

	while (move < 10)
	{
		if (strcmp(selector[move].opcode, token) == 0)
		{
			selector[move].f(head, counter);
			return;
		}
		move++;
	}
	if (token[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", counter, token);
		exit(EXIT_FAILURE);
	}
}
