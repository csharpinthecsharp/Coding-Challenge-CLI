#include "../hpp_files/Interface.hpp"

Interface::Interface() : 
_run(true), _in_exo(false) {
}

Interface::~Interface() {

}

bool Interface::isRunning() {
    return (this->_run);
}

void Interface::loopExercice( Profile& profile ) {
    (void)profile;
    if (!_in_exo)
        std::cout << "Commands: exit, continue, select" << std::endl;
    else
        std::cout << "Commands: exit, grade" << std::endl;
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof())
        exit(1);
    commandDispatcher(line, profile);
}

void Interface::commandDispatcher( const std::string& cmd, Profile& profile )
{
    if (cmd == "exit")
        _run = false;
    else if (cmd == "continue")
    {
        if (_in_exo)
            return ;
        std::cout << 
            profile.getLevelsObjects(profile.getLevel(), profile.getChapter())
                << std::endl;
        _in_exo = true;
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

