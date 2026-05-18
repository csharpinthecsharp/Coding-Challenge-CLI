#include "learner.h"

void sigint_handler(int sig)
{
    (void)sig;
    ctrl_c = 1;
    write(1, "\n", 1);
}

void ban_ctrl_c(void)
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    struct sigaction sa = {0};
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0; 
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

void restore_term(void)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ECHOCTL | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

volatile sig_atomic_t ctrl_c = 0;

int main(int ac, char* av[])
{
    (void)av;
    if (ac != 1) {
        fprintf(stderr, "Error: no arguments expected.\n");
        return (1);
    }

    ban_ctrl_c();

    t_profile *prf = NULL;
    if (init_data_profile(&prf) == -1)
    {
        free_data(prf);
        return (1);
    }
    if (init_data_lines(&prf->lines) == -1)
    {
        free_data(prf);
        return (1);
    }
    if (!do_profile_exist())
        create_profile(&prf);
    if (cli_loop(&prf->cli) == -1)
    {
        fprintf(stdout, "\nExiting Learn_C CLI..\n");
        free_data(prf);
        return (1);
    }
    free_data(prf);
    return (0);
}