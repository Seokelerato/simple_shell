/**
 * main - program that is used to satisfy betty.
 * Return: 0 (Success)
 */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXIMUM_ARGS 10
#define MAXIMUM_LINE_LEN 80

int main(void)
{
	char currentLine[MAXIMUM_LINE_LEN];

	char *arguments[MAXIMUM_ARGS];

	while (1)
	{
		printf("please enter a command: ");
		fgets(currentLine, MAXIMUM_LINE_LEN, stdin);

		int i = 0;

		arguments[i] = strtok(currentLine, "\n");
		while (arguments[i] != NULL)
		{
			i++;
			arguments[i] = strtok(NULL, "\n");
		}
		arguments[i] = NULL;

		if (strcmp(arguments[0], "cd") == 0)
		{
			chdir(arguments[1]);
			continue;
		}
		else if (strcmp(arguments[0], "exit") == 0)
		{
			exit(0);
		}

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("could not fork.");
		}
		else if (pid == 0)
		{
			execvp(arguments[0], args);
			perror("exec could not create");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

