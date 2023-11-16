#include "monty.h"

/**
* stack_add - Adds the top two elements of the stack.
* @head: Head of the list
* @counter: Number of the line
* Return: Void
**/
void stack_add(stack_t **head, unsigned int counter)
{
	int f_add;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	f_add = (*head)->n;
	f_add += (*head)->next->n;
	pop_stack(head, counter);
	(*head)->n = f_add;
}
