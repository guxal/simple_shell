#include "header.h"
/**
 * *_getenv - get enviroment for name
 * @name: nam
 * Return: enviroment
 */
char *_getenv(const char *name)
{
	char *delim = "=";
	char *token;

	while (*environ)
	{
		token = strtok(*environ, delim);
		if (_strcmp(token, (char *) name) == 0)
			return (strtok(NULL, delim));
		environ++;
	}
	return (NULL);
}
