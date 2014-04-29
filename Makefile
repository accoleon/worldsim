CC:=icc
CXX:=icpc
CXXFLAGS:=-O3 -Wall -Wextra $(shell sdl2-config --cflags)
LDFLAGS:=$(shell sdl2-config --libs)

all: worldsim
	
worldsim: worldsim.o units.o

clean:
	rm -f worldsim *.o
