/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Nibbler
*/

#include "../include/Nibbler.hpp"

namespace Arcade
{
    Nibbler::Nibbler()
        : _isDead(false), _Score(0)
    {
        Loadmap();
        _lastUpdateTime = std::clock();
        _updateInterval = 100;
    }

    Nibbler::~Nibbler()
    {
    }

    void Nibbler::Loadmap()
    {
        std::ifstream file("assets/maps/map_bis.txt");

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
                    } else if (line[x] == 'A') {
                        mapCell.path = "assets/pictures/SNAKE/Graphics/apple.png";
                        mapCell.text = "A";
                        mapCell.color.c = FOND_MAGENTA;
                        _ApplePos.push_back(std::make_pair(mapCell.pos_x, mapCell.pos_y));
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

    std::vector<std::vector<cell_t>> Nibbler::getMap()
    {
        return _map;
    }

    void Nibbler::generateApple()
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

    bool Nibbler::gameOver()
    {

        if (check_colision() == true)
            return true;
        return false;
    }

    void Nibbler::execEvent(events_t event)
    {
        if (event != -1 && event != L) {
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

    std::size_t Nibbler::getScore()
    {
        return _Score;
    }

    void Nibbler::reset()
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

    void Nibbler::move_left()
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
        if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text == "#") {
            if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text == "#" && _map[_SnakePos.at(0).second - 1][_SnakePos.at(0).first].text != "#") {
                _last_event = UP;
                move_up();
                return;
            } else if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text != "#" && _map[_SnakePos.at(0).second - 1][_SnakePos.at(0).first].text == "#") {
                _last_event = DOWN;
                move_down();
                return;
            } else if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text != "#" && _map[_SnakePos.at(0).second - 1][_SnakePos.at(0).first].text != "#") {
                _last_event = P;
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
            } else
                _isDead = true;
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
    }

    void Nibbler::move_right()
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
        if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text == "#") {
            if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text == "#" && _map[_SnakePos.at(0).second - 1][_SnakePos.at(0).first].text != "#") {
                _last_event = UP;
                move_up();
                return;
            } else if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text != "#" && _map[_SnakePos.at(0).second - 1][_SnakePos.at(0).first].text == "#") {
                _last_event = DOWN;
                move_down();
                return;
            } else if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text != "#" && _map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text != "#") {
                _last_event = P;
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
            } else
                _isDead = true;
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
    }

    void Nibbler::move_up()
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
        if (_map[_SnakePos.at(0).second - 1][_SnakePos.at(0).first].text == "#") {
            if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text == "#" && _map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text != "#") {
                _last_event = RIGHT;
                move_right();
                return;
            } else if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text != "#" && _map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text == "#") {
                _last_event = LEFT;
                move_left();
                return;
            } else if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text != "#" && _map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text != "#") {
                _last_event = P;
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
                return;
            } else
                _isDead = true;
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

    void Nibbler::move_down()
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
        if (_map[_SnakePos.at(0).second + 1][_SnakePos.at(0).first].text == "#") {
            if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text == "#" && _map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text != "#") {
                _last_event = RIGHT;
                move_right();
                return;
            } else if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text != "#" && _map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text == "#") {
                _last_event = LEFT;
                move_left();
                return;
            } else if (_map[_SnakePos.at(0).second][_SnakePos.at(0).first - 1].text != "#" && _map[_SnakePos.at(0).second][_SnakePos.at(0).first + 1].text != "#") {
                _last_event = P;
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
            } else
                _isDead = true;
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
    }

    bool Nibbler::check_colision()
    {
        int i = 0;
        for (auto &pos : _SnakePos) {
            if (_SnakePos.at(0).first == pos.first && _SnakePos.at(0).second == pos.second) {
                i++;
                if (i > 1) {
                    _isDead = true;
                }
            }
        }
        if (_ApplePos.empty() == true)
            reset();
        return _isDead;
    }

    void Nibbler::check_apple()
    {
        int x = 0;
        int y = 0;
        int temp = 0;

        for (auto &pos : _ApplePos) {
            if (_SnakePos.at(0).first == pos.first && _SnakePos.at(0).second == pos.second) {
                x = pos.first;
                y = pos.second;
                _map[pos.second][pos.first].text = " ";
                _map[pos.second][pos.first].path = " ";
                _Score += 10;
                temp++;
            }
        }
        if (temp == 0)
            return;
        std::pair<int, int> _AteApple = std::make_pair(x, y);
        std::vector<std::pair<int, int>>::iterator itr = _ApplePos.end();
        for (auto it = _ApplePos.begin(); it != _ApplePos.end(); ++it) {
            if (*it == _AteApple) {
                itr = it;
                break;
            }
        }
        if (itr != _ApplePos.cend())
            _ApplePos.erase(itr);
    }

    void Nibbler::update()
    {
        if (_Score > 100 && _Score < 200)
            _updateInterval = 50;
        if (_Score >= 200)
            _updateInterval = 20;
        std::clock_t currentTime = std::clock();
        double timeElapsed = (currentTime - _lastUpdateTime) / (double)CLOCKS_PER_SEC * 1000;
        if (timeElapsed >= _updateInterval) {
            _last_Score = _Score;
            check_apple();
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

    std::string Nibbler::getBackground()
    {
        return "assets/pictures/SNAKE/Background_snake.png";
    }
}

extern "C" Arcade::IGame *createGame()
{
    return new Arcade::Nibbler();
}
