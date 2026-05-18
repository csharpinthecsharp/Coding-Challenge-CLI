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
#define PROFILE_LINES 2

enum ref_profile {
    CHAPTER,
    LEVEL,
};

typedef struct s_cli {
    char* curr_line;
    char  buffer;
} t_cli;

typedef struct s_lines  {
    char* key;
    char* string_value;
    char  char_value;
    int   int_value;
    size_t content_size;
} t_lines;

typedef struct s_profile {
    int     fd;
    t_cli* cli;
    t_lines* lines;
} t_profile;

/* DATA */
int init_data_profile(t_profile **prf);
int init_data_lines(t_lines **lines);
void free_data(t_profile *prf);
/* Check if its the first time this user login */
bool do_profile_exist(void);
/* Create profile.data and store value inside t_profile */
void create_profile(t_profile **prf);
/* Fill profile.data */
void fill_profile(t_profile **prf, t_lines **lines);
/* terminal.c */
void get_line(t_cli *cli);

#endif