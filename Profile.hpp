#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Profile {
    private:
        unsigned int _level;
        unsigned int _chapter;
    public:
        Profile();
        ~Profile();

        void setLevel( unsigned int n );
        void setChapter( unsigned int n);
        unsigned int getLevel();
        unsigned int getChapter();

        void retrieveProfileData();
};

#endif