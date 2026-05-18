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
    if (init_data_lines(&prf->lines) == -1)
    {
        free_data(prf);
        return (1);
    }
    if (do_profile_exist())
    {
        get_line(prf->cli);  
    }
    else
    {
        create_profile(&prf);
    }
    free_data(prf);
    return (0);
}