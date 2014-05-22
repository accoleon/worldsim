// World.cpp
// World definition
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <cilk/cilk.h>
#include <iostream>
using std::cout;
using std::endl;

#include "World.h"

namespace gws {
	World::World(SDL_Window* window, int width, int height) : 
		width(width),
		height(height),
		waterSystem(*this),
		renderSystem(*this, window) {}
	World::~World() {}
	
	int World::addEntity() {
		int ID = nextEntityID++;
		positions.emplace_back();
		waters.emplace_back();
		return ID;
	}
	int World::addRandomPlant() {
		// Create a random plant-type entity
		int ID = addEntity();;
		return ID;
	}
	int World::addRandomLake() {
		// Create a random lake entity
		int ID = addEntity();;
		return ID;
	}
	
	void World::reserve(size_t size) {
		positions.reserve(size);
		waters.reserve(size);
		survivors.reserve(size);
	}
	
	void World::runSystems() {
		// Probably don't want this - we have to order the systems to update 
		// in a certain order since they have dependencies - generally render at
		// the end of every other system
		if (nextEntityID == 0) {
			cout << "World is empty" << endl;
		}
		waterSystem.update();
		
		// Rendering is done after everything else
		renderSystem.update();
	}
} /* gws */
