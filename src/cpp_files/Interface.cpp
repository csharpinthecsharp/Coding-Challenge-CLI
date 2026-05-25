#include "../hpp_files/Interface.hpp"

Interface::Interface() : 
_run(true), _in_exo(false) {
    _cursor[0] = 0, _cursor[1] = 0;
    setupterm(NULL, fileno(stdout), NULL);
    putp(tigetstr("smcup"));
}

Interface::~Interface() {
    putp(tigetstr("rmcup"));
}

bool Interface::isRunning() {
    return (this->_run);
}

void Interface::clearTerminal() {
    putp(tigetstr("clear"));
    putp(tigetstr("home"));
}

void Interface::moveTerminalCursor( int n1, int n2 ) {
    putp(tparm(tigetstr("cup"), n1-1, n2-1)); 
}

void Interface::loopExercice( Profile& profile ) {
    this->moveTerminalCursor(_cursor[0], _cursor[1]);
    if (!_in_exo)
        std::cout << "Commands list: [exit, continue, select]" << std::endl;
    else
        std::cout << "Commands list: [exit, grade]" << std::endl;
    std::cout << "$> ";
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof())
        exit(1);
    this->clearTerminal();
    if (_in_exo && line != "exit")
        commandDispatcher("continue", profile);
    else
        commandDispatcher(line, profile);
}

void Interface::commandDispatcher( const std::string& cmd, Profile& profile )
{
    if (cmd == "exit")
        _run = false;
    else if (cmd == "continue")
    {
        std::cout << 
            profile.getLevelsObjects(profile.getLevel(), profile.getChapter())
                << std::endl;
        _in_exo = true;
        _cursor[0] = 23, _cursor[1] = 0;
        return ;
    }
    else if (cmd == "select")
    {
        if (_in_exo)
            return ;
    }
    else if (cmd == "grade")
    {
        if (!_in_exo)
            return ;
    }
}

