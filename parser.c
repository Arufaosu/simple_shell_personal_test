#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * parseinput - tokenizes input from user
 * @line: char pointer
 * @bufsize: buffer size
 *
 * Return: nothing
 */
#define MAX_ARGS 10

char *args[MAX_ARGS];

void parseinput(char *line) 
{
    int i = 0;
    char *token = strtok(line, ";\n");

    while (token != NULL && i < MAX_ARGS) 
    {
        parse_command(token);
        token = strtok(NULL, ";\n");
    }
}

void parse_command(char *command) 
{
    int i = 0;
    char *token = strtok(command, " \t\n");

    while (token != NULL && i < MAX_ARGS - 1) 
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }

    args[i] = NULL;
}

int main() 
{
    char input[100];

    printf("Simple Shell\n");

    while (1) 
    {
        printf("Enter command: ");
        if (fgets(input, sizeof(input), stdin) == NULL) 
	{
            break;
    	}

        parseinput(input);

        int i = 0;
        while (args[i] != NULL) 
	{
            printf("Argument %d: %s\n", i, args[i]);
            i++;
        }
    }

    return 0;
}

