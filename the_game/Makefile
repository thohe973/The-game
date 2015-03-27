CXXFLAGS=-Wall -Wextra -std=c++11 -Wno-unused-parameter -Woverloaded-virtual -g
SDL_FLAGS=`sdl-config --libs --cflags` -lSDL_image -lSDL_ttf


all: the_game

the_game: main.o sprite.o game.o player.o cloud.o map.o timer.o menu.o text.o powerup.o arrow.o
	g++ $(CXXFLAGS) main.cc game.cc player.cc cloud.cc sprite.cc map.cc timer.cc menu.cc text.cc powerup.cc arrow.cc -o the_game $(SDL_FLAGS)

main.o: main.cc
	g++ $(CXXFLAGS) -c main.cc $(SDL_FLAGS)

sprite.o: sprite.cc
	g++ $(CXXFLAGS) -c sprite.cc $(SDL_FLAGS)

game.o: game.cc
	g++ $(CXXFLAGS) -c game.cc $(SDL_FLAGS)

player.o: player.cc
	g++ $(CXXFLAGS) -c player.cc $(SDL_FLAGS)

cloud.o: cloud.cc
	g++ $(CXXFLAGS) -c cloud.cc $(SDL_FLAGS)

map.o: map.cc
	g++ $(CXXFLAGS) -c map.cc $(SDL_FLAGS)

timer.o: timer.cc
	g++ $(CXXFLAGS) -c timer.cc $(SDL_FLAGS)

menu.o: menu.cc
	g++ $(CXXFLAGS) -c menu.cc $(SDL_FLAGS)

text.o: text.cc
	g++ $(CXXFLAGS) -c text.cc $(SDL_FLAGS)

powerup.o: powerup.cc
	g++ $(CXXFLAGS) -c powerup.cc $(SDL_FLAGS)

arrow.o: arrow.cc
	g++ $(CXXFLAGS) -c arrow.cc $(SDL_FLAGS)











.PHONY clean:
	rm -f main.o sprite.o game.o player.o cloud.o map.o timer.o menu.o text.o powerup.o arrow.o

