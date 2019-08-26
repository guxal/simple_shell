#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void delete_memory(int **table, int value);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *read_line(void);
char **split_line(char *buf);
int execute(char **argv);

#endif
