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
	const static int min = 0;
	const static int max = 255;
	World::World(SDL_Window* window, int width, int height) : 
		width(width),
		height(height),
		waterSystem(*this),
		nutrientSystem(*this),
		survivalSystem(*this),
		renderSystem(*this, window) {}
	World::~World() {}
	
	size_t World::addRandomPlant() {
		// Create a random plant-type entity
		size_t ID = nextEntityID++;
		positions.emplace_back(true);
		survivors.emplace_back(false);
		nutrients.emplace_back(true);
		waters.emplace_back(false);
		return ID;
	}
	size_t World::addRandomAnimal() {
		// Create a random lake entity
		size_t ID = nextEntityID++;
		positions.emplace_back(true);
		survivors.emplace_back(true);
		nutrients.emplace_back(true);
		waters.emplace_back(false);
		return ID;
	}
	size_t World::addRandomLake() {
		// Create a random lake entity
		size_t ID = nextEntityID++;
		positions.emplace_back(true);
		survivors.emplace_back(false);
		nutrients.emplace_back(false);
		waters.emplace_back(true);
		return ID;
	}
	void World::reserve(size_t size) {
		positions.reserve(size);
		survivors.reserve(size);
		nutrients.reserve(size);
		waters.reserve(size);
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
