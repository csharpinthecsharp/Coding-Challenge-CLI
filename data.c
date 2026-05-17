#include "learner.h"

static int read_data(ssize_t *r,
     int fd,
      char *line,
        size_t line_s,
            char **val)
{
    char buff;
    size_t len = 0;
    while ((*r = read(fd, &buff, 1)) == 1)
    {
        if (buff == '\n' || len >= line_s - 1)
            break;
        line[len++] = buff;
    }
    if (*r <= 0 && len == 0)
        return (2);
    line[len] = '\0';

    char *split = strchr(line, ':');
    if (!split)
        return (1);
    *split = '\0';

    *val = split + 1;
    if (!val)
        return (1);
    return (0);
}

static void read_data_offset(ssize_t *r,
        int fd,
            char *line,
                off_t *pos,
                    off_t *pos_start,
                        char *key)
{
    while (1)
    {
        char buf;
        size_t len = 0;
        while ((*r = read(fd, &buf, 1)) == 1)
        {
            if (buf == '\n' || len >= sizeof(line) - 1)
                break;
            line[len++] = buf;
        }
        line[len] = '\0';

        if (r <= 0 && len == 0)
            break;
        if (strncmp(line, key, strlen(key)) == 0 && line[strlen(key)] == ':')
        {
            *pos = *pos_start + strlen(key) + 1;
            break;
        }
        *pos_start += len + 1;
    }
}

unsigned int retrieve_int_data(const char *key)
{
    int res = -1;
    int fd = open("data/profile.data",  O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: profile.data not found!\n");
        exit(1);
    }
    char line[64];
    ssize_t r;
    while (1)
    {
        char *val;
        int rd;
        rd = read_data(&r, fd, line, sizeof(line), &val);
        if (rd == 2)
            break;
        if (rd == 1)
            continue;
        if (strcmp(line, key) == 0)
        {
            res = atoi(val);
            break;
        }
    }
    close (fd);
    if (res <= 0)
    {
        fprintf(stderr, "Error: '%s' not found in profile.data\n", key);
        exit(1);
    }
    return (res);
}

char* retrieve_str_data(const char *key)
{
    char* res = NULL;
    int fd = open("data/profile.data",  O_RDONLY);
    if (fd == -1) 
    {
        fprintf(stderr, "Error: profile.data not found!\n");
        exit(1);
    }
    char line[64];
    ssize_t r;
    while (1)
    {
        char *val;
        int rd;
        rd = read_data(&r, fd, line, sizeof(line), &val);
        if (rd == 2)
            break;
        if (rd == 1)
            continue;
            
        if (strcmp(line, key) == 0)
        { 
            res = strdup(val);
            if (!res)
            {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(1);
            }
            break;
        }
    }
    close (fd);
    if (!res)
    {
        fprintf(stderr, "Error: '%s' not found in profile.data\n", key);
        exit(1);
    }
    return (res);
}

void write_int_data(char n, char *key) 
{
    int fd = open("data/profile.data", O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "Error: profile.data not found\n");
        exit(1);
    }
    char line[64];
    off_t pos = 0;
    off_t pos_start = 0;
    ssize_t r = 0;
    read_data_offset(&r, fd, line, &pos, &pos_start, key);
    if (lseek(fd, pos, SEEK_SET) == -1)
    {
        fprintf(stderr, "Error: failed to moove cursor (lseek)\n");
        exit(1);
    }
    if (write(fd, &n, 1) == -1)
    {
        fprintf(stderr, "Error: failed to write into fd\n");
        exit(1);
    }
    close(fd);
}

void write_str_data(char *str, char *key)
{
    int fd = open("data/profile.data", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    char storage[1024] = "";
    char line[256];
    ssize_t r;
    size_t storage_len;

    while (1)
    {
        size_t line_len = 0;
        char buf;
        while ((r = read(fd, &buf, 1)) > 0)
        {
            if (buf == '\n')
                break;
            if (line_len < sizeof(line) - 1)
                line[line_len++] = buf;
        }
        line[line_len] = '\0';
        if (line_len == 0 && r <= 0)
            break;
        if (strncmp(line, key, strlen(key)) == 0 && line[strlen(key)] == ':')
        {
            strcat(storage, key);
            strcat(storage, ":");
            strcat(storage, str);
            strcat(storage, "\n");
        }
        else
        {
            strcat(storage, line);
            strcat(storage, "\n");
        }
        if (r <= 0)
            break;
    }
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        fprintf(stderr, "Error: failed to moove cursor (lseek)\n");
        exit(1);
    }
    storage_len = strlen(storage);
    if (write(fd, storage, storage_len) == -1)
    {
        fprintf(stderr, "Error: failed to write into fd\n");
        exit(1);
    }

    close(fd);
}

void write_data(t_data *data)
{
    write_int_data('2', "logged");
    write_str_data(data->name, "name");
    write_str_data(data->level, "level");
}

unsigned int is_logged(void) 
{
    int res = retrieve_int_data("logged");
    if (res == 2)
        return (1);
    return (0);
}

void log_in(t_data *data)
{
    get_name(data);
    get_level(data);
    write_data(data);
}

void init_data_at_zero(t_data *data)
{
    data->level = NULL;
    data->logged = 0;
    data->name = NULL;
}

void init_data(t_data *data)
{
    data->level = retrieve_str_data("level");
    data->name = retrieve_str_data("name");
}

void free_data(t_data *data)
{
    if (data->name)
        free(data->name);
}