/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-tekspice-axel.petitjean
** File description:
** Error
*/

#include "Error.hpp"

namespace Arcade
{
    Error::Error(const std::string &error)
    {
        _error = error;
    }

    const char* Error::what() const noexcept
    {
        return _error.c_str();
    }

}