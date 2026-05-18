#include "learner.h"

int main(int ac, char* av[])
{
    (void)av;
    if (ac != 1) {
        fprintf(stderr, "Error: no arguments expected.\n");
        return (1);
    }
    
    t_profile *prf = NULL;
    init_data(&prf);
    if (do_profile_exist())
    {
        get_line(prf->cli);  
    }
    else
    {
        create_profile(prf);
    }
    free_data(prf);
    return (0);
}