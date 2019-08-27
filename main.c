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

	while (EOF)
	{
		/* print prompt */
		if (isatty(fileno(stdin)))
			printf("#cisfun$ ");
		buf = read_line();
		if (buf == NULL)
		{
			//free(buf);
			perror("NULL");
		}
		else
		{
			args = split_line(buf);
			execute(args.argv);	
			delete_memory(args.argv, args.argc);
		}
		free(buf);
	}
	return (0);
}
