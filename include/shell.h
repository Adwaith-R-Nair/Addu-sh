#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHELL_NAME "addu-sh"
#define MAX_INPUT   4096

// shell.c
void    run_shell(void);
char    *read_input(void);
void    print_prompt(void);

#endif