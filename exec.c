#include "shell.h"

/**
 * print_env - prints the current envirenment
 *
 * Return: void
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * exec - executes a command
 * @argv: name of the program
 * @av: the commands
 * Return: 0 on success
 */

int exec(char *argv, char **av)
{
	char *cmd_path, *cmd;
	pid_t pid;
	int status;

	if (!av[0])
		return (0);
	cmd = av[0];
	if (strcmp(cmd, "exit") == 0)
	{
		free_tokens(av);
		exit(0);
	}
	else if (strcmp(cmd, "env") == 0)
		print_env();
	else
	{
		cmd_path = location(cmd);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv, cmd);
			return (0);
		}
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			if (execve(cmd_path, av, NULL) == -1)
			{
				perror("Error: ");
				exit(0);
			}
		}
		else if (waitpid(pid, &status, 0) == -1)
			perror("Error: ");
		free(cmd_path);
	}
	return (0);
}
