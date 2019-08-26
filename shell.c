#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void delete_memory(char **table, int value)
{
	int i;

	
	for (i = 0; i < value; i++)
		free(table[i]);
	free(table);
}
/**
 * *_calloc - call
 * @nmemb: n
 * @size: size
 * Return: 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *memory;

	if (nmemb == 0 || size == 0)
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		*(memory + i) = 0;
	return ((void *)memory);
}
/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", buffer[i]);
        i++;
    }
    printf("\n");
}
/**
 * _strlen - string legth
 * @str: string
 * Return: integer length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;
	return (i);
}
/**
 * *_strcpy - copy string
 * @dest: destination
 * @src: source
 * Return: copy destination
 */
char *_strcpy(char *dest, char *src)
{
	int str = _strlen(src);
	int i;

	for (i = 0; i <= str; i++)
	{
			dest[i] = src[i];
	}

	return (dest);
}
/**
 * main - simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *buf = NULL;
	char *token = NULL;
	char *tmp = NULL;
	char *delim = " \n\t";
	char **argv = NULL;
	int numTokens;
	int characters = 0; 
	int i;
	int status = 1;
	pid_t pid;
	size_t bufsize = 0;

	do
	{
		printf("#cisfun...$ ");
		fflush(stdin);
		characters = getline(&buf, &bufsize, stdin);
		if (characters == -1)
		{
			perror("ERROR");
			exit(1);
		}
		else
		{
			printf("buf : %s", buf);
			printf("strlen buf : %d\n", _strlen(buf));
			//i = _strlen(buf);
			//tmp = malloc(i * sizeof(char));	
			//if (tmp == NULL)
			//	exit(1);
			tmp = _calloc((unsigned int) _strlen(buf) + 1, sizeof(char));
			printf("sizeof : %lu\n", sizeof(tmp));
			//printf("caracter %p\n", &tmp[1]);
			tmp = _strcpy(tmp, buf);
			printf("\n===== print bug ================\n");
			simple_print_buffer(buf, _strlen(buf) + 1);
			printf("\n===== print tmp ================\n");
			simple_print_buffer(tmp, _strlen(tmp) + 1);
			
			numTokens = 0;
			token = strtok(buf, delim);
			while (token)
				token = strtok(NULL, delim), numTokens++;

			printf("number of tokens : %d\n", numTokens);

			//argv = (char **) _calloc(numTokens + 1, sizeof(char *));
			argv = (char **) malloc((numTokens + 1) * sizeof(char *));
			if (argv == NULL)
				exit(1);				
			numTokens = 0;
			token = strtok(tmp, delim);
			while(token)
			{
				printf("%s", token);
				argv[numTokens] = _calloc((_strlen(token) + 1), sizeof(char));
				argv[numTokens] = _strcpy(argv[numTokens], token);
				numTokens++;
				token = strtok(NULL, delim);
			}
			argv[numTokens] = NULL;

			printf(".\n");
			printf(".\n");
			printf(".\n");
			printf(".\n");

			printf("number of data save inside argv : %d\n", numTokens);
			i = numTokens;
			for (; i >= 0; i--)
			{
				printf ("argv[%d] : %s\n",i ,(argv[i] == NULL) ? "(nil)" : argv[i]);
			}
			//printf ("argv[0] : %s\n", (argv[0] == NULL) ? "(nil)" : argv[0]);
			//printf ("argv[1] : %s\n", (argv[1] == NULL) ? "(nil)" : argv[1]);
			//printf ("argv[2] : %s\n", (argv[2] == NULL) ? "(nil)" : argv[2]);
			//free(token);
			//free(buf);

			if (argv[0] != NULL)
			{
				pid = fork();
				if (pid == 0)
				{
					if (execve(argv[0], argv, NULL) == -1)
					{
						perror("Error:");
					}
					//free(buf);
				}
				else
				{
					wait(&pid);
				}
			//	
			}
			delete_memory(argv, numTokens + 1);
			//free(argv);
			free(tmp);
			//free(buf);
		}
		//free(tmp);
	} while (status);

	

	return (0);
}
