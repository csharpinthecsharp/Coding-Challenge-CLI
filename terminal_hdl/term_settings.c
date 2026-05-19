#include "../learner.h"

int t_limit_inp(int count, int c)
{
    (void)count;
    if (rl_end >= 45)
        return (0);
    return rl_insert_text((char[]){c, 0});
}

void t_setup()
{
    setupterm(NULL, fileno(stdout), NULL);
    putp(tigetstr("smcup"));
    for (size_t i = 32; i < 127; i++)        
        rl_bind_key(i, t_limit_inp);
}

void t_unsetup()
{
    putp(tigetstr("rmcup"));
}

void t_clear_back()
{
    putp(tigetstr("clear"));
    putp(tigetstr("home"));
}

void t_move_cursor(int r, int c)
{
    putp(tparm(tigetstr("cup"), r-1, c-1));
}

void t_exit(t_profile *prf)
{
    t_unsetup();
    fprintf(stdout, "Exiting Learn_C CLI..\n");
    free_data(prf);
}