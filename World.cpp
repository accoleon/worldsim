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
	
	void World::runSystems() {
		// Probably don't want this - we have to order the systems to update 
		// in a certain order since they have dependencies - generally render at
		// the end of every other system
		for (auto system : systems) {
			system->update();
		}
	}
} /* gws */