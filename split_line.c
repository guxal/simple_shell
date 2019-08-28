#include "header.h"
/**
 * split_line - Generate argv vector
 *@buf: Line to be splitted
 * Return: double pointer char
 */

args_t split_line(char *buf)
{
	args_t argts;
	char **argv;
	char *temp;
	char *delim = " \n\t";
	char *token;
	int count = 0;

	temp = malloc((_strlen(buf) + 1) * sizeof(char));
	temp = _strcpy(temp, buf);
	token = strtok(buf, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	argv = (char **) malloc((count + 1) * sizeof(char *));
	if (argv == NULL)
		return (argts);
	token = strtok(temp, " ");
	count = 0;
	while (token != NULL)
	{
		argv[count] = (char *) _calloc((_strlen(token) + 1), sizeof(char));
		argv[count] = _strcpy(argv[count], token);
		count++;
		token = strtok(NULL, " ");
	}
	argv[count] = NULL;
	argts.argc = count;
	argts.argv = argv;
	free(temp);
	free(token);
	return (argts);
}
