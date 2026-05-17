#include "learner.h"

int main(int ac, char* av[])
{
    (void)av;
    if (ac != 1) {
        fprintf(stderr, "Error: no arguments expected.\n");
        return (1);
    }
    
    t_data data;
    init_data_at_zero(&data);
    if (is_logged())
    {
        data.logged = 1;
        init_data(&data);
        print_home(&data);
    }
    else
    {
        log_in(&data);
    }
    free_data(&data);
    return (0);
}