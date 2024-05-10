/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** Ncurses
*/

#include "../include/Ncurses.hpp"
#include <fstream>
#include <vector>

namespace Arcade
{
    Ncurses::Ncurses()
    {
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        start_color();
        curs_set(0);
        cbreak();
        nodelay(stdscr, TRUE);
        init_pair(RED, COLOR_RED, COLOR_BLACK);
        init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
        init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
        init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
        init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(FOND_BLACK, COLOR_BLACK, COLOR_BLACK);
        init_pair(FOND_RED, COLOR_BLACK, COLOR_RED);
        init_pair(FOND_GREEN, COLOR_BLACK, COLOR_GREEN);
        init_pair(FOND_YELLOW, COLOR_BLACK, COLOR_YELLOW);
        init_pair(FOND_BLUE, COLOR_BLACK, COLOR_BLUE);
        init_pair(FOND_MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(FOND_CYAN, COLOR_BLACK, COLOR_CYAN);
        init_pair(FOND_WHITE, COLOR_BLACK, COLOR_WHITE);
    }

    Ncurses::~Ncurses()
    {
        clear();
        endwin();
    }

    void Ncurses::display()
    {
        refresh();
    }

    void Ncurses::myClear()
    {
        clear();
    }

    events_t Ncurses::catchEvent()
    {
        int get_getch;
        get_getch = getch();
        if (get_getch == KEY_UP)
            return UP;
        if (get_getch == KEY_DOWN)
            return DOWN;
        if (get_getch == KEY_RIGHT)
            return RIGHT;
        if (get_getch == KEY_LEFT)
            return LEFT;
        if (get_getch == 32)
            return INTERACT;
        if (get_getch == 27)
            return MENU;
        if (get_getch == KEY_BACKSPACE)
            return DEL;
        if (get_getch == 'a' || get_getch == 'A')
            return A;
        if (get_getch == 'b' || get_getch == 'B')
            return B;
        if (get_getch == 'c' || get_getch == 'C')
            return C;
        if (get_getch == 'd' || get_getch == 'D')
            return D;
        if (get_getch == 'e' || get_getch == 'E')
            return E;
        if (get_getch == 'f' || get_getch == 'F')
            return F;
        if (get_getch == 'g' || get_getch == 'G')
            return G;
        if (get_getch == 'h' || get_getch == 'H')
            return H;
        if (get_getch == 'i' || get_getch == 'I')
            return I;
        if (get_getch == 'j' || get_getch == 'J')
            return J;
        if (get_getch == 'k' || get_getch == 'K')
            return K;
        if (get_getch == 'l' || get_getch == 'L')
            return L;
        if (get_getch == 'm' || get_getch == 'M')
            return M;
        if (get_getch == 'n' || get_getch == 'N')
            return N;
        if (get_getch == 'o' || get_getch == 'O')
            return O;
        if (get_getch == 'p' || get_getch == 'P')
            return P;
        if (get_getch == 'q' || get_getch == 'Q')
            return Q;
        if (get_getch == 'r' || get_getch == 'R')
            return R;
        if (get_getch == 's' || get_getch == 'S')
            return S;
        if (get_getch == 't' || get_getch == 'T')
            return T;
        if (get_getch == 'u' || get_getch == 'U')
            return U;
        if (get_getch == 'v' || get_getch == 'V')
            return V;
        if (get_getch == 'w' || get_getch == 'W')
            return W;
        if (get_getch == 'x' || get_getch == 'X')
            return X;
        if (get_getch == 'y' || get_getch == 'Y')
            return Y;
        if (get_getch == 'z' || get_getch == 'Z')
            return Z;
        return NOTHING;
    }

    void Ncurses::drawText(const text_t &texte)
    {
        int max_x, max_y;
        getmaxyx(stdscr, max_y, max_x);
        if (max_x < 185 && max_y < 40) {
            move(LINES, COLS);
            attron(COLOR_PAIR(1) | A_BOLD | A_BLINK);
            printw("Put the terminal in full screen to continue.");
            attroff(COLOR_PAIR(1) | A_BOLD | A_BLINK);
            return;
        }
        int x_pos = (texte.pos_x);
        int y_pos = (texte.pos_y);
        move(y_pos, x_pos);
        if (texte.underline)
            attron(A_UNDERLINE);
        attron(COLOR_PAIR(texte.color.c) | A_BOLD);
        printw(texte.text.c_str());
        attroff(COLOR_PAIR(texte.color.c) | A_BOLD);
        if (texte.underline)
            attroff(A_UNDERLINE);
    }

    void Ncurses::drawMap(const std::vector<std::vector<cell_t>> &map, int xMapMax, int yMapMax)
    {
        for (size_t y = 0; y < map.size(); ++y) {
            for (size_t x = 0; x < map[y].size(); ++x) {
                move(map[y][x].pos_y + _yMin, map[y][x].pos_x + _xMin);
                attron(COLOR_PAIR(map[y][x].color.c));
                printw(" ");
                attroff(COLOR_PAIR(map[y][x].color.c));
            }
        }
    }

    void Ncurses::drawBackgroundGame(const std::string &pathBack, int xMin, int yMin, int xMax, int yMax)
    {
        _xMin = xMin;
        _yMin = yMin;
        _xMax = xMax;
        _yMax = yMax;
    }

}

extern "C" Arcade::IGraphical *createGraphical()
{
    return new Arcade::Ncurses();
}
