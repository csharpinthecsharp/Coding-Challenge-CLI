#include "learner.h"

int main(int ac, char* av[])
{
    (void)av;
    if (ac != 1) {
        fprintf(stderr, "Error: no arguments expected.\n");
        return (1);
    }

    t_profile *prf = NULL;
    if (init_data_profile(&prf) == -1)
    {
        free_data(prf);
        return (1);
    }
    if (init_data_lines(&prf->line) == -1)
    {
        free_data(prf);
        return (1);
    }
    if (!check_current_level(prf->line))
        reload_data(prf); // ACTUALLY RELOAD ALL DATA
    if (!do_profile_exist())
        create_profile(&prf);
    if (cli_loop(&prf) == 1)
    {
        t_exit(prf);
        return (0);
    }
    free_data(prf);
    return (0);
}