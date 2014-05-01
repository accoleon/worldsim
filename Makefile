CC:=icpc
CXX:=icpc
CXXFLAGS:=-O3 -Wall -Wextra -pedantic -std=c++11
LDFLAGS:=-ltbb -lSDL2 -std=c++11
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
