#include "hpp_files/Interface.hpp"

int main(int ac, char *av[])
{
    (void)av;
    if (ac != 1)
    {
        std::cout << "Error: ./learn" << std::endl;
        return (1);
    }
    Profile profile;
    // GET DATA/PROFILE.DT VALUE OR CREATE ONE
    profile.retrieveProfileData();
    profile.loadChapters();

    Interface interface;
    interface.moveTerminalCursor(0,0);
    while (interface.isRunning())
        interface.loopExercice(profile);
    return (0);
}