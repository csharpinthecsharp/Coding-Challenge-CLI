#ifndef LEVEL_HPP
#define LEVEL_HPP 

#include "Profile.hpp"

#define N_ELEMENTS 6

enum {
    TITLE,
    SUBJECTS,
    ALL_FNC,
    FILE_T_IN,
    PROTO,
    HINTS,
    EXAMPL,
};

class Level {
    private:
        int _level;
        std::string _description[N_ELEMENTS];
    public:
        Level( int level );
        ~Level();
};
#endif