/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Snake
*/

#include "../include/Snake.hpp"

namespace Arcade
{
    Snake::Snake()
        : _isDead(false), _Score(0)
    {
        Loadmap();
        generateApple();
        _lastUpdateTime = std::clock();
        _updateInterval = 100;
    }

    Snake::~Snake()
    {
    }

    void Snake::Loadmap()
    {
        std::ifstream file("assets/maps/map.txt");

        if (file.is_open()) {
            std::string line;
            int y = 0;
            while (std::getline(file, line)) {
                std::vector<cell_t> row;
                for (int x = 0; x < line.length(); x++) {
                    cell_t mapCell;
                    mapCell.pos_x = x;
                    mapCell.pos_y = y;
                    if (line[x] == '#') {
                        mapCell.path = "assets/pictures/SNAKE/obstacle.png";
                        mapCell.color.c = FOND_RED;
                        mapCell.text = "#";
                        _ObstaclePos.push_back(std::make_pair(mapCell.pos_x, mapCell.pos_y));
                    } else if (line[x] == 'S' && line[x - 1] != 'S') {
                        mapCell.path = "assets/pictures/SNAKE/Graphics/head_left.png";
                        mapCell.text = "S";
                        mapCell.color.c = FOND_YELLOW;
                        _SnakePos.push_back(std::make_pair(mapCell.pos_x, mapCell.pos_y));
                    } else if (line[x] == 'S' && line[x - 1] == 'S' && line[x + 1] == 'S') {
                        mapCell.path = "assets/pictures/SNAKE/Graphics/body_horizontal.png";
                        mapCell.text = "S";
                        mapCell.color.c = FOND_GREEN;
                        _SnakePos.push_back(std::make_pair(mapCell.pos_x, mapCell.pos_y));
                    } else if (line[x] == 'S' && line[x - 1] == 'S' && line[x + 1] != 'S') {
                        mapCell.path = "assets/pictures/SNAKE/Graphics/tail_right.png";
                        mapCell.text = "S";
                        mapCell.color.c = FOND_GREEN;
                        _SnakePos.push_back(std::make_pair(mapCell.pos_x, mapCell.pos_y));
                    } else {
                        mapCell.color.c = WHITE;
                    }
                    row.push_back(mapCell);
                }
                _map.push_back(row);
                y++;
            }
            file.close();
        } else {
            std::cerr << "Je n'ai pas réussi à l'ouvrir" << std::endl;
        }
    }

    std::vector<std::vector<cell_t>> Snake::getMap()
    {
        return _map;
    }

    void Snake::generateApple()
    {
        if (!_ApplePos.empty()) {
            check_apple();
            return;
        }
        int pos_y;
        int pos_x;
        int temp = 0;
        while (1) {
            pos_y = std::rand() % _map.size();
            pos_x = std::rand() % _map[pos_y].size();

            if (_map[pos_y][pos_x].text != "#" && _map[pos_y][pos_x].text != "S") {
                _ApplePos.push_back(std::make_pair(pos_x, pos_y));
                _map[pos_y][pos_x].path = "assets/pictures/SNAKE/Graphics/apple.png";
                _map[pos_y][pos_x].color.c = FOND_MAGENTA;
                break;
            }
        }
    }

    bool Snake::gameOver()
    {
        if (check_wall() == true)
            return true;
        return false;
    }

    void Snake::execEvent(events_t event)
    {
        if (event != -1 && event != L && event != G) {
            if (event == LEFT && _last_event == RIGHT)
                return;
            if (event == RIGHT && _last_event == LEFT)
                return;
            if (event == UP && _last_event == DOWN)
                return;
            if (event == DOWN && _last_event == UP)
                return;
            if (event == R)
                reset();
            if (event != P && event != UP && event != DOWN && event != RIGHT && event != LEFT)
                return;
            _last_event = event;
        }
        return;
    }

    std::size_t Snake::getScore()
    {
        return _Score;
    }

    void Snake::reset()
    {
        _last_event = NOTHING;
        _isDead = false;
        _Score = 0;
        _last_Score = 0;
        _SnakePos.clear();
        _ObstaclePos.clear();
        _ApplePos.clear();
        _map.clear();
        Loadmap();
    }

    void Snake::move_left()
    {
        for (int y = 0; y < _map.size(); y++) {
            for (int x = 0; x < _map[y].size(); x++) {
                if (_map[y][x].text == "S") {
                    _map[y][x].text = " ";
                    _map[y][x].color.c = WHITE;
                    _map[y][x].path = "";
                }
            }
        }
        _SnakePos.insert(_SnakePos.begin(), std::make_pair(_SnakePos.at(0).first - 1, _SnakePos.at(0).second));
        if (_Score == _last_Score)
            _SnakePos.pop_back();
        int temp = 0;
        for (const auto &pos : _SnakePos) {
            if (temp != 0) {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_GREEN;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/body_horizontal.png";
            } else {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_YELLOW;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/head_left.png";
            }
            temp++;
        }
        return;
    }

    void Snake::move_right()
    {
        for (int y = 0; y < _map.size(); y++) {
            for (int x = 0; x < _map[y].size(); x++) {
                if (_map[y][x].text == "S") {
                    _map[y][x].text = " ";
                    _map[y][x].color.c = WHITE;
                    _map[y][x].path = "";
                }
            }
        }
        _SnakePos.insert(_SnakePos.begin(), std::make_pair(_SnakePos.at(0).first + 1, _SnakePos.at(0).second));
        if (_Score == _last_Score)
            _SnakePos.pop_back();
        int temp = 0;
        for (const auto &pos : _SnakePos) {
            if (temp != 0) {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_GREEN;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/body_horizontal.png";
            } else {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_YELLOW;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/head_right.png";
            }
            temp++;
        }
        return;
    }

    void Snake::move_up()
    {
        for (int y = 0; y < _map.size(); y++) {
            for (int x = 0; x < _map[y].size(); x++) {
                if (_map[y][x].text == "S") {
                    _map[y][x].text = " ";
                    _map[y][x].color.c = WHITE;
                    _map[y][x].path = "";
                }
            }
        }
        _SnakePos.insert(_SnakePos.begin(), std::make_pair(_SnakePos.at(0).first, _SnakePos.at(0).second - 1));
        if (_Score == _last_Score)
            _SnakePos.pop_back();
        int temp = 0;
        for (const auto &pos : _SnakePos) {
            if (temp != 0) {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_GREEN;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/body_horizontal.png";
            } else {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_YELLOW;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/head_up.png";
            }
            temp++;
        }
    }

    void Snake::move_down()
    {
        for (int y = 0; y < _map.size(); y++) {
            for (int x = 0; x < _map[y].size(); x++) {
                if (_map[y][x].text == "S") {
                    _map[y][x].text = " ";
                    _map[y][x].color.c = WHITE;
                    _map[y][x].path = "";
                }
            }
        }
        _SnakePos.insert(_SnakePos.begin(), std::make_pair(_SnakePos.at(0).first, _SnakePos.at(0).second + 1));
        if (_Score == _last_Score)
            _SnakePos.pop_back();
        int temp = 0;
        for (const auto &pos : _SnakePos) {
            if (temp != 0) {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_GREEN;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/body_horizontal.png";
            } else {
                _map[pos.second][pos.first].text = "S";
                _map[pos.second][pos.first].color.c = FOND_YELLOW;
                _map[pos.second][pos.first].path = "assets/pictures/SNAKE/Graphics/head_down.png";
            }
            temp++;
        }
        return;
    }

    bool Snake::check_wall()
    {
        for (auto &pos : _ObstaclePos) {
            if (_SnakePos.at(0).first == pos.first && _SnakePos.at(0).second == pos.second) {
                _isDead = true;
            }
        }
        int i = 0;
        for (auto &pos : _SnakePos) {
            if (_SnakePos.at(0).first == pos.first && _SnakePos.at(0).second == pos.second) {
                i++;
                if (i > 1) {
                    _isDead = true;
                }
            }
        }
        return _isDead;
    }

    void Snake::check_apple()
    {
        for (auto &pos : _ApplePos) {
            if (_SnakePos.at(0).first == pos.first && _SnakePos.at(0).second == pos.second) {
                _ApplePos.pop_back();
                _Score += 10;
            }
        }
    }

    void Snake::update()
    {
        if (_Score > 100 && _Score < 200)
            _updateInterval = 50;
        if (_Score >= 200)
            _updateInterval = 20;
        std::clock_t currentTime = std::clock();
        double timeElapsed = (currentTime - _lastUpdateTime) / (double)CLOCKS_PER_SEC * 1000;
        if (timeElapsed >= _updateInterval) {
             _last_Score = _Score;
            generateApple();
            if (_last_event == UP)
                move_up();
            if (_last_event == DOWN)
                move_down();
            if (_last_event == LEFT)
                move_left();
            if (_last_event == RIGHT)
                move_right();
            _lastUpdateTime = currentTime;
        }
    }

    std::string Snake::getBackground()
    {
        return "assets/pictures/SNAKE/Background_snake.png";
    }
}

extern "C" Arcade::IGame *createGame()
{
    return new Arcade::Snake();
}
