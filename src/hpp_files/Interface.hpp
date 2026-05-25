#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Profile.hpp"
#include <term.h>

class Interface {
    private:
        bool _run;
        bool _in_exo;
        int _cursor[2];
    public:
        Interface();
        ~Interface();

        bool isRunning();
        void loopExercice( Profile& profile );
        void commandDispatcher( const std::string& cmd, Profile& profile );
        void clearTerminal();
        void moveTerminalCursor( int n1, int n2 );
};

#endif