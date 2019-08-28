#include "header.h"

/**
 * *read_line - read line for stdin
 * Return: Success or Fail
 */
char *read_line(void)
{
	char *buf = NULL;
	int characters;
	size_t bufsize = 0;

	fflush(stdin);
	characters = getline(&buf, &bufsize, stdin);
	if (characters == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
