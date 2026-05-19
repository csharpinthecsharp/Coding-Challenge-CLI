#include "learner.h"

/* Check if its the first time this user login */
bool do_profile_exist(void)
{
    return (access("data/profile.data", R_OK) != -1);
}

/* Create profile.data and store value inside t_profile */
void create_profile(t_profile **prf)
{
    (*prf)->fd = creat("data/profile.data", 00700);
    if ((*prf)->fd == -1)
    {
        perror("creat");
        exit(1);
    }
    fill_profile(prf, &(*prf)->lines);
}

/* Fill profile.data */
void fill_profile(t_profile **prf, t_lines **lines)
{
    size_t key_size = 0;
    (*lines)[CHAPTER].key = strdup("CHAPTER");
    key_size = strlen((*lines)[CHAPTER].key);
    write((*prf)->fd, (*lines)[CHAPTER].key, key_size);
    write((*prf)->fd, ":", 1);
    write((*prf)->fd, &(*lines)[CHAPTER].char_value, 1);
    write((*prf)->fd, "\n", 1);
    (*lines)[CHAPTER].content_size = key_size + 3;

    key_size = 0;
    (*lines)[LEVEL].key = strdup("LEVEL");
    key_size = strlen((*lines)[LEVEL].key);
    write((*prf)->fd, (*lines)[LEVEL].key, key_size);
    write((*prf)->fd, ":", 1);
    write((*prf)->fd, &(*lines)[LEVEL].char_value, 1);
    (*lines)[LEVEL].content_size = key_size + 2;
}


int init_data_profile(t_profile **prf)
{
    *prf = malloc(sizeof(t_profile));
    if (!*prf)
    {
        perror("malloc");
        return (-1);
    }

    (*prf)->cli = malloc(sizeof(t_cli));
    if (!(*prf)->cli)
    {
        perror("malloc");
        free(*prf);
        *prf = NULL;
        return (-1);
    }
    (*prf)->fd = -1;
    (*prf)->cli->buffer = 0;
    (*prf)->cli->curr_line = NULL;
    (*prf)->cli->reply = NULL;
    return (0);
}

int init_data_lines(t_lines **lines)
{
    *lines = malloc(sizeof(t_lines) * (PROFILE_LINES + 1));
    if (!*lines)
    {
        perror("malloc");
        return (-1);
    }

    for (size_t i = 0; i < (PROFILE_LINES + 1); i++)
    {
        (*lines)[i].string_value = NULL;
        (*lines)[i].int_value = 0;
        (*lines)[i].char_value = (*lines)[i].int_value + '0';
        (*lines)[i].content_size = 0;
        (*lines)[i].key = NULL;
    }
    return (0);
}

void free_data(t_profile *prf)
{

    if (!prf)
        return;

    if (prf->fd >= 0)
        close(prf->fd);

    if (prf->cli)
    {
        if (prf->cli->curr_line)
            free (prf->cli->curr_line);
        free(prf->cli);
    }

    if (prf->lines)
    {
        for (size_t i = 0; i < (PROFILE_LINES + 1); i++)
        {
            free(prf->lines[i].key);
            free(prf->lines[i].string_value);
        }
        free(prf->lines);
    }

    free(prf);
}
