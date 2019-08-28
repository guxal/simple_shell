#include "header.h"

/**
 * main - create shell
 *
 * Return: Success or Fail
 */

int main(void)
{
	char *buf = NULL;
	args_t args;
	node_t node;

	node = build_node();


	while (EOF)
	{
		/* print prompt */
		if (isatty(fileno(stdin)))
			printf("#cisfun$ ");
		buf = read_line();
		if (buf == NULL)
		{
			if (isatty(fileno(stdin)))
				printf("\n");
			break;
		}

		else
		{
			args = split_line(buf);
			execute(args.argv, node.path);
			delete_memory(args.argv, args.argc);
			free(buf);
		}
	}

	free_list(node.path);
	return (0);
}
