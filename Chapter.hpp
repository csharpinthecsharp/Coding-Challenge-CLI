#ifndef CHAPTER_HPP
#define CHAPTER_HPP 

#include "Level.hpp"

class Chapter {
    private:
        int _chapter;
        Level* _levels;
    public:
        Chapter( int chapter );
        ~Chapter();
};
#endif