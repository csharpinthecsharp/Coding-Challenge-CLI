#include "learner.h"

char* input_user(void)
{
    char buf;
    char input[64];
    size_t len = 0;
    while (read(STDIN_FILENO, &buf, 1) == 1)
    {
        if (buf == '\n' || len >= sizeof(input) - 1)
            break;
        input[len++] = buf;        
    }
    input[len] = '\0';
    return (strdup(input));
}

void get_line(t_cli *cli)
{
    system("clear");
    fprintf(stdout, "$> ");
    fflush(stdout);
    cli->curr_line = input_user();
}