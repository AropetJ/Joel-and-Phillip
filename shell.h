#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>

int _putchar(char c);
int handleCommand(char *cmd);
char **_strtok(char *command, size_t *count);
void handle_signal(int signal);
int runprog(char *path);

#endif
