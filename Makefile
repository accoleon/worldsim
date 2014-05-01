CC:=icpc
CXX:=icpc
CFLAGS:=$(shell sdl2-config --cflags)
CXXFLAGS:=-O3 -Wall -Wextra -pedantic -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS:=-ltbb -std=c++11 $(shell sdl2-config --libs)
UNAME:=$(shell uname)
ifeq ($(UNAME),Darwin)
endif
VPATH=Components Entities Systems

all: worldsim

worldsim: worldsim.o units.o World.o EntityManager.o SystemManager.o WaterSystem.o RenderSystem.o

testSFML: testSFML.o

testSDL: testSDL.o

clean:
	rm -f *.o worldsim testSFML
