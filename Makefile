CC:=icpc
CXX:=icpc
CXXFLAGS:=-O3 -Wall -Wextra -pedantic -std=c++11
LDFLAGS:=-ltbb -lsdl2 -std=c++11
UNAME:=$(shell uname)
ifeq ($(UNAME),Darwin)
#export CPLUS_INCLUDE_PATH=/usr/local/Cellar/gcc/4.8.2/lib/gcc/x86_64-apple-darwin13.1.0/4.8.2/include/c++:/usr/local/Cellar/gcc/4.8.2/lib/gcc/x86_64-apple-darwin13.1.0/4.8.2/include/c++/x86_64-apple-darwin13.1.0
#CXXFLAGS+=-gxx-name=g++-4.8 -no-use-clang-env
#LDFLAGS+=-gxx-name=g++-4.8 -no-use-clang-env
endif
VPATH=Components Entities Systems

all: worldsim

worldsim: worldsim.o units.o World.o EntityManager.o SystemManager.o WaterSystem.o RenderSystem.o

testSFML: testSFML.o

testSDL: testSDL.o

clean:
	rm -f *.o worldsim testSFML
