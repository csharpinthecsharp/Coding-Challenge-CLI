#include "learner.h"

void print_home(t_data *data)
{
    system("clear");
    fprintf(stdout, "Welcome back, %s!\n", data->name);
    fprintf(stdout, "You were at level %s, would you like to continue there? (Y/N)\n", data->level);
}

char* input_user(void)
{
    char buf;
    char input[64];
    size_t len = 0;
    while (read(STDIN_FILENO, &buf, 1) == 1)
    {
        if (buf == '\n' || len >= sizeof(input) - 1)
            break;
        input[len++] = buf;        
    }
    input[len] = '\0';
    return (strdup(input));
}

void get_name(t_data *data)
{
    (void)data;
    system("clear");
    fprintf(stdout, "Welcome!\n");
    fprintf(stdout, "Please tell me your name before starting: ");
    fflush(stdout);
    data->name = input_user();

    fprintf(stdout, "Oh!! Hello %s, at what level would you want to start?\n", data->name);
    fflush(stdout);
}

void get_level(t_data *data)
{
    while (data->level == 0)
    {
        fprintf(stdout, "Select from 1 to 10: ");
        fflush(stdout);

        data->level = input_user();
    }
}