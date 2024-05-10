/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_
#include <iostream>
#include "../interfaces/tools.hpp"
#include <cstring>

namespace Arcade {
    class Menu {
        public:
            Menu();
            ~Menu();
            text_t DisplayTitle();
            text_t GetPlayerName();
            text_t showPlayTitle();
            void create_score_file(std::string filename);
            text_t show_arrow();
            text_t show_L();
            text_t show_G();
            text_t show_Escape();
            text_t show_Interact();
            text_t show_instructions();
            text_t show_R();

        protected:
        private:
    };
}

#endif /* !MENU_HPP_ */
