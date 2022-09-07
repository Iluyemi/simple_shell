#include "shell.h"

int main (int argc __attribute__((unused)), char **argv)
{
	char *line;
	(void) argv;

	signal(SIGINT, ctrl_C);
	
	while (1)
	{
		print(" ($) ", STDOUT_FILENO);
		line = _getline();
		/**printf("Inputed line: %s", line);*/
	}
}
