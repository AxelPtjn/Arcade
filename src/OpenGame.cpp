/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** OpenGame
*/

#include "include/OpenGame.hpp"

namespace Arcade
{
    OpenGame::OpenGame(const std::string &GameName)
    {
        auto temp = dlopen(GameName.c_str(), RTLD_LAZY);

        if (!temp)
            std::cerr << dlerror() << std::endl;

        handle = std::shared_ptr<void>(temp, [](void *pat) { dlclose(pat); });

        auto _libs = (IGame * (*)()) dlsym(handle.get(), "createGame");

        ptr.reset(_libs());
    }

    OpenGame::~OpenGame()
    {
    }

    const std::unique_ptr<IGame> &OpenGame::getGame()
    {
        return ptr;
    }

}