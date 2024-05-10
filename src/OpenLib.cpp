/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** OpenLib
*/

#include "include/OpenLib.hpp"

namespace Arcade
{
    OpenLib::OpenLib(const std::string &libName)
    {
        auto temp = dlopen(libName.c_str(), RTLD_LAZY);

        if (!temp)
            std::cerr << dlerror() << std::endl;

        handle = std::shared_ptr<void>(temp, [](void *pat) { dlclose(pat); });

        auto _libs = (IGraphical * (*)()) dlsym(handle.get(), "createGraphical");

        ptr.reset(_libs());
    }

    OpenLib::~OpenLib()
    {
    }

    const std::unique_ptr<IGraphical> &OpenLib::getLib()
    {
        return ptr;
    }
}
