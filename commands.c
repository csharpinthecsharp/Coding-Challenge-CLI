#include "learner.h"
#include <stdio.h>
#include <string.h>

int command_dispatcher( const char* cmd, t_cli **cli)
{
    if (!cmd)
        return (1);
    else if (!strlen(cmd))
        return (0);
    else if (strcmp(cmd, "exit") == 0)
        return (1);
    else if (strcmp(cmd, "help") == 0)
        (*cli)->reply = strdup("cmds list: [help, exit]\n");
    else
        (*cli)->reply = strdup("no command found, type help for commands list\n");
    return (0);
}