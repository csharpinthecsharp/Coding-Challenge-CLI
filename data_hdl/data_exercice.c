#include "../learner.h"

enum LEVEL_FLAGS {
    EXCP_FILES,
    ALLOWED_FUNC,
    SUBJECT,
    EXEMPLE,
    HINT,
    EXCP_RESULT
};

char* get_chapter_data(int chapter)
{
    char path[15] = "data/chapter_";
    path[13] = chapter + '0';
    path[14] = '\0';
    DIR* dir = opendir(path);
    if (!dir)
        return (NULL);
    closedir(dir);
    return (strdup(path));
}

bool get_level_data(int level, int chapter)
{
    char path[28] = "data/chapter_ /level_ .data";
    path[13] = chapter + '0';
    path[21] = level + '0';
    return (access(path, R_OK) != -1);
}

bool check_current_level(t_lines *l)
{
    char *chapter_dir = get_chapter_data(l[CHAPTER].int_value);
    if (!chapter_dir)
        return (false);
    if (!get_level_data(l[LEVEL].int_value, l[CHAPTER].int_value))
    {
        free(chapter_dir);
        return (false);
    }
    free(chapter_dir);
    return (true);  
}
