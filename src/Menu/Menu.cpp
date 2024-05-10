/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Menu
*/

#include "Menu.hpp"

#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

namespace Arcade
{
    Menu::Menu()
    {
    }

    Menu::~Menu()
    {
    }

    text_t Menu::DisplayTitle()
    {
        text_t title;
        title.color.r = 235;
        title.color.g = 9;
        title.color.b = 9;
        title.color.a = 255;
        title.color.c = RED;
        title.size = 60;
        title.pos_x = ((190 / 2) - 3);
        title.pos_y = 2;
        title.text = "ARCADE";
        title.police = BASSEM;
        title.underline = false;

        return title;
    }

    text_t Menu::GetPlayerName()
    {
        text_t player;
        player.police = BASSEM;
        player.color.r = 0;
        player.color.g = 255;
        player.color.b = 255;
        player.color.a = 255;
        player.color.c = CYAN;
        player.size = 35;
        player.pos_x = 9;
        player.pos_y = 7;
        player.text = " ";
        player.underline = false;

        return player;
    }

    text_t Menu::showPlayTitle()
    {
        text_t title;
        title.police = BASSEM;
        title.color.r = 255;
        title.color.g = 0;
        title.color.b = 0;
        title.color.a = 255;
        title.color.c = RED;
        title.size = 35;
        title.pos_x = 6;
        title.pos_y = 5;
        title.text = "Player Name : ";
        title.underline = false;
        return title;
    }

    void Menu::create_score_file(std::string filename)
    {
        size_t posStart = filename.find("score_");
        posStart += 6;
        size_t posEnd = filename.find(".txt", posStart);
        std::string gameName = filename.substr(posStart, posEnd - posStart);
        chmod(filename.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        std::ofstream file(filename);

        file.close();

        chmod(filename.c_str(), S_IRUSR | S_IRGRP | S_IROTH);
        return;
    }

    text_t Menu::show_instructions()
    {
        text_t title;
        title.police = BASSEM;
        title.color.r = 0;
        title.color.g = 174;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = BLUE;
        title.size = 16;
        title.pos_x = 7;
        title.pos_y = 34;
        title.text = "INSTRUCTIONS";
        title.underline = true;
        return title;
    }

    text_t Menu::show_Escape()
    {
        text_t title;
        title.police = GREG;
        title.color.r = 255;
        title.color.g = 255;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = WHITE;
        title.size = 16;
        title.pos_x = 1;
        title.pos_y = 35;
        title.text = "-> ESCAPE TO GO BACK TO THE LIBRARY";
        title.underline = false;
        return title;
    }

    text_t Menu::show_L()
    {
        text_t title;
        title.police = GREG;
        title.color.r = 255;
        title.color.g = 255;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = WHITE;
        title.size = 16;
        title.pos_x = 1;
        title.pos_y = 36;
        title.text = "-> L TO CHANGE THE LIBRARY";
        title.underline = false;
        return title;
    }

    text_t Menu::show_Interact()
    {
        text_t title;
        title.police = GREG;
        title.color.r = 255;
        title.color.g = 255;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = WHITE;
        title.size = 16;
        title.pos_x = 1;
        title.pos_y = 37;
        title.text = "-> [SPACE] TO INTERACT WITH THE MEU";
        title.underline = false;
        return title;
    }

    text_t Menu::show_arrow()
    {
        text_t title;
        title.police = GREG;
        title.color.r = 255;
        title.color.g = 255;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = WHITE;
        title.size = 16;
        title.pos_x = 1;
        title.pos_y = 38;
        title.text = "-> USING ARROWS TO MOVE AROUND THE MENU AND IN THE GAME";
        title.underline = false;
        return title;
    }

    text_t Menu::show_G()
    {
        text_t title;
        title.police = GREG;
        title.color.r = 255;
        title.color.g = 255;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = WHITE;
        title.size = 16;
        title.pos_x = 1;
        title.pos_y = 39;
        title.text = "-> G TO CHANGE THE GAME (IN GAME)";
        title.underline = false;
        return title;
    }

    text_t Menu::show_R()
    {
        text_t title;
        title.police = GREG;
        title.color.r = 255;
        title.color.g = 255;
        title.color.b = 255;
        title.color.a = 255;
        title.color.c = WHITE;
        title.size = 16;
        title.pos_x = 1;
        title.pos_y = 40;
        title.text = "-> R TO RESET THE GAME (IN GAME)";
        title.underline = false;
        return title;
    }
}