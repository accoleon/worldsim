CXXFLAGS = -O3 -Wall -Wextra

all: worldsim
	
worldsim: main.o units.o
	$(CXX) $(CXXFLAGS) -o $(@) $^