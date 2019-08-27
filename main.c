#include "header.h"

/**
 * main - create shell
 *
 * Return: Success or Fail
 */

int main(void)
{
	/* it saves the buffer*/
	char *buf = NULL;
	/* it saves the parsed array from strtok*/
	char *chainArray;
	/* temporal */
	char *temp;
	/* it saves the strings array argv {"path", "path", "path"} */
	char **argv;
/*int i;*/

	while (EOF)
	{
		/* print prompt */
		/* if (isatty(fileno(stdin))) */
		printf("#cisfun$ ");

		buf = read_line();

		if (buf == NULL)
		{
			perror("NULL");
		}
		/* when read_line sucessull */
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
