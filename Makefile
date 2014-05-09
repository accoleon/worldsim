CC:=icc
CXX:=icpc
LD:=icpc
CFLAGS:=$(shell sdl2-config --cflags)
CXXFLAGS:=-Wall -Wextra -pedantic -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS:=-ltbb -std=c++11 $(shell sdl2-config --libs)
VPATH=Components Entities Systems

all: worldsim

worldsim: worldsim.o units.o World.o EntityManager.o SystemManager.o WaterSystem.o RenderSystem.o

testSDL: testSDL.o

clean:
	rm -f *.o worldsim testSDL
