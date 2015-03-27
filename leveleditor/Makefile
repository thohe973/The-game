CXXFLAGS=-Wall -Wextra -std=c++11 -Wno-unused-parameter -g
SDL_FLAGS=`sdl-config --libs --cflags` -lSDL_image


all: level_editor

level_editor: main.o sprite.o map.o
	g++ $(CXXFLAGS) main.cc sprite.cc map.cc -o level_editor $(SDL_FLAGS)

main.o: main.cc
	g++ $(CXXFLAGS) -c main.cc $(SDL_FLAGS)

sprite.o: sprite.cc
	g++ $(CXXFLAGS) -c sprite.cc $(SDL_FLAGS)

map.o: map.cc
	g++ $(CXXFLAGS) -c map.cc $(SDL_FLAGS)





.PHONY clean:
	rm -f main.o sprite.o map.o

