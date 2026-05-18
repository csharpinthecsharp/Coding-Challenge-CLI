#include "learner.h"

/* Check if its the first time this user login */
bool do_profile_exist(void)
{
    return (access("data/profile.data", R_OK) != -1);
}

/* Create profile.data and store value inside t_profile */
void create_profile(t_profile *prf)
{
    prf->fd = creat("data/profile.data", 00700);
    if (prf->fd == -1)
    {
        perror("creat");
        exit(1);
    }
}

void init_data(t_profile **prf)
{
    *prf = malloc(sizeof(t_profile) * 1);
    if (!*prf)
    {
        perror("malloc");
        exit(1);
    }

    (*prf)->cli = malloc(sizeof(t_cli) * 1);
    if (!(*prf)->cli)
    {
        perror("malloc");
        free(*prf);
        *prf = NULL;
        exit(1);
    }

    (*prf)->nb_lines = 0;
    (*prf)->fd = -1;
    (*prf)->cli->buffer = 0;
    (*prf)->cli->curr_line = NULL;
}

void free_data(t_profile *prf)
{
    if (!prf)
        return;

    if (prf->fd >= 0)
        close(prf->fd);
    if (prf->cli->curr_line)
        free (prf->cli->curr_line);
    if (prf->cli)
        free(prf->cli);

    free(prf);
    prf = NULL;
}
