#include "Profile.hpp"

int main(int ac, char *av[])
{
    (void)av;
    if (ac != 1)
    {
        std::cout << "Error: ./learn" << std::endl;
        return (1);
    }
    Profile profile;
}