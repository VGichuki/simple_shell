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
	char *cmd_path, *cmd;
	static char *working_dir;
	pid_t pid;
	int status;

	cmd = av[0];
	if (strcmp(cmd, "pwd") == 0)
	{
		printf("%s\n", getcwd(working_dir, 1024));
		free(working_dir);
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "env") == 0)
		print_env();
	else
	{
		cmd_path = location(cmd);
		if (!cmd_path)
			return (-1);
		pid = fork();
		if (pid == -1)
			perror("Error");

		else if (pid == 0)
		{
			execve(cmd_path, av, NULL);
			perror("Error: ");
			return (-1);
		}
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: ");
			return (-1);
		}
		free(cmd_path);
	}
	return (0);
}
