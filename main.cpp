// main.cpp
// main simulation file - loads world and objects
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-16

#include <iostream>
using std::cout;
using std::endl;
#include <string>

#include "units.hpp"
using namespace gensim;

units world;

void createUnits() {
	cout << "Creating units...\n";
	// Create a basic plant;
	
}

void runWorld() {
	cout << "Running world...\n";
}

void teardown()
{
	cout << "Tearing down...\n";
}

int main (int, char**)
{
	// create units
	createUnits();
	// run world
	runWorld();
	// teardown
	teardown();
	return 0;
}