#include "learner.h"
#include <readline/history.h>


int cli_loop(t_profile **prf)
{
    system("clear");
    while (1)
    {
        (*prf)->cli->curr_line = readline("$> ");
        if ((*prf)->cli->curr_line)
            add_history((*prf)->cli->curr_line);
        if (command_dispatcher((*prf)->cli->curr_line) == 1)
            return (1);
    }
    return (0);
}