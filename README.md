# #cisfun$ shell
#cisfun$ is a simple shell implementation of the Bash Shell in the C Programming language. The #cisfun$ shell can be compiled and runned from the command line. It contains the most basic features and functions found in the various shell programs.

## Usage

You must include in your function the "header.h" header:

```c
#include "header.h"
```

The directory contents should be compiled with the following command:

```c
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
The #cisfun$ Shell runs in interactive mode, doing:
```sh
#./hsh
```
Getting the promt and typing commands:

```sh
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./shs
```
```sh
#cisfun$ ls
AUTHORS    calloc.c	  delete_memory.c  getenv.c  main.c		 read_line.c  split_line.c  strcmp.c  strlen.c
README.md  create_node.c  execute.c	      header.h  man_1_simple_shell  shs	            strcat.c	          strcpy.c
#cisfun$
```


And #cisfun$ run a command in non-interactive mode, doing:
```sh
$ echo "echo 'what the shell?'" | ./hsh
'what the shell?'
$
```
## Example




## Built-ins
The built-ins supported for this shell are

cd - Change directory
exit - Exit the shell
help - Display help for a builtin command



## Files and functions

| File | Description |
| :-:   | :-: |
| AUTHORS | Contributors list to this project |
| _calloc.c | Our calloc dynamic memory function |
|delete_memory.c | Focus on free memory tasks |
|execute.c|hell builtins and command execution|
|header.h|Header file with prototypes of functions|
|main.c|The main function from #cisfun$ Shell|
|man_1_simple_shell|#cisfun$ Shell man page|
|_realloc.c | Our realloc dynamic memory function |
|read_line.c| Read a line from the user input |
|split_line.c | Line to tokens to generate argv vector |
|strcmp.c| Our strcmp string function |
|strcpy.c| Our strcpy string function |
|strlen.c| Our strlen string function |
### Authors
Jonathan Cardenas Pabon
email: 892@holbertonschool.com
Rolando Quiroz
email: 906@holbertonschool.com

## License
[MIT](https://choosealicense.com/licenses/mit/)