/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include "../Menu/Menu.hpp"
#include "../include/OpenGame.hpp"
#include "../include/OpenLib.hpp"
#include "../interfaces/IGraphical.hpp"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <dirent.h>
#include <iostream>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <vector>


#include <map>

namespace Arcade
{
    class Core
    {
    public:
        Core(const std::string &libName);
        ~Core();
        void createLibVector();
        void main_loop();
        int findLibIndex(std::string lib);
        void changeCurrentLibrary();
        bool check_graphical_lib(std::string str);
        bool check_game_lib(std::string str);
        void verif_score_exist();
        void putGameName();
        void putGameScore(std::string game, int pos_x);
        text_t WritePlayerName(events_t event, text_t playerName);
        text_t WritePlayerName_bis(events_t event, text_t playerName);
        void drawMenu();
        void createLib_Game_Names_to_Draw();
        void browse_in_menu(bool GameSelected, int selectLib, int selectGame);
        bool AGameSelected(int selectGame);
        void ALibSelected(int selectLib, int numLibraryOptions);
        void sort_score(std::vector<std::pair<std::string, int>>& scores);
        void updateScore();
        void changeCurrentGame();
        int findGameIndex(std::string gamename);
        void draw_instructions();

    protected:
    private:
        std::string _CurrentLibrary;
        std::vector<std::string> _Libfiles;
        std::vector<std::string> _Gamefiles;
        std::unique_ptr<OpenLib> _openLib;
        std::unique_ptr<OpenGame> _openGame;
        std::unique_ptr<Menu> _Menu;
        bool run;
        std::string _playerName;
        bool _WriteMode;
        std::vector<std::string> _libraries;
        std::vector<std::string> _games;
        std::string _selectedGame;
        bool _inGame;
        std::vector<std::pair<int, int>> _AllScore;
    };
}

#endif /* !CORE_HPP_ */
