CC:=icpc
CXX:=icpc
CPPFLAGS:=-O3 -debug -Wall -Wextra -pedantic
LDFLAGS:=-lsfml-system -lsfml-graphics -lsfml-window -ltbb
UNAME:=$(shell uname)
ifeq ($(UNAME),Darwin)
CPPFLAGS+=-stdlib=libc++
LDFLAGS+=-stdlib=libc++
endif
VPATH=Components Entities Systems

all: worldsim testSFML

worldsim: worldsim.o units.o World.o EntityManager.o SystemManager.o

testSFML: testSFML.o

clean:
	rm -f *.o worldsim testSFML
