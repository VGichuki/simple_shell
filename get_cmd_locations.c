#include "shell.h"

/**
 * location - returns full path of a command
 * @cmd: the command
 *
 * Return: pointer to the full path
 */

char *location(const char *cmd)
{
	char *path, *token, *full_path;
	char delim = ":";
	int len;

	path = getenv("PATH");
	if (!path)
	{
		return (NULL);
	}

	token = strtok(path, delim);

	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(full_path);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		token = strtok(NULL, delim);
	}
	return (NULL);
}
