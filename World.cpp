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
	
	size_t World::addEntity() {
		size_t ID = nextEntityID++;
		positions.emplace_back();
		waters.emplace_back();
		return ID;
	}
	size_t World::addRandomPlant() {
		// Create a random plant-type entity
		size_t ID = nextEntityID++;
		positions.emplace_back();
		survivors.emplace_back(STATIONARY,rand() % max + min,rand() % max + min);
		nutrients.emplace_back(100);
		return ID;
	}
	size_t World::addRandomAnimal() {
		// Create a random lake entity
		size_t ID = nextEntityID++;
		positions.emplace_back();
		survivors.emplace_back(EXPLORE,rand() % max + min,rand() % max + min);
		nutrients.emplace_back(100);
		return ID;
	}
	size_t World::addRandomLake() {
		// Create a random lake entity
		size_t ID = nextEntityID++;
		positions.emplace_back();
		waters.emplace_back();
		return ID;
	}
	void World::reserve(size_t size) {
		positions.reserve(size);
		nutrients.reserve(size);
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
