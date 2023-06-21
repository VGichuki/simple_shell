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
 * @av: the commands
 * Return: 0 on success
 */

int exec(char **av)
{
	char *cmd_path, cmd, *env = NULL;
	static char working_dir;
	int status;

	cmd = argv[0];
	if (strcmp(cmd, "pwd") == 0)
		printf("%s\n", getcwd(working_dir, 1024));
	else if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "env") == 0)
	{
		print_env();
	}
	else
	{
		cmd_path = location(cmd);
		if (!cmd_path)
			return (-1);
		status = fork();
		if (status == 0)
		{
			execve(cmd_path, av, env);
			perror("Error: ");
			exit(0);
		}
		else if (status == -1)
		{
			perror("Error: ");
		}
		else
		{
			wait(NULL);
		}
		free(cmd_path);
		return (0);
	}
	return (-1);
}
