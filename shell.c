#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - simple shell
 *
 *
 */
int main(void)
{
	char *buf = NULL;
	char *token;
	char *tmp;
	char **argv;
	int numTokens;
	int characters = 0, i;
	size_t bufsize = 0;

	while (1)
	{
		fflush(stdin);
		characters = getline(&buf, &bufsize, stdin);

		if (characters == -1)
		{
			perror("ERROR");
		}
		else
		{

		}
	}

	return (0);
}
