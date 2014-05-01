// World.cpp
// World definition
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <iostream>
using std::cout;
using std::endl;

#include "World.h"

namespace gws {
	World::World(int width, int height) : width(width), height(height) {}
	World::~World() {}
	void World::addSystem(System& system) {
		systems.push_back(&system);
		cout << "World: Added " << system.getName() << endl;
	}
} /* gws */