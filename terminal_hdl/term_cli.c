#include "../learner.h"

void print_cli_prompt(t_profile **prf)
{
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
    , (*prf)->line[LEVEL].int_value, (*prf)->line[CHAPTER].int_value);
    printf("    ╭──────────────────────────────────────────────────╮\n");
    printf("                                                        \n");
    printf("    ╰──────────────────────────────────────────────────╯\n");
}

void print_cli_reply(t_profile **prf)
{
    t_move_cursor(21,7);
    if ((*prf)->cli->reply)
    {
        printf("%s", (*prf)->cli->reply);
        fflush(stdout);
    }
    t_move_cursor(18,7);
    fflush(stdout);
}

int cli_loop(t_profile **prf)
{
    t_setup();
    while (1)
    {
        t_clear_back();
        print_cli_prompt(prf);
        print_cli_reply(prf);
        (*prf)->cli->curr_line = readline("\033[1m>\033[0m ");

        if ((*prf)->cli->curr_line)
            add_history((*prf)->cli->curr_line);
        if (command_dispatcher((*prf)->cli->curr_line, &(*prf)->cli) == 1)
            return (1);
    }
    return (0);
}