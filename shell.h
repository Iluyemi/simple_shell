#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int process(char **cmd);
char** parse(char* input)
#endif
