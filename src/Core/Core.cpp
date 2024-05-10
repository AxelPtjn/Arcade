/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Core
*/

#include "Core.hpp"

namespace Arcade
{
    Core::Core(const std::string &libName)
        : _openLib(std::make_unique<OpenLib>(libName)), run(true), _playerName("Player_1"), _inGame(false)
    {
        _CurrentLibrary = libName;
        createLibVector();
        createLib_Game_Names_to_Draw();
    }

    Core::~Core()
    {
    }

    void Core::changeCurrentLibrary()
    {
        int pos = findLibIndex(_CurrentLibrary);
        pos += 1;
        if (pos > (_Libfiles.size() - 1))
            pos = 0;
        _CurrentLibrary = _Libfiles.at(pos);
        _openLib = nullptr;
        _openLib = std::make_unique<OpenLib>(_CurrentLibrary);
    }

    bool Core::check_graphical_lib(std::string str)
    {
        std::string comp[] = {
        "arcade_ndk++.so",
        "arcade_aalib.so",
        "arcade_libcaca.so",
        "arcade_allegro5.so",
        "arcade_xlib.so",
        "arcade_gtk+.so",
        "arcade_sfml.so",
        "arcade_irrlicht.so",
        "arcade_opengl.so",
        "arcade_vulkan.so",
        "arcade_qt5.so",
        "arcade_ncurses.so",
        "arcade_sdl2.so",
        };

        int n = sizeof(comp) / sizeof(*comp);

        bool exists = std::find(comp, comp + n, str) != comp + n;

        return exists;
    }

    bool Core::check_game_lib(std::string str)
    {
        std::string comp[] = {
        "arcade_snake.so",
        "arcade_nibbler.so",
        "arcade_pacman.so",
        "arcade_qix.so",
        "arcade_centipede.so",
        "arcade_solarfox.so",
        };

        int n = sizeof(comp) / sizeof(*comp);

        bool exists = std::find(comp, comp + n, str) != comp + n;

        return exists;
    }

    void Core::createLibVector()
    {
        std::string lib = "lib";
        std::string temp = "lib/";
        DIR *dir = opendir(lib.c_str());
        if (dir != nullptr) {
            struct dirent *dirent;
            while ((dirent = readdir(dir)) != nullptr) {
                if (std::string(dirent->d_name)[0] != '.' && check_graphical_lib(dirent->d_name)) {
                    _Libfiles.push_back(temp + dirent->d_name);
                }
                if (std::string(dirent->d_name)[0] != '.' && check_game_lib(dirent->d_name)) {
                    _Gamefiles.push_back(temp + dirent->d_name);
                }
            }
            closedir(dir);
        }
    }

    int Core::findLibIndex(std::string lib)
    {
        for (auto i = 0; i < _Libfiles.size(); i++) {
            if (_Libfiles[i] == lib)
                return i;
        }
        return -1;
    }

    int Core::findGameIndex(std::string game)
    {
        for (auto i = 0; i < _games.size(); i++) {
            if (_games[i] == game)
                return i;
        }
        return -1;
    }

    text_t Core::WritePlayerName_bis(events_t event, text_t playerName)
    {
        if (event == M && playerName.text.length() < 11)
            playerName.text += "M";
        else if (event == N && playerName.text.length() < 11)
            playerName.text += "N";
        else if (event == O && playerName.text.length() < 11)
            playerName.text += "O";
        else if (event == P && playerName.text.length() < 11)
            playerName.text += "P";
        else if (event == Q && playerName.text.length() < 11)
            playerName.text += "Q";
        else if (event == R && playerName.text.length() < 11)
            playerName.text += "R";
        else if (event == S && playerName.text.length() < 11)
            playerName.text += "S";
        else if (event == T && playerName.text.length() < 11)
            playerName.text += "T";
        else if (event == U && playerName.text.length() < 11)
            playerName.text += "U";
        else if (event == V && playerName.text.length() < 11)
            playerName.text += "V";
        else if (event == W && playerName.text.length() < 11)
            playerName.text += "W";
        else if (event == X && playerName.text.length() < 11)
            playerName.text += "X";
        else if (event == Y && playerName.text.length() < 11)
            playerName.text += "Y";
        else if (event == Z && playerName.text.length() < 11)
            playerName.text += "Z";
        else if (event == DEL && !playerName.text.empty())
            playerName.text.pop_back();
        return playerName;
    }

    text_t Core::WritePlayerName(events_t event, text_t playerName)
    {
        if (event == A && playerName.text.length() < 11) {
            playerName.text += "A";
        } else if (event == B && playerName.text.length() < 11)
            playerName.text += "B";
        else if (event == C && playerName.text.length() < 11)
            playerName.text += "C";
        else if (event == D && playerName.text.length() < 11)
            playerName.text += "D";
        else if (event == E && playerName.text.length() < 11)
            playerName.text += "E";
        else if (event == F && playerName.text.length() < 11)
            playerName.text += "F";
        else if (event == G && playerName.text.length() < 11)
            playerName.text += "G";
        else if (event == H && playerName.text.length() < 11)
            playerName.text += "H";
        else if (event == I && playerName.text.length() < 11)
            playerName.text += "I";
        else if (event == J && playerName.text.length() < 11)
            playerName.text += "J";
        else if (event == K && playerName.text.length() < 11)
            playerName.text += "K";
        else if (event == L && playerName.text.length() < 11)
            playerName.text += "L";
        else if (event == UP)
            _WriteMode = false;
        playerName = WritePlayerName_bis(event, playerName);
        return playerName;
    }

    void Core::putGameScore(std::string game, int pos_x)
    {
        std::ifstream gameFile("score_" + game + ".txt");
        std::vector<std::pair<std::string, int>> players;
        std::string line;
        while (std::getline(gameFile, line)) {
            if (line.empty()) {
                continue;
            }
            std::istringstream iss(line);
            std::string playerName;
            int score;
            if (iss >> playerName >> score) {
                players.push_back({playerName, score});
            }
        }

        for (size_t i = 0; i < players.size() && i < 3; i++) {
            _openLib->getLib()->drawText({players[i].first, pos_x - 8, static_cast<int>(19 + ((i + 1) * 2)), GREG, {255, 255, 255, 255, WHITE}, 30, false});
            _openLib->getLib()->drawText({std::to_string(players[i].second), pos_x + 8, static_cast<int>(19 + (i + 1) * 2), GREG, {255, 255, 255, 255, WHITE}, 30, false});
        }
        return;
    }

    void Core::putGameName()
    {
        std::string game1 = _Gamefiles.at(0);
        std::string game2 = _Gamefiles.at(1);

        size_t posSlash = game1.rfind('/');
        std::string gameName1 = game1.substr(posSlash + 1);
        size_t posArcade = gameName1.find("arcade_");
        if (posArcade != std::string::npos) {
            gameName1.erase(posArcade, 7);
        }
        size_t posDot = gameName1.find(".so");
        if (posDot != std::string::npos) {
            gameName1.erase(posDot);
        }

        posSlash = game2.rfind('/');
        std::string gameName2 = game2.substr(posSlash + 1);
        posArcade = gameName2.find("arcade_");
        if (posArcade != std::string::npos) {
            gameName2.erase(posArcade, 7);
        }
        posDot = gameName2.find(".so");
        if (posDot != std::string::npos) {
            gameName2.erase(posDot);
        }
        std::string back_game1 = gameName1;
        std::string back_game2 = gameName2;
        std::transform(gameName1.begin(), gameName1.end(), gameName1.begin(), ::toupper);
        std::transform(gameName2.begin(), gameName2.end(), gameName2.begin(), ::toupper);
        _openLib->getLib()->drawText({gameName1, 40, 17, GREG, {255, 255, 255, 255, WHITE}, 30, true});
        _openLib->getLib()->drawText({gameName2, 154, 17, GREG, {255, 255, 255, 255, WHITE}, 30, true});

        putGameScore(back_game1, 40);
        putGameScore(back_game2, 154);
    }

    void Core::drawMenu()
    {
        for (int i = 68; i != 136; i++) {
            _openLib->getLib()->drawText({"-", i, 10, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"-", i, 29, GREG, {255, 255, 255, 255, WHITE}, 60, false});
        }
        for (int i = 0; i != 18; i++) {
            int temp = i + 11;
            _openLib->getLib()->drawText({"|", 67, temp, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"|", 135, temp, GREG, {255, 255, 255, 255, WHITE}, 60, false});
        }
        for (int i = 30; i != 60; i++) {
            _openLib->getLib()->drawText({"-", i, 15, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"-", i, 15 + 15, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"-", i + 115, 15, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"-", i + 115, 15 + 15, GREG, {255, 255, 255, 255, WHITE}, 60, false});
        }
        for (int i = 0; i != 14; i++) {
            int temp = i + 16;
            _openLib->getLib()->drawText({"|", 29, temp, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"|", 60, temp, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"|", 144, temp, GREG, {255, 255, 255, 255, WHITE}, 60, false});
            _openLib->getLib()->drawText({"|", 175, temp, GREG, {255, 255, 255, 255, WHITE}, 60, false});
        }
        putGameName();
    }

    void Core::verif_score_exist()
    {
        for (int i = 0; i != _Gamefiles.size(); i++) {
            if (_Gamefiles.at(i) == "lib/arcade_snake.so")
                if (!std::ifstream("score_snake.txt"))
                    _Menu->create_score_file("score_snake.txt");
            if (_Gamefiles.at(i) == "lib/arcade_nibbler.so")
                if (!std::ifstream("score_nibbler.txt"))
                    _Menu->create_score_file("arcade_pacman.txt");
            if (_Gamefiles.at(i) == "lib/arcade_pacman.so")
                if (!std::ifstream("score_pacman.txt"))
                    _Menu->create_score_file("score_pacman.txt");
            if (_Gamefiles.at(i) == "lib/arcade_qix.so")
                if (!std::ifstream("score_qix.txt"))
                    _Menu->create_score_file("score_qix.txt");
            if (_Gamefiles.at(i) == "lib/arcade_centipede.so")
                if (!std::ifstream("score_centipede.txt"))
                    _Menu->create_score_file("score_centipede.txt");
            if (_Gamefiles.at(i) == "lib/arcade_solarfox.so")
                if (!std::ifstream("score_solarfox.txt"))
                    _Menu->create_score_file("score_solarfox.txt");
        }
    }

    void Core::createLib_Game_Names_to_Draw()
    {
        for (const auto &lib : _Libfiles) {
            std::string libName = lib.substr(11, lib.size() - 14);
            std::transform(libName.begin(), libName.end(), libName.begin(),
            ::toupper);
            _libraries.push_back(libName);
        }
        for (const auto &game : _Gamefiles) {
            std::string gameName = game.substr(11, game.size() - 14);
            std::transform(gameName.begin(), gameName.end(), gameName.begin(),
            ::toupper);
            _games.push_back(gameName);
        }
    }

    void Core::browse_in_menu(bool LibSelected, int selectLib, int selectGame)
    {
        if (LibSelected) {
            for (int i = 0; i < _libraries.size(); i++)
                _openLib->getLib()->drawText({_libraries[i], 74, 15 + i * 5, GREG, {255, 0, 0, 255, RED}, 30, selectLib == i});

            for (int i = 0; i < _games.size(); i++)
                _openLib->getLib()->drawText({_games[i], 115, 17 + i * 5, GREG, {255, 255, 255, 255, WHITE}, 30, false});

        } else {
            for (int i = 0; i < _libraries.size(); i++) {
                _openLib->getLib()->drawText({_libraries[i], 74, 15 + i * 5, GREG, {255, 255, 255, 255, WHITE}, 30, false});
            }
            for (int i = 0; i < _games.size(); i++) {
                _openLib->getLib()->drawText({_games[i], 115, 17 + i * 5, GREG, {255, 0, 0, 255, RED}, 30, selectGame == i});
            }
        }
    }

    bool Core::AGameSelected(int selectGame)
    {
        _selectedGame = _games[selectGame];
        std::transform(_selectedGame.begin(), _selectedGame.end(), _selectedGame.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        std::string gameLibraryPath = "lib/arcade_" + _selectedGame + ".so";

        _openGame = std::make_unique<OpenGame>(gameLibraryPath);
        _inGame = true;
        return _inGame;
    }

    void Core::ALibSelected(int selectLib, int numberLib)
    {
        if (selectLib < numberLib) {
            std::string selectedLibrary = _libraries[selectLib];
            std::transform(selectedLibrary.begin(), selectedLibrary.end(), selectedLibrary.begin(), [](unsigned char c) {
                return std::tolower(c);
            });
            std::string libName = "lib/arcade_" + selectedLibrary + ".so";
            if (_CurrentLibrary != libName) {
                _CurrentLibrary = libName;
                _openLib = nullptr;
                _openLib = std::make_unique<OpenLib>(_CurrentLibrary);
            }
        }
    }

    void Core::sort_score(std::vector<std::pair<std::string, int>> &scores)
    {
        std::sort(scores.begin(), scores.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
    }

    void Core::updateScore()
    {
        std::string file_name = "score_" + _selectedGame + ".txt";
        std::transform(file_name.begin(), file_name.end(), file_name.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        std::ifstream fichier_in(file_name);
        chmod(file_name.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        std::vector<std::pair<std::string, int>> scores;
        std::string ligne;
        std::string nom_jeu;
        while (getline(fichier_in, ligne)) {
            if (ligne.find(":") != std::string::npos) {
                nom_jeu = ligne.substr(0, ligne.size() - 1);
            } else {
                std::istringstream iss(ligne);
                std::string name;
                int score;
                iss >> name >> score;
                scores.push_back({name, score});
            }
        }
        bool playerFound = false;
        if (_playerName[0] != ' ')
            _playerName = ' ' + _playerName;
        for (auto &pair : scores) {
            if (" " + pair.first == _playerName) {
                playerFound = true;
                if (pair.second < _openGame->getGame()->getScore())
                    pair.second = _openGame->getGame()->getScore();
            }
        }
        if (!playerFound) {
            scores.push_back({_playerName, _openGame->getGame()->getScore()});
        }

        sort_score(scores);

        std::ofstream fichier_out(file_name);

        fichier_out << nom_jeu << ":\n";
        for (const auto &pair : scores) {
            fichier_out << pair.first << " " << pair.second << "\n";
        }
        chmod(file_name.c_str(), S_IRUSR | S_IRGRP | S_IROTH);
    }

    void Core::changeCurrentGame()
    {
        int pos = findGameIndex(_selectedGame);
        pos += 1;
        if (pos > (_games.size() - 1))
            pos = 0;
        _selectedGame = _games.at(pos);
        _openGame = nullptr;
        auto tmp = _selectedGame;
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        _openGame = std::make_unique<OpenGame>("lib/arcade_" + tmp + ".so");
    }

    void Core::draw_instructions()
    {
        text_t helper_l = _Menu->show_L();
        text_t helper_escape = _Menu->show_Escape();
        text_t helper_g = _Menu->show_G();
        text_t helper_arrow = _Menu->show_arrow();
        text_t helper_interact = _Menu->show_Interact();
        text_t helper_title = _Menu->show_instructions();
        text_t helper_reset = _Menu->show_R();

        _openLib->getLib()->drawText(helper_escape);
        _openLib->getLib()->drawText(helper_l);
        _openLib->getLib()->drawText(helper_arrow);
        _openLib->getLib()->drawText(helper_interact);
        _openLib->getLib()->drawText(helper_g);
        _openLib->getLib()->drawText(helper_title);
        _openLib->getLib()->drawText(helper_reset);
    }

    void Core::main_loop()
    {
        text_t title = _Menu->DisplayTitle();
        text_t playerName = _Menu->GetPlayerName();
        text_t player_texte_title = _Menu->showPlayTitle();

        int selectLib = 0;
        int selectGame = 0;
        bool LibSelected = false;
        _WriteMode = false;
        bool OldWriteMode = false;
        srand(time(NULL));

        verif_score_exist();
        const auto time = std::chrono::high_resolution_clock::now();
        auto LastUpdate = time;
        auto limit = std::chrono::milliseconds(50);
        while (run) {
            OldWriteMode = _WriteMode;
            if (std::chrono::high_resolution_clock::now() - LastUpdate > limit) {
                LastUpdate = std::chrono::high_resolution_clock::now();
                _openLib->getLib()->myClear();
                _openLib->getLib()->drawText(title);
                drawMenu();
                _openLib->getLib()->drawText(player_texte_title);
                _openLib->getLib()->drawText(playerName);
                draw_instructions();
                browse_in_menu(LibSelected, selectLib, selectGame);
                if (_inGame == true) {
                    _openLib->getLib()->myClear();
                    _openLib->getLib()->drawBackgroundGame(_openGame->getGame()->getBackground(), 45, 5, 135, 36);
                    _openGame->getGame()->update();
                    draw_instructions();
                    _openLib->getLib()->drawMap(_openGame->getGame()->getMap(), 0, 0);
                    _openLib->getLib()->drawText({"SCORE:", 140, 13, BASSEM, {255, 0, 0, 255, RED}, 60, true});
                    _openLib->getLib()->drawText({std::to_string(_openGame->getGame()->getScore()), 147, 17, BASSEM, {255, 0, 0, 255, RED}, 55, false});
                    std::transform(_selectedGame.begin(), _selectedGame.end(), _selectedGame.begin(), ::toupper);
                    _openLib->getLib()->drawText({_selectedGame, 8, 3, BASSEM, {255, 0, 0, 255, RED}, 55, true});
                    _openLib->getLib()->drawText({_playerName, 14, 7, BASSEM, {0, 191, 255, 255, CYAN}, 45, false});
                    if (_openGame->getGame()->gameOver() == true) {
                        _openLib->getLib()->drawText({"GAME OVER", 150, 13, GREG, {255, 0, 0, 255, RED}, 50, true});
                        updateScore();
                        _openGame->getGame()->reset();
                    }
                }
                _openLib->getLib()->display();
            }
            events_t event = _openLib->getLib()->catchEvent();

            if (_inGame == false) {
                if (event == N)
                    _WriteMode = true;
                if (event == L)
                    if (_WriteMode == false)
                        changeCurrentLibrary();
                if (event == Q)
                    if (_WriteMode == false)
                        run = false;
                size_t numberLib = _libraries.size();
                size_t numberGame = _games.size();
                if (event == LEFT) {
                    LibSelected = true;
                } else if (event == RIGHT) {
                    LibSelected = false;
                } else if (LibSelected) {
                    if (event == UP && _WriteMode == false) {
                        selectLib = (selectLib - 1 + numberLib) % numberLib;
                    } else if (event == DOWN) {
                        selectLib = (selectLib + 1) % numberLib;
                    } else if (event == INTERACT && _inGame == false) {
                        ALibSelected(selectLib, numberLib);
                    }
                } else {
                    if (event == UP && _WriteMode == false) {
                        selectGame = (selectGame - 1 + numberGame) % numberGame;
                    } else if (event == DOWN) {
                        selectGame = (selectGame + 1) % numberGame;
                    } else if (event == INTERACT && _inGame == false) {
                        _inGame = AGameSelected(selectGame);
                    }
                }
                if (_WriteMode && OldWriteMode == true) {
                    playerName = WritePlayerName(event, playerName);
                    _playerName = playerName.text;
                    continue;
                }
            } else {
                _openGame->getGame()->execEvent(event);
                if (event == L)
                    changeCurrentLibrary();
                else if (event == Q)
                    run = false;
                else if (event == MENU)
                    _inGame = false;
                else if (event == G) {
                    changeCurrentGame();
                }
            }
        }
    }
}
