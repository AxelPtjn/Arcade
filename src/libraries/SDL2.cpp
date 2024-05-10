/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** SDL2
*/

#include "../include/SDL2.hpp"

namespace Arcade
{
    SDL2::SDL2()
        : _Window(NULL), _Renderer(NULL),
          _textureBackgroundGame(NULL),
          _BackgroundGameSurface(NULL), _xMin(0), _yMin(0), _xMax(0), _yMax(0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        _Window = SDL_CreateWindow("ARCADE SDL_2 WINDOW", 100, 100, 1920, 1080, SDL_WINDOW_RESIZABLE);
        _Renderer = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_ACCELERATED);
        TTF_Init();

        _BackgroundGameSurface = IMG_Load("assets/pictures/Arcade.jpg");
        _Rect = {1, 1, _BackgroundGameSurface->w, _BackgroundGameSurface->h};

        _textureBackgroundGame = IMG_LoadTexture(_Renderer, "assets/pictures/Arcade.jpg");
        SDL_RenderCopy(_Renderer, _textureBackgroundGame, NULL, &_Rect);

        SDL_RenderPresent(_Renderer);
    }

    SDL2::~SDL2()
    {
        if (_textureBackgroundGame)
            SDL_DestroyTexture(_textureBackgroundGame);
        if (_Renderer)
            SDL_DestroyRenderer(_Renderer);
        if (_Window)
            SDL_DestroyWindow(_Window);
        TTF_Quit();
        SDL_Quit();
    }

    events_t SDL2::catchEvent()
    {
        SDL_Event event;

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_Quit();
                return Q;
            }
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_LEFT) {
                    return LEFT;
                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    return RIGHT;
                } else if (event.key.keysym.sym == SDLK_UP) {
                    return UP;
                } else if (event.key.keysym.sym == SDLK_DOWN) {
                    return DOWN;
                } else if (event.key.keysym.sym == SDLK_a) {
                    return A;
                } else if (event.key.keysym.sym == SDLK_b) {
                    return B;
                } else if (event.key.keysym.sym == SDLK_c) {
                    return C;
                } else if (event.key.keysym.sym == SDLK_d) {
                    return D;
                } else if (event.key.keysym.sym == SDLK_e) {
                    return E;
                } else if (event.key.keysym.sym == SDLK_f) {
                    return F;
                } else if (event.key.keysym.sym == SDLK_g) {
                    return G;
                } else if (event.key.keysym.sym == SDLK_h) {
                    return H;
                } else if (event.key.keysym.sym == SDLK_i) {
                    return I;
                } else if (event.key.keysym.sym == SDLK_j) {
                    return J;
                } else if (event.key.keysym.sym == SDLK_k) {
                    return K;
                } else if (event.key.keysym.sym == SDLK_l) {
                    return L;
                } else if (event.key.keysym.sym == SDLK_m) {
                    return M;
                } else if (event.key.keysym.sym == SDLK_n) {
                    return N;
                } else if (event.key.keysym.sym == SDLK_o) {
                    return O;
                } else if (event.key.keysym.sym == SDLK_p) {
                    return P;
                } else if (event.key.keysym.sym == SDLK_q) {
                    return Q;
                } else if (event.key.keysym.sym == SDLK_r) {
                    return R;
                } else if (event.key.keysym.sym == SDLK_s) {
                    return S;
                } else if (event.key.keysym.sym == SDLK_t) {
                    return T;
                } else if (event.key.keysym.sym == SDLK_u) {
                    return U;
                } else if (event.key.keysym.sym == SDLK_v) {
                    return V;
                } else if (event.key.keysym.sym == SDLK_w) {
                    return W;
                } else if (event.key.keysym.sym == SDLK_x) {
                    return X;
                } else if (event.key.keysym.sym == SDLK_y) {
                    return Y;
                } else if (event.key.keysym.sym == SDLK_z) {
                    return Z;
                } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    return DEL;
                } else if (event.key.keysym.sym == SDLK_SPACE) {
                    return INTERACT;
                } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return MENU;
                }
            }
        }
        return NOTHING;
    }

    void SDL2::display()
    {
        SDL_RenderPresent(_Renderer);
    }

    void SDL2::myClear()
    {
        SDL_RenderClear(_Renderer);
        SDL_RenderCopy(_Renderer, _textureBackgroundGame, NULL, &_Rect);
    }

    void SDL2::drawText(const text_t &str)
    {
        SDL_Surface *_textSurface = NULL;
        SDL_Texture *_textTexture = NULL;
        TTF_Font *font = TTF_OpenFont(str.police.c_str(), str.size);
        if (str.underline)
            TTF_SetFontStyle(font, TTF_STYLE_BOLD | TTF_STYLE_UNDERLINE);

        SDL_Color textColor;
        textColor.r = str.color.r;
        textColor.g = str.color.g;
        textColor.b = str.color.b;
        textColor.a = str.color.a;
        _textSurface = TTF_RenderText_Blended(font, str.text.c_str(), textColor);
        _textTexture = SDL_CreateTextureFromSurface(_Renderer, _textSurface);
        SDL_Rect textRect = {str.pos_x * 10, str.pos_y * 25, _textSurface->w, _textSurface->h};
        SDL_RenderCopy(_Renderer, _textTexture, NULL, &textRect);
        SDL_DestroyTexture(_textTexture);
        TTF_CloseFont(font);
        SDL_FreeSurface(_textSurface);
    }

    void SDL2::drawBackgroundGame(const std::string &pathBack, int xMin, int yMin, int xMax, int yMax)
    {
        SDL_Surface *BackgroundGameSurface = NULL;
        SDL_Texture *textureBackgroundGame = NULL;
        BackgroundGameSurface = IMG_Load(pathBack.c_str());
        _xMin = xMin;
        _yMin = yMin;
        _xMax = xMax;
        _yMax = yMax;
        SDL_Rect Rect = {_xMin * 10, _yMin * 25, (_xMax - _xMin) * 10, (_yMax - _yMin) * 25};

        textureBackgroundGame = IMG_LoadTexture(_Renderer, pathBack.c_str());
        SDL_RenderCopy(_Renderer, textureBackgroundGame, NULL, &Rect);
        SDL_DestroyTexture(textureBackgroundGame);
        SDL_FreeSurface(BackgroundGameSurface);
    }

    void SDL2::drawMap(const std::vector<std::vector<cell_t>> &picture, int xMapMax, int yMapMax)
    {
        size_t sizeMapY = picture.size();
        size_t sizeMapX = picture[0].size();
        if (xMapMax != 0 && yMapMax != 0) {
            sizeMapX = xMapMax;
            sizeMapY = yMapMax;
        }
        SDL_Texture *_textureCell = NULL;
        SDL_Surface *_cellSurface = NULL;
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[i].size(); j++) {
                if (picture[i][j].path != "") {
                    _cellSurface = IMG_Load(picture[i][j].path.c_str());
                    int _size_cell_x = 10 * (_xMax - _xMin) / sizeMapX;
                    int _size_cell_y = 25 * (_yMax - _yMin) / sizeMapY;
                    SDL_Rect Rect = {_xMin * 10 + picture[i][j].pos_x * _size_cell_x, _yMin * 25 + picture[i][j].pos_y * _size_cell_y, _size_cell_x, _size_cell_y};
                    _textureCell = IMG_LoadTexture(_Renderer, picture[i][j].path.c_str());
                    SDL_RenderCopy(_Renderer, _textureCell, NULL, &Rect);
                    SDL_DestroyTexture(_textureCell);
                    SDL_FreeSurface(_cellSurface);
                }
            }
        }
    }
}

extern "C" Arcade::IGraphical *createGraphical()
{
    return new Arcade::SDL2();
}
