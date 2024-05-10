/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Parser
*/
#include "Parser.hpp"


namespace Arcade {
    void Parser::check_lib(std::string lib_name)
    {
        if (!std::filesystem::exists(lib_name))
            throw Arcade::Error("The file specified : [ "+ lib_name +" ] doesn't exist.");
    }
}
