#ifndef LEARNER_HPP
#define LEARNER_HPP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data {
    unsigned int logged;
    char* level;
    char* name;
} t_data;

/*data.c / main.c */
void free_data(t_data *data);

unsigned int is_logged(void);
void log_in(t_data *data);

void init_data(t_data *data);
void init_data_at_zero(t_data *data);

unsigned int retrieve_int_data(const char *key);
char* retrieve_str_data(const char *key);

void write_data(t_data *data);
void write_int_data(char n, char *key);
void write_str_data(char *str, char *key);

/* terminal.c */
void print_home(t_data *data);
void get_name(t_data *data);
void get_level(t_data *data);

#endif