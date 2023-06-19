#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024

/*Global environment*/
extern char **environ

/*function declarations*/
int exec(char **av);
int bettyStyle(int a, int b);
int _putchar(char c);
char *location(const char *cmd);


#endif
