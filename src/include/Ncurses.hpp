/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../interfaces/IGraphical.hpp"
#include <ncurses.h>

namespace Arcade {
    class Ncurses : public IGraphical {
        public:
            Ncurses();
            ~Ncurses();
            void display() override;
            void myClear() override;
            events_t catchEvent() override;
            void drawText(const text_t &) override;
            void drawMap(const std::vector<std::vector<cell_t>> &map, int xMapMax, int yMapMax) override;
            void drawBackgroundGame(const std::string &, int xMin, int yMin, int xMax, int yMax) override;

        protected:
        private:
            int _xMin;
            int _yMin;
            int _xMax;
            int _yMax;
    };
}
#endif /* !NCURSES_HPP_ */