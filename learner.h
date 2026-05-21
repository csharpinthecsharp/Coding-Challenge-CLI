#ifndef LEARNER_HPP
#define LEARNER_HPP
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <term.h>
#include <dirent.h>

#define RED "\033[31m"
#define WHITE "\033[0m"
#define PROFILE_LINES 2

enum ref_profile {
    CHAPTER,
    LEVEL,
};

typedef struct s_cli {
    char* curr_line;
    char  buffer;
    char *reply;
    bool  ex_mode;
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
    t_lines* line;
} t_profile;

/* DATA */
int init_data_profile(t_profile **prf);
int init_data_lines(t_lines **line);
void free_data(t_profile *prf);
void reload_data(t_profile *prf);
/* Check if its the first time this user login */
bool do_profile_exist(void);
/* Create profile.data and store value inside t_profile */
void create_profile(t_profile **prf);
/* Fill profile.data */
void fill_profile(t_profile **prf, t_lines **line);
/* terminal.c */
int cli_loop(t_profile **prf);

/* main.c */
/*commands*/
int command_dispatcher( const char* cmd, t_cli **cli );

void t_setup();
void t_unsetup();
void t_clear_back();
int t_limit_inp(int count, int c);
void t_move_cursor(int r, int c);
void t_exit(t_profile *prf);
int t_limit_to_enter(int count, int c);


bool check_current_level(t_lines *l);

#endif