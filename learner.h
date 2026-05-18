#ifndef LEARNER_HPP
#define LEARNER_HPP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define SEPARATOR ':'

enum ref_profile {
    IS_LOGGED,
    CURRENT_LEVEL
};

typedef struct s_cli {
    char* curr_line;
    char  buffer;
} t_cli;

typedef struct s_lines  {
    int   ref;
    char* key;
    char* string_value;
    char  char_value;
    int   int_value;
    size_t content_size;
} t_lines;

typedef struct s_profile {
    t_lines* lines;
    size_t  nb_lines;
    int     fd;
    t_cli* cli;
} t_profile;

/* DATA */
void init_data(t_profile **prf);
void free_data(t_profile *prf);
/* Check if its the first time this user login */
bool do_profile_exist(void);
/* Create profile.data and store value inside t_profile */
void create_profile(t_profile *prf);

/* terminal.c */
void get_line(t_cli *cli);

#endif