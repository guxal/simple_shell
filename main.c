#include "header.h"

/**
 * main - create shell
 *
 * Return: Success or Fail
 */

int main(void)
{
	char *buf = NULL;
	char **argv;

	while (EOF)
	{
		if (isatty(fileno(stdin)))
		/* print prompt */
		/* if (isatty(fileno(stdin))) */
		printf("#cisfun$ ");
		buf = read_line();
		if (buf == NULL)
		{
			perror("NULL");
		}
		else
		{
			argv = split_line(buf);
			execute(argv);
			free(buf);
			free(argv);
		}
	}
	return (0);
}
