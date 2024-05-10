/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** tools
*/
#include <iostream>

#ifndef TOOLS_HPP_
#define TOOLS_HPP_
#define GREG "assets/fonts/Georgia Regular font.ttf"
#define BASSEM "assets/fonts/Workbench-Regular-VariableFont_BLEDSCAN.ttf"

namespace Arcade
{

    enum Color {
        RED = 1,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        FOND_BLACK,
        FOND_RED,
        FOND_GREEN,
        FOND_YELLOW,
        FOND_BLUE,
        FOND_MAGENTA,
        FOND_CYAN,
        FOND_WHITE
    };

    typedef struct color {
        int r;
        int g;
        int b;
        int a;
        Color c;
    }color_t;

    typedef struct text_to_display {
        std::string text;
        int pos_x;
        int pos_y;
        std::string police;
        color_t color;
        int size;
        bool underline;
    } text_t;

    typedef struct cell {
        std::string path;
        std::string text;
        color_t color;
        int pos_x;
        int pos_y;
    } cell_t;

    typedef enum {
        NOTHING = -1, // No event
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        DEL,           // Delete character
        MENU,          // Go back to the menu
        UP,            // Up
        DOWN,          // Down
        LEFT,          // Left
        RIGHT,         // Right
        INTERACT,      // Interact with the game
        PAUSE = P,     // Game in pause (optional)
        RESET = R,     // Reset the game
        LIB_GRAPH = L, // Change graphical library
        GAME = G,      // Change game
        QUIT = Q       // Quit the programme
    } events_t;

}

#endif /* !TOOLS_HPP_ */