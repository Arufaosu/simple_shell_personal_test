#include "shell.h"
/**
 * shell_exit - exits shell
 * @args: double pointer to arg
 * Return: 0
 */
int shell_exit(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		exit(status);
	}
	exit(EXIT_SUCCESS);
}

