#include "shell.h"
#define DELIM " \n\t\r"

void free_tokens(char **args);

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
		/*free(args)*/
		return (NULL);
	}
	token = strtok(str, DELIM);
	while (token)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			free_tokens(args);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_tokens - frees the array of tokens
 * @args: array to be freed
 * Return: void
 */

void free_tokens(char **args)
{
	int i;

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
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
			free(buf);
			exit(0);
		}
		arg = tokenize(buf);
		if (arg == NULL)
		{
			continue;
		}
		exec(argv[0], arg);

		free_tokens(arg);
		free(buf);
		buf = NULL;
		len = 0;
	}
	free_tokens(arg);
	return (0);
	argc++;
	argv[i] = "j";
}
