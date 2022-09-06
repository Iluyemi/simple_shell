#include "shell.h"

int process(char **cmd)
{
	pid_t i;
	int status;

	if (!cmd)
	{
		perror("failed");
	}
	/*child process for exec*/
	i = fork();
	/*debugging wahala*/
	if (i == -1)
	{
		perror("Fail");
		return (1);
	}
	/*child process*/
	else if (i == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			printf("%s\n", cmd[0]);
			perror("Issue execuing");
			exit(-1);
		}
	}
	else
	/*parent process waiting*/
		wait(&status);
	return (0);
}

/**
 * main - shell function
 * @void: nothing
 * Return: value
 */
int main(void)
{
	size_t n = 0;
	char *line = NULL;
	char **tokens;
	int output;

	while (1)
	{
		/*prompt*/
		write(1, "($) ", 5);
		/*takes in command*/
		getline(&line, &n, stdin);
		/*tokenization of string*/
		tokens = parse(line);
		/*execution of tokens*/
		output = process(tokens);
	}
	return (0);
}
