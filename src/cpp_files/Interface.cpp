#include "../hpp_files/Interface.hpp"

Interface::Interface() : _run(true) {
}

Interface::~Interface() {

}

bool Interface::isRunning() {
    return (this->_run);
}

void Interface::loopExercice( Profile& profile ) {
    (void)profile;
    std::cout << "Commands: exit, continue, select" << std::endl;
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
        std::cout << 
            profile.getLevelsObjects(profile.getLevel(), profile.getChapter())
                << std::endl;
    }
}

