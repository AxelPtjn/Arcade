/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
    #define SDL2_HPP_
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>

#include "../interfaces/IGraphical.hpp"

namespace Arcade {
    class SDL2 : public IGraphical {
        public:
            SDL2();
            ~SDL2();
            events_t catchEvent() override;
            void display() override;
            void myClear() override;
            void drawText(const text_t &) override;
            void drawBackgroundGame(const std::string &, int xMin, int yMin, int xMax, int yMax) override;
            void drawMap(const std::vector<std::vector<cell_t>> &map, int xMapMax, int yMapMax) override;

        protected:
        private:
            SDL_Window *_Window;
            SDL_Renderer *_Renderer;
            SDL_bool run;
            int _xMin;
            int _yMin;
            int _xMax;
            int _yMax;

            SDL_Texture *_textureBackgroundGame;
            SDL_Surface *_BackgroundGameSurface;
            SDL_Rect _Rect;

    };
}
#endif /* !SDL2_HPP_ */
