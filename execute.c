#include "header.h"

/**
 * execute - execute
 * @argv: double pointer
 * Return: none
 */
int execute(char **argv)
{
	pid_t pid;
	int status;

	if (argv[0] != NULL)
	{
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
	}

	return (1);
}
