/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** OpenGame
*/

#ifndef OPENGAME_HPP_
#define OPENGAME_HPP_
#include "../interfaces/IGame.hpp"

namespace Arcade {

    class OpenGame {
        public:
            OpenGame(const std::string &GameName);
            ~OpenGame();
            const std::unique_ptr<IGame> &getGame();

        protected:
        private:
            std::shared_ptr<void> handle;
            std::unique_ptr<IGame> ptr;
    };
}

#endif /* !OPENGAME_HPP_ */
