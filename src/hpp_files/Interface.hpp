#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Profile.hpp"

class Interface {
    private:
        bool _run;
        bool _in_exo;
    public:
        Interface();
        ~Interface();

        bool isRunning();
        void loopExercice( Profile& profile );
        void commandDispatcher( const std::string& cmd, Profile& profile );
};

#endif