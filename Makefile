CC:=icc
CXX:=icpc
LD:=icpc
CFLAGS:=$(shell sdl2-config --cflags)
CXXFLAGS:=-Wall -Wextra -pedantic -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS:=-ltbb -std=c++11 $(shell sdl2-config --libs) -lGLEW -fopenmp
VPATH=Components Entities Systems
# OS X
ifeq ($(shell uname),Darwin)
	CXXFLAGS +=
	LDFLAGS += -framework OpenGL
else
	LDFLAGS += -lGL			
endif

all: worldsim

worldsim: worldsim.o units.o World.o SystemManager.o NutrientSystem.o RenderSystem.o OxygenSystem.o MovementSystem.o SurvivalSystem.o WaterSystem.o

testSDL: testSDL.o

clean:
	rm -f *.o worldsim testSDL
