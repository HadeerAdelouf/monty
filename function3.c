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
/**
 * stack_sub - subtracts top element from the second top element of the stack
 * @head: Head of the list
 * @counter: Number of the line
 * Return:Nothing
 **/

void stack_sub(stack_t **head, unsigned int counter)
{
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *stack_div -divides the second top element by the top element of the stack
 * @head: The head of the Stack.
 * @counter: Number of the line.
 * Return: void
 **/
void stack_div(stack_t **head, unsigned int counter)
{
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * stack_mul -  multiplies the second top element with the top element
 * @head: Head of the list
 * @counter: Number of the line
 * Return: Void
 **/

void stack_mul(stack_t **head, unsigned int counter)
{
	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * stack_mod - Computes the modulus
 * @head: A pointer to the top mode node
 * @counter: The current line number of a Monty bytecodes file.
 *
 */
void stack_mod(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*head)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		exit(EXIT_FAILURE);
		return;
	}

	(*head)->next->next->n %= (*head)->next->n;
	pop_stack(head, counter);
}
