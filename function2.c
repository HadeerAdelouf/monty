#include"monty.h"
/**
 * pop_stack - Removes the top element of the stack.
 * @head: Head of the list0
 * @counter: Number of the line
 * Return: void - nothing
 **/
void pop_stack(stack_t **head, unsigned int counter)
{
	stack_t *new_list = *head;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}
	new_list = (*head)->next;
	free(*head);
	*head = new_list;
}


/**
 * swap_stack - Swaps the top two elements of the stack.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void
 **/

void swap_stack(stack_t **head, unsigned int counter)
{
	int tmp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
/**
 * nop - Doesn’t do anything.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void - Nothing
 **/
void nop(stack_t **head, unsigned int counter)
{
	(void) head;
	(void) counter;
}
