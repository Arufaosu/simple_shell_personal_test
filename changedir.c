#include "shell.h"
/**
 * change_dir - changes directory using chdir
 * @args: double pointer to arg
 * Return: 1
 */
int change_dir(char **args)
{
	char prev_dir[1024] = "";
	char *path = args[1];
	char cwd[1024];

	    if (path == NULL)
	    {
		    path = getenv("HOME");
		    if (path == NULL)
		    {
			    printf("HOME environment variable not set.\n");
			    return 1;
		    }
	    }
	    else if (strcmp(path, "-") == 0)
	    {
		    if (prev_dir[0] == '\0')
		    {
			    printf("Previous directory not available.\n");
			    return (1);
		    }
		    path = prev_dir;
	    }
	    if (getcwd(cwd, sizeof(cwd)) == NULL)
	    {
		    perror("getcwd");
		    return (1);
	    }
	    strcpy(prev_dir, cwd);

	    if (chdir(path) != 0)
	    {
		    printf("Error: Directory not found.\n");
		    return (1);
	    }
	    if (getcwd(cwd, sizeof(cwd)) != NULL)
		    setenv("PWD", cwd, 1);

	    else
	    {
		    perror("getcwd");
		    return (1);
	    }


	return (1);
}

