#include "monty.h"
/**
 * free_all - Frees memory in stack
 * @head: Head of the list
 * Return: Void - Nothing
 **/

void free_all(stack_t **head)
{
	stack_t *temp;
	stack_t *h_list;

	h_list = *head;

	while (h_list)
	{
		temp = h_list;
		h_list = h_list->next;
		free(temp);
	}
}

/**
 * push_stack - Function for push an element to the stack.
 * @head: Head of the list.
 * @counter: Number of the line.
 * Return: void - nothing
 **/

void push_stack(stack_t **head, unsigned int counter)
{
	stack_t *new_node = NULL;
	int cont = 0;
	char *checker = strtok(NULL, LIMIT);

	if (!checker)
	{
		fprintf(stderr, "L%u: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	while (checker[cont] != '\0')
	{
		if (!isdigit(checker[cont]) && checker[cont] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", counter);
			exit(EXIT_FAILURE);
		}
		cont++;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(checker);
	new_node->prev = NULL;

	if (*head)
	{
		new_node->next = (*head);
		(*head)->prev = new_node;
		(*head) = new_node;
	}
	else
	{
		(*head) = new_node;
		new_node->next = NULL;
	}
}

/**
 * pall_stack - Prints all the values on the stack,
 * starting from the top of the stack.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: void
 **/

void pall_stack(stack_t **head, unsigned int counter __attribute__((unused)))
{
	stack_t *temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack,
 * followed by a new line.
 * @head: Head of the list
 * @counter: Number of the line
 * Return: void
 **/

void pint(stack_t **head, unsigned int counter)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
