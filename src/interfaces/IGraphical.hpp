/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** IGraphical
*/

#ifndef IGraphical_HPP_
#define IGraphical_HPP_
#include "tools.hpp"
#include <vector>
#include <dlfcn.h>
#include <memory>

namespace Arcade
{
    class IGraphical {
        public:
            virtual ~IGraphical() = default;
            virtual void display() = 0;
            virtual void myClear() = 0;
            virtual events_t catchEvent() = 0;
            virtual void drawText(const text_t &) = 0;
            virtual void drawMap(const std::vector<std::vector<cell_t>> &map, int xMapMax, int yMapMax) = 0;
            virtual void drawBackgroundGame(const std::string &, int xMin, int yMin, int xMax, int yMax) = 0;
    };
}
extern "C" Arcade::IGraphical* createGraphical();
#endif /* !IGRAPHICAL_HPP_ */