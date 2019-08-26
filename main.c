#include "header.h"

/**
 * main - create shell
 *
 * Return: Success or Fail
 */

int main()
{
	/* me guarda el buf*/
	char *buf = NULL;
	/* me guarda el array resultado del strtok */
	char *chainArray;
	/* temporal */
	char *temp;
	/* me guarda un array de strings {"path", "path", "path"} */
	char **argv;
//int i;

	while(EOF)
	{
		/* print prompt */
		//if (isatty(fileno(stdin)))
		printf("#cisfun$ ");

		buf = read_line();

		if (buf == NULL)
		{
			perror("NULL");
		}
		/* en caso de que sea exitosa */
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
