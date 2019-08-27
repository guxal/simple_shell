#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct args - arguments
 * @argc: numbers of argv
 * @argv: double pointer of strings
 *
 * Description: struct arguments
 */
typedef struct args
{
	int argc;
	char **argv;
} args_t;

int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *read_line(void);
args_t split_line(char *buf);
int execute(char **argv);
void delete_memory(char **table, int value);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
