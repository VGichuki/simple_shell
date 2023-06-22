#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFF_SIZE 1024

/*Global environment*/
extern char **environ;

/*Function declarations*/
int exec(char **av);
void print_env(void);
int bettyStyle(int a, int b);
int _putchar(char c);
char *location(const char *cmd);
char **tokenize(char *str);
void prompt(void);
int main(int argc, char **argv);


#endif
