#include "monty.h"

/**
 * main - Main function
 * @argc: Arguments counter
 * @argv: Arguments vector
 * Return:return
 **/

int main(int argc, char *argv[])
{

	stack_t *head = NULL;
	ssize_t read_file;
	size_t buff_size;
	FILE *fi_le;
	char *tokens, *Ptr = NULL;
	unsigned int count = 0;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fi_le = fopen(argv[1], "r");
	if (!fi_le)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_file = _getline(&Ptr, &buff_size, fi_le)) != -1)
	{
		tokens = strtok(Ptr, LIMIT);
		count++;
		if (tokens)
			choose_function(&head, tokens, count);

		else if (!tokens)
			continue;

	}
	if (Ptr)
		free(Ptr);
	free_all(&head);
	fclose(fi_le);
	exit(EXIT_SUCCESS);
}

