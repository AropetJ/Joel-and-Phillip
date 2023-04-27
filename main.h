#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

void handleCommand(char *cmd, char *prompter);
char **_strtok(char *command, size_t *count);
void runprog(char *path, char **args, char *prompter);

#endif
