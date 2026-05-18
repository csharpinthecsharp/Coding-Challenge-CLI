#include "learner.h"

int input_user(t_cli **cli)
{
    char buf;
    char input[1024];
    size_t len = 0;
    ssize_t r;

    while (1)
    {
        r = read(STDIN_FILENO, &buf, 1);
        if (ctrl_c)
        {
            ctrl_c = 0;
            return (1);
        }
        // CTRL D.
        if (buf == '\x04')
        {
            if (len == 0)
                return (-1);
            break;
        }
        if (r < 0)
        {
            if (errno == EINTR)
                continue;
            return (-1);
        }
        if (buf == '\n')
            break;
        if (len < sizeof(input) - 1)
            input[len++] = buf;
    }
    input[len] = '\0';
    free((*cli)->curr_line);
    (*cli)->curr_line = strdup(input);
    return (0);
}


int cli_loop(t_cli **cli)
{
    system("clear");
    int res;
    while (1)
    {
        fprintf(stdout, "$> ");
        fflush(stdout);
        res = input_user(cli);
        if (res == -1)
            return (-1);
    }
    return (0);
}