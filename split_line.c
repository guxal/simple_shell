#include "header.h"
/**
 * split_line - Generate argv vector
 *@buf: Line to be splitted
 * Return: double pointer char
 */
char **split_line(char *buf)
{
	char **argv;
	char *temp;
	char *tokenArray;
	int count = 0;

	temp = malloc((_strlen(buf) + 1) * sizeof(char));
	_strcpy(temp, buf);
	tokenArray = strtok(buf, " "); /* It counts parmeters from stdin */
	while (tokenArray != NULL)
	{
		if (_strcmp(tokenArray, " ") > 0)
			count++;
		tokenArray = strtok(NULL, " ");
	}
	argv = (char **) malloc((count) * sizeof(char *));
	if (argv == NULL)
		return (0);
	tokenArray = strtok(temp, " ");
	count = 0;
	while (tokenArray != NULL)
	{
		if (_strcmp(tokenArray, " ") > 0)
		{
			argv[count] = malloc((_strlen(tokenArray)) * sizeof(char));
			argv[count] = _strcpy(argv[count], tokenArray);
			count++;
		}
		tokenArray = strtok(NULL, " ");
	}
	argv[count] = NULL;
	free(temp);
	free(tokenArray);
	return (argv);
}
