#include "shell.h"

void    print_prompt(void)
{
    write(STDOUT_FILENO, SHELL_NAME " $ ", 10);
}

char    *read_input(void)
{
    char    *buffer;

    buffer = malloc(MAX_INPUT * sizeof(char));
    if (!buffer)
    {
        fprintf(stderr, "addu-sh: memory allocation failed\n");
        exit(1);
    }
    if (fgets(buffer, MAX_INPUT, stdin) == NULL)
    {
        free(buffer);
        return (NULL);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return (buffer);
}

void    run_shell(void)
{
    char    *input;

    while (1)
    {
        print_prompt();
        input = read_input();
        if (input == NULL)
        {
            write(STDOUT_FILENO, "\n", 1);
            break ;
        }
        if (input[0] == '\0')
        {
            free(input);
            continue ;
        }
        printf("You typed: %s\n", input);
        free(input);
    }
}