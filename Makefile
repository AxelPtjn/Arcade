##
## EPITECH PROJECT, 2024
## B-OOP-400-LYN-4-1-arcade-gnanmienlie-patrick-levy.n-da
## File description:
## Makefile
##

SRC = 	src/main.cpp \
		src/Core/Core.cpp \
		src/Parser.cpp \
		src/Error/Error.cpp \
		src/OpenLib.cpp \
		src/OpenGame.cpp \
		src/Menu/Menu.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -std=c++20 -g3 -fPIC

NAME = arcade

SFML_LIB	=	lib/arcade_sfml.so
SFML_FILE	=	src/libraries/SFML.cpp
SFML_FLAGS	=	-shared -fPIC -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window -lm
OBJ_SFML	=	$(SFML_FILE:.cpp=.o)

NCURSES_LIB		=	lib/arcade_ncurses.so
NCURSES_FILE	=	src/libraries/Ncurses.cpp
NCURSES_FLAGS	=	-shared -fPIC -lncurses
OBJ_NCURSES		=	$(NCURSES_FILE:.cpp=.o)

SDL2_LIB	=	lib/arcade_sdl2.so
SDL2_FILE	= 	src/libraries/SDL2.cpp
SDL2_FLAGS	=	-shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image
OBJ_SDL2	= 	$(SDL2_FILE:.cpp=.o)

SNAKE_LIB	=	lib/arcade_snake.so
SNAKE_FILE	=	src/games/Snake.cpp
SNAKE_FLAGS	=	-shared -fPIC
OBJ_SNAKE	=	$(SNAKE_FILE:.cpp=.o)

NIBBLER_LIB	=	lib/arcade_nibbler.so
NIBBLER_FILE	=	src/games/Nibbler.cpp
NIBBLER_FLAGS	=	-shared -fPIC
OBJ_NIBBLER	=	$(NIBBLER_FILE:.cpp=.o)

.PHONY: all clean fclean re core graphicals games

all: core graphicals games

core: $(NAME)

graphicals: $(SFML_LIB) $(NCURSES_LIB) $(SDL2_LIB)

games: $(SNAKE_LIB) $(NIBBLER_LIB)

$(NAME): $(OBJ)
	g++ $(CXXFLAGS) -o $(NAME) $(OBJ) -fPIC -ldl -fno-gnu-unique

$(SFML_LIB): $(OBJ_SFML)
	g++ $(CXXFLAGS) $(OBJ_SFML) -o $(SFML_LIB) $(SFML_FLAGS)

$(NCURSES_LIB): $(OBJ_NCURSES)
	g++ $(CXXFLAGS) $(OBJ_NCURSES) -o $(NCURSES_LIB) $(NCURSES_FLAGS)

$(SDL2_LIB): $(OBJ_SDL2)
	g++ $(CXXFLAGS) $(OBJ_SDL2) -o $(SDL2_LIB) $(SDL2_FLAGS)

$(SNAKE_LIB): $(OBJ_SNAKE)
	g++ $(CXXFLAGS) $(OBJ_SNAKE) -o $(SNAKE_LIB) $(SNAKE_FLAGS)

$(NIBBLER_LIB): $(OBJ_NIBBLER)
	g++ $(CXXFLAGS) $(OBJ_NIBBLER) -o $(NIBBLER_LIB) $(NIBBLER_FLAGS)

clean:
	rm -f $(OBJ) $(OBJ_SNAKE) $(OBJ_NIBBLER) $(OBJ_SDL2) $(OBJ_NCURSES) $(OBJ_SFML)

fclean: clean
	rm -f $(NAME) $(SFML_LIB) $(NCURSES_LIB) $(SDL2_LIB) $(SNAKE_LIB) $(NIBBLER_LIB)

re: fclean all
