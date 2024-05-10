/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Nibbler
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../interfaces/IGame.hpp"
#include <ctime>
#include <map>

#include <sstream>
#include <sys/stat.h>
#include <set>
namespace Arcade {
    class Nibbler : public IGame {
        public:
            Nibbler();
            ~Nibbler();
            void execEvent(events_t) override;
            std::vector<std::vector<cell_t>> getMap() override;
            bool gameOver() override;
            std::size_t getScore() override;
            void reset() override;
            void update() override;
            std::string getBackground() override;
            void Loadmap();
            std::vector<std::vector<cell_t>> draw_apple();
            void move_left();
            void move_right();
            void move_up();
            void move_down();
            void generateApple();
            bool check_colision();
            void check_apple();

        protected:
        private:
            std::vector<std::vector<cell_t>> _map;
            int _Score;
            int _last_Score;
            std::vector<std::pair<int, int>> _SnakePos;
            std::vector<std::pair<int, int>> _ObstaclePos;
            std::vector<std::pair<int, int>> _ApplePos;
            events_t _last_event;
            bool _isDead;
            std::clock_t _lastUpdateTime;
            double _updateInterval;

    };
}
#endif /* !SNAKE_HPP_ */
