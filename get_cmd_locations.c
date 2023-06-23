#include "shell.h"
#define DELIM ":"

/**
 * location - returns full path of a command
 * @cmd: the command
 *
 * Return: pointer to the full path
 */

char *location(const char *cmd)
{
	char *path, *token, *full_path, *path_env;
	int len;

	path_env = getenv("PATH");
	if (!path_env)
	{
		return (NULL);
	}
	path = strdup(path_env);

	token = strtok(path, DELIM);

	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(sizeof(char) * len);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, F_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, DELIM);
	}
	free(path);
	return (NULL);
}
