/**
 * main - program that is used to satisfy betty.
 * Return: 0 (Success)
 */

#include "shell.h"

int main(int ac, char **argv)
{
	char *linePointer;

	size_t n = 0;
	ssize_t noOfChars_read;


	(void)ac;

	(void) argv;

	while (1)
	{

		printf("shell $ ");
		noOfChars_read = getline(&linePointer, &n, stdin);

		if (noOfChars_read == -1)
		{
			printf("Leaving the shell..");
			return (-1);
		}

		printf("%s\n", linePointer);

		free(linePointer);
	}
	return (0);
}
