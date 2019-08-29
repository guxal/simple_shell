#include "header.h"
/**
 * built_cd - change directory.
 * @args: arguments
 * @return Always returns 1, to continue executing.
 */
int built_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

/**
   @brief Builtin command: print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int built_help(char **args)
{
  int i;
  printf("Stephen Brennan's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");
  printf("Use the man command for information on other programs.\n");
  return (1);
}

/**
   @brief Builtin command: exit.
   @param args List of args.  Not examined.
   @return Always returns 0, to terminate execution.
 */
int built_exit(char **args)
{
  exit(1);
}

int built_env(char **args)
{
    char **ptr;

    ptr = environ;
    
    while (*ptr)
    {
        printf("%s\n", *ptr);
        *ptr++;
    }
    return (1);
}