#include "learner.h"
#include <readline/history.h>

void exit_cli(t_profile *prf)
{
    // UNLOCK ALTERNATE TERMINAL SCROLLING | Clear Terminal
    fprintf(stdout, "\033[?1049l");
    system("clear");
    fprintf(stdout, "Exiting Learn_C CLI..\n");
    free_data(prf);
}

void print_prompt(t_profile **prf)
{
    printf("\033[?1049h"); // CREATE ALTERNATE TERMINAL TO LOCK MODE, PREVENT SCROLLING
    printf("\033[2J\033[H"); // CLEAR AND SET CURSOR
    printf(
    "\n    \033[33mWelcome to Coding Challenge!\033[0m\n "
    "\033[35m   ██████\033[0m╗ \033[35m██████\033[0m╗ \033[35m██████\033[0m╗ \033[35m██\033[0m╗\033[35m███\033[0m╗   \033[35m██\033[0m╗ \033[35m██████\033[0m╗ \n"
    "   \033[35m██\033[0m╔════╝\033[35m██\033[0m╔═══\033[35m██\033[0m╗\033[35m██\033[0m╔══\033[35m██\033[0m╗\033[35m██\033[0m║\033[35m████\033[0m╗  \033[35m██\033[0m║\033[35m██\033[0m╔════╝ \n"
    "   \033[35m██\033[0m║     \033[35m██\033[0m║   \033[35m██\033[0m║\033[35m██\033[0m║  \033[35m██\033[0m║\033[35m██\033[0m║\033[35m██\033[0m╔\033[35m██\033[0m╗ \033[35m██\033[0m║\033[35m██\033[0m║  \033[35m███\033[0m╗\n"
    "   \033[35m██\033[0m║     \033[35m██\033[0m║   \033[35m██\033[0m║\033[35m██\033[0m║  \033[35m██\033[0m║\033[35m██\033[0m║\033[35m██\033[0m║╚\033[35m██\033[0m╗\033[35m██\033[0m║\033[35m██\033[0m║   \033[35m██\033[0m║\n"
    "   ╚\033[35m██████\033[0m╗╚\033[35m██████\033[0m╔╝\033[35m██████\033[0m╔╝\033[35m██\033[0m║\033[35m██\033[0m║ ╚\033[35m████\033[0m║╚\033[35m██████\033[0m╔╝\n"
    "    ╚═════╝ ╚═════╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝\033[0m \n"
    "\n     \033[1m\033[33mCC is a CLI built for training C skills (beginner, intermediate)."
    "\n     You can start your journey by typing: help\033[0m\n\n\n"
    "   \033[1;35m●\033[0m Level: \033[1;35m%u\033[0m\n"
    "   \033[1;35m•●\033[0m Chapter: \033[1;35m%u\033[0m\n\n"
    , (*prf)->lines[LEVEL].int_value, (*prf)->lines[CHAPTER].int_value);
    printf("    ╭──────────────────────────────────────────────────╮\n");
    printf("                                                        \n");
    printf("    ╰──────────────────────────────────────────────────╯\n");
    // MOVE CURSOR OUTSIDE THE BOX
    printf("\033[21;7H");
    if ((*prf)->cli->reply)
    {
        printf("%s", (*prf)->cli->reply);
        fflush(stdout);
    }
    // MOVE CURSOR INSIDE THE BOX
    printf("\033[18;7H");
    fflush(stdout);
}

int cli_loop(t_profile **prf)
{
    system("clear");
    while (1)
    {
        print_prompt(prf);

        (*prf)->cli->curr_line = readline("\033[1m>\033[0m ");

        if ((*prf)->cli->curr_line)
            add_history((*prf)->cli->curr_line);
        if (command_dispatcher((*prf)->cli->curr_line, &(*prf)->cli) == 1)
            return (1);
    }
    return (0);
}