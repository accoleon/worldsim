CC:=icpc
CXX:=icpc
CPPFLAGS:=-O3 -debug -Wall -Wextra -pedantic
LDFLAGS:=-lsfml-system -lsfml-graphics -lsfml-window -ltbb
UNAME:=$(shell uname)
ifeq ($(UNAME),Darwin)
CPPFLAGS+=-stdlib=libc++
LDFLAGS+=-stdlib=libc++
endif

all: worldsim

worldsim: worldsim.o units.o World.o EntityManager.o

testSFML: testSFML.o

clean:
	rm -f worldsim *.o
