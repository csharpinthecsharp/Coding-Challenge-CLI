#include "../learner.h"

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
    fill_profile(prf, &(*prf)->line);
}

/* Fill profile.data */
void fill_profile(t_profile **prf, t_lines **line)
{
    size_t key_size = 0;
    (*line)[CHAPTER].key = strdup("CHAPTER");
    key_size = strlen((*line)[CHAPTER].key);
    write((*prf)->fd, (*line)[CHAPTER].key, key_size);
    write((*prf)->fd, ":", 1);
    write((*prf)->fd, &(*line)[CHAPTER].char_value, 1);
    write((*prf)->fd, "\n", 1);
    (*line)[CHAPTER].content_size = key_size + 3;

    key_size = 0;
    (*line)[LEVEL].key = strdup("LEVEL");
    key_size = strlen((*line)[LEVEL].key);
    write((*prf)->fd, (*line)[LEVEL].key, key_size);
    write((*prf)->fd, ":", 1);
    write((*prf)->fd, &(*line)[LEVEL].char_value, 1);
    (*line)[LEVEL].content_size = key_size + 2;
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

int init_data_lines(t_lines **line)
{
    *line = malloc(sizeof(t_lines) * (PROFILE_LINES + 1));
    if (!*line)
    {
        perror("malloc");
        return (-1);
    }

    for (size_t i = 0; i < (PROFILE_LINES + 1); i++)
    {
        (*line)[i].string_value = NULL;
        (*line)[i].int_value = 0;
        (*line)[i].char_value = (*line)[i].int_value + '0';
        (*line)[i].content_size = 0;
        (*line)[i].key = NULL;
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
        if (prf->cli->reply)
            free(prf->cli->reply);
        free(prf->cli);
    }

    if (prf->line)
    {
        for (size_t i = 0; i < (PROFILE_LINES + 1); i++)
        {
            free(prf->line[i].key);
            free(prf->line[i].string_value);
        }
        free(prf->line);
    }

    free(prf);
}
