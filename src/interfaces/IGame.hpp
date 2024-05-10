/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
#include "tools.hpp"
#include <vector>
#include <stdbool.h>
#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <fstream>
#include <unordered_map>

namespace Arcade
{
    class IGame {
        public:
            virtual ~IGame() = default;

            virtual void execEvent(events_t) = 0;
            virtual std::vector<std::vector<cell_t>> getMap() = 0;
            virtual bool gameOver() = 0;
            virtual std::size_t getScore() = 0;
            virtual void reset() = 0;
            virtual void update() = 0;
            virtual std::string getBackground() = 0;

        private:
    };
}
extern "C" Arcade::IGame* createGame();
#endif /* !IGAME_HPP_ */
