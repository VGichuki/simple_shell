#include "shell.h"
#define DELIM " \n\t\r"

/**
 * tokenize - divides string into tokens
 * @str: string to tokenize
 * Return: pointer
 */

char **tokenize(char *str)
{
	char *token, **args /*str_cpy*/;
	int i = 0;

	args = malloc(sizeof(char *) * 1024);
	if (!args)
	{
		free(args);
		return (NULL);
	}
	/*str_cpy = strdup(str);
	if (!str_cpy)
	{
		perror("Error");
		return (NULL);
	}*/
	token = strtok(str, DELIM);
	while (token)
	{
		args[i] = token;
		if (!args[i])
			return (NULL);
		token = strtok(NULL, DELIM);
		i++;
	}
	args[i] = NULL;
	return (args);
}


/**
 * prompt - prints the prompt
 *
 * Return: void
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *buf = NULL;
	int i;
	size_t len;
	ssize_t status;
	char **arg;

	while (1)
	{
		prompt();
		status = getline(&buf, &len, stdin);
		if (status == -1)
		{
			exit(1);
		}
		arg = tokenize(buf);
		if (arg == NULL)
		{
			free(buf);
			continue;
		}
		exec(arg);

		/*for (i = 0; arg[i] != NULL; i++)
		{
			free(arg[i]);
		}*/
		free(arg);
		/*free(buf);*/
		buf = NULL;
		len = 0;
	}
	return (0);
	argc++;
	argv[i] = "j";

}
