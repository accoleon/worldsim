CC:=icpc
CXX:=icpc
CPPFLAGS:=-debug -Wall -Wextra -pedantic -stdlib=libc++
LDFLAGS:=-lsfml-system -lsfml-graphics -lsfml-window -ltbb -stdlib=libc++

all: worldsim
	
worldsim: worldsim.o units.o World.o EntityManager.o

testSFML: testSFML.o

clean:
	rm -f worldsim *.o
