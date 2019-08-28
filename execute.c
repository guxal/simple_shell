#include "header.h"
/**
 * launch - launch commands
 * @argv: arguments
 * Return: Success or Fail
 */
int launch(char **argv)
{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else if (pid < 0)
	{
		perror("#cisfun$ ");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		/* wait(NULL); */
	}
	
	return (1);
}
/**
 * execute - execute
 * @argv: double pointer
 * Return: none
 */
int execute(char **argv, path_t *path)
{
	int i;
	char *concat;
	struct stat st;

	if (argv[0] == NULL)
	{
		return (1);
	}

	if (argv[0][0] == '/' || argv[0][0] == '.')
	{
		return (launch(argv));
	}

	//for (i = 0; i < lsh_num_builtins(); i++)
	//{
    //	if (_strcmp(argv[0], builtin_str[i]) == 0)
	//	{
    //	  return (*builtin_func[i])(argv);
    //	}
  	//}

	while (path)
	{
		concat = malloc((_strlen(path->str) + 1) * sizeof(char));
		_strcpy(concat, path->str);
		

		concat = _strcat(concat, argv[0]);
		
		//printf("concat : %s\n", concat);
		
		//printf("%s\n", path->str);
		if (stat(concat, &st) == 0)
        {
            //printf(" FOUND\n");
			free(argv[0]);
			argv[0] = malloc((_strlen(concat) + 1) * sizeof(char));
			argv[0] = _strcpy(argv[0], concat);
			return (launch(argv));
        }
        else
        {
            //printf(" NOT FOUND\n");
        }
		
		path = path->next;
	}
	free(concat);
	return (1);
}
