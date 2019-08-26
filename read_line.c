#include "header.h"

/**
 * main - create shell
 *
 * Return: Success or Fail
 */
char *read_line(void)
{
	char *buf = NULL;
	int characters;
	size_t bufsize = 0;
	fflush(stdin);
	characters = getline(&buf, &bufsize, stdin);
	if (characters == -1){
		//putchar(10);
		exit(1);
	}
	return (buf);
}
