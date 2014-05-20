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
	World::World(int width, int height) : width(width), height(height) {}
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
		//Entity plant;
		//plant.addComponent(new PositionComponent());
		//plant.addComponent(new RenderComponent());
		return ID;
	}
	int World::addRandomLake() {
		// Create a random lake entity
		int ID = addEntity();;
		//lake.addComponent(new WaterComponent());
		//lake.addComponent(new PositionComponent());
		//lake.addComponent(new RenderComponent());
		return ID;
	}
	// This might not be necessary - we already know what we want to add
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
