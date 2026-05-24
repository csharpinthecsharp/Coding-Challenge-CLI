#ifndef PROFILE_HPP
#define PROFILE_HPP

#include "Chapter.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Profile {
    private:
        unsigned int _level;
        unsigned int _chapter;

        Chapter* chapters;
    public:
        Profile();
        ~Profile();

        void setLevel( unsigned int n );
        void setChapter( unsigned int n);
        unsigned int getLevel() const;
        unsigned int getChapter() const;

        void retrieveProfileData();
        void loadChapters();
};

#endif