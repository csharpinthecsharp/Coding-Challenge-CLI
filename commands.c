#include "learner.h"
#include <stdio.h>
#include <string.h>

int command_dispatcher( const char* cmd )
{
    if (!cmd)
        return (1);
    else if (!strlen(cmd))
        return (0);
    else if (strcmp(cmd, "exit") == 0)
        return (1);
    else if (strcmp(cmd, "help") == 0)
        fprintf(stdout, "cmds list: [help, exit]\n");
    else
        fprintf(stdout, "%s: command don't exist, type: help\n", cmd);
    return (0);
}