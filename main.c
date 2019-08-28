#include "header.h"

/**
 * main - create shell
 *
 * Return: Success or Fail
 */

int main(void)
{
	char *buf = NULL;
	char *get_env;
	char *delim = ":";
	path_t *head;
	args_t args;

	get_env = _getenv("PATH");
	head = create_node(get_env, delim);

	while (EOF)
	{
		/* print prompt */
		if (isatty(fileno(stdin)))
			printf("#cisfun$ ");
		buf = read_line();
		if (buf == NULL)
		{
			free(buf);
			perror("NULL");
		}
		else
		{
			args = split_line(buf);
			execute(args.argv, head);
			delete_memory(args.argv, args.argc);
			free(buf);
		}
	}
	return (0);
}
