/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFML
*/

#include "../include/SFML.hpp"

namespace Arcade
{
    SFML::SFML()
        : _Window(sf::VideoMode(1920, 1080), "ARCADE SFML WINDOW"), _xMin(0), _yMin(0), _xMax(0), _yMax(0)
    {
        _textureBackground.loadFromFile("assets/pictures/Arcade.jpg");
        _spriteBackground.setTexture(_textureBackground, true);
        _spriteBackground.setPosition(1, 1);
        _Window.draw(_spriteBackground);
        _Window.display();
    }

    SFML::~SFML()
    {
        _Window.close();
    }

    void SFML::drawText(const text_t &text)
    {
        sf::Text str;
        sf::Font font;
        if (text.underline)
            str.setStyle(sf::Text::Underlined | sf::Text::Bold);
        font.loadFromFile(text.police);
        str.setFont(font);
        str.setString(text.text);
        str.setCharacterSize(text.size);
        str.setPosition({static_cast<float>(text.pos_x * 10), static_cast<float>(text.pos_y * 25)});
        sf::Color color;
        color.r = text.color.r;
        color.g = text.color.g;
        color.b = text.color.b;
        color.a = text.color.a;
        str.setFillColor(color);
        _Window.draw(str);
    }

    events_t SFML::catchEvent()
    {
        sf::Event event;
        if (_Window.pollEvent(event)) {
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::A)
                    return A;
                else if (event.key.code == sf::Keyboard::B)
                    return B;
                else if (event.key.code == sf::Keyboard::C)
                    return C;
                else if (event.key.code == sf::Keyboard::D)
                    return D;
                else if (event.key.code == sf::Keyboard::E)
                    return E;
                else if (event.key.code == sf::Keyboard::F)
                    return F;
                else if (event.key.code == sf::Keyboard::G)
                    return G;
                else if (event.key.code == sf::Keyboard::H)
                    return H;
                else if (event.key.code == sf::Keyboard::I)
                    return I;
                else if (event.key.code == sf::Keyboard::J)
                    return J;
                else if (event.key.code == sf::Keyboard::K)
                    return K;
                else if (event.key.code == sf::Keyboard::L)
                    return L;
                else if (event.key.code == sf::Keyboard::M)
                    return M;
                else if (event.key.code == sf::Keyboard::N)
                    return N;
                else if (event.key.code == sf::Keyboard::O)
                    return O;
                else if (event.key.code == sf::Keyboard::P)
                    return P;
                else if (event.key.code == sf::Keyboard::Q)
                    return Q;
                else if (event.key.code == sf::Keyboard::R)
                    return R;
                else if (event.key.code == sf::Keyboard::S)
                    return S;
                else if (event.key.code == sf::Keyboard::T)
                    return T;
                else if (event.key.code == sf::Keyboard::U)
                    return U;
                else if (event.key.code == sf::Keyboard::V)
                    return V;
                else if (event.key.code == sf::Keyboard::W)
                    return W;
                else if (event.key.code == sf::Keyboard::X)
                    return X;
                else if (event.key.code == sf::Keyboard::Y)
                    return Y;
                else if (event.key.code == sf::Keyboard::Z)
                    return Z;
                else if (event.key.code == sf::Keyboard::Up)
                    return UP;
                else if (event.key.code == sf::Keyboard::Down)
                    return DOWN;
                else if (event.key.code == sf::Keyboard::Left)
                    return LEFT;
                else if (event.key.code == sf::Keyboard::Right)
                    return RIGHT;
                else if (event.key.code == sf::Keyboard::Backspace)
                    return DEL;
                else if (event.key.code == sf::Keyboard::Space)
                    return INTERACT;
                else if (event.key.code == sf::Keyboard::Escape)
                    return MENU;
            } else if (event.type == sf::Event::Closed)
                return Q;
        }
        return NOTHING;
    }

    void SFML::display()
    {
        _Window.display();
    }

    void SFML::myClear()
    {
        _Window.clear();
        if (_loadedTextures.find("assets/pictures/Arcade.jpg") == _loadedTextures.end()) {
            _textureBackground.loadFromFile("assets/pictures/Arcade.jpg");
            _loadedTextures["assets/pictures/Arcade.jpg"] = _textureBackground;
        } else {
            _textureBackground = _loadedTextures["assets/pictures/Arcade.jpg"];
        }
        _spriteBackground.setTexture(_textureBackground, true);
        _spriteBackground.setPosition(1, 1);
        _Window.draw(_spriteBackground);
    }

    void SFML::drawBackgroundGame(const std::string &pathBack, int xMin, int yMin, int xMax, int yMax)
    {
        _xMin = xMin;
        _yMin = yMin;
        _xMax = xMax;
        _yMax = yMax;
        if (_loadedTextures.find(pathBack) == _loadedTextures.end()) {
            _textureBackgroundGame.loadFromFile(pathBack);
            _loadedTextures[pathBack] = _textureBackgroundGame;
        } else {
            _textureBackgroundGame = _loadedTextures[pathBack];
        }
        _spriteBackgroundGame.setTexture(_textureBackgroundGame, true);
        _spriteBackgroundGame.setPosition(_xMin * 10, _yMin * 25);
        sf::Vector2u temp = _textureBackgroundGame.getSize();
        _spriteBackgroundGame.setScale((_xMax - _xMin) * 10.0 / temp.x, (_yMax - _yMin) * 25.0 / temp.y);
        _Window.draw(_spriteBackgroundGame);
    }

    void SFML::drawMap(const std::vector<std::vector<cell_t>> &picture, int xMapMax, int yMapMax)
    {
        size_t sizeMapY = picture.size();
        size_t sizeMapX = picture[0].size();
        if (xMapMax != 0 && yMapMax != 0) {
            sizeMapX = xMapMax;
            sizeMapY = yMapMax;
        }
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[i].size(); j++) {
                if (picture[i][j].path != "") {
                    if (_loadedTextures.find(picture[i][j].path) == _loadedTextures.end()) {
                        _textureCell.loadFromFile(picture[i][j].path);
                        _loadedTextures[picture[i][j].path] = _textureCell;
                    } else {
                        _textureCell = _loadedTextures[picture[i][j].path];
                    }
                    _spriteCell.setTexture(_textureCell, true);
                    _spriteCell.setPosition(_xMin * 10.0 + picture[i][j].pos_x * (10.0 * (_xMax - _xMin) / sizeMapX), (_yMin * 25.0 + picture[i][j].pos_y * (25.0 * (_yMax - _yMin) / sizeMapY)));
                    sf::Vector2u temp = _textureCell.getSize();
                    _spriteCell.setScale(10.0 * (_xMax - _xMin) / sizeMapX / temp.x, 25.0 * (_yMax - _yMin) / sizeMapY / temp.y);
                    _Window.draw(_spriteCell);
                }
            }
        }
    }

}

extern "C" Arcade::IGraphical *createGraphical()
{
    return new Arcade::SFML();
}
