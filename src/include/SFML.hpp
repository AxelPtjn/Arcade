/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_
#include "../interfaces/IGraphical.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Arcade{
    class SFML : public IGraphical {
        public:
            SFML();
            ~SFML();
            void drawText(const text_t &) override;
            events_t catchEvent() override;
            void display() override;
            void myClear() override;
            void drawBackgroundGame(const std::string &, int xMin, int yMin, int xMax, int yMax) override;
            void drawMap(const std::vector<std::vector<cell_t>> &map, int xMapMax, int yMapMax) override;

        private:
            sf::RenderWindow _Window;
            sf::Texture _textureBackgroundGame;
            sf::Sprite _spriteBackgroundGame;
            sf::Texture _textureCell;
            sf::Sprite _spriteCell;
            int _xMin;
            int _yMin;
            int _xMax;
            int _yMax;

            sf::Texture _textureBackground;
            sf::Sprite _spriteBackground;
            std::map<std::string, sf::Texture> _loadedTextures;

    };
}
#endif /* !SFML_HPP_ */
