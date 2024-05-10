/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** main
*/
#include "Parser.hpp"
#include "include/OpenLib.hpp"
#include "Core/Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Arcade::Parser pars;
    std::string lib_to_open = av[1];
    try {
        pars.check_lib(lib_to_open);
        Arcade::Core core(av[1]);
        core.main_loop();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }

    return 0;
}
