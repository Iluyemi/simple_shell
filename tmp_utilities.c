#include "shell.h"

void ctrl_C(int signum)
{
	if (signum == SIGINT)
		print("\n ($) ", STDIN_FILENO);
}

char *_getline(void)
{
	int bufsize = READ_BUF;
	int no_read, position;

	char *buffer = malloc(bufsize * sizeof(char));
	char c;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		no_read = read(STDIN_FILENO, &c, 1);
		if (c == EOF || !no_read)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				print("\n", STDIN_FILENO);
				return (NULL);
			}
		}
		else if (c == '\n' || !no_read)
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize)
		{
			bufsize += READ_BUF;
			buffer = _realloc(buffer, READ_BUF, bufsize);
			if (!buffer)
			{
				perror("Failed to re-allocate a space in memory");
				exit(EXIT_FAILURE);
			}
		}
}
}
