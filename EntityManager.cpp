// EntityManager.cpp
// EntityManager definition
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18

#include <iostream>
using std::cout;
using std::endl;

#include "EntityManager.h"

namespace gws {
	EntityManager::EntityManager(World& world) : world(world) {}
	EntityManager::~EntityManager() {}
	void EntityManager::addEntity(Entity& entity) {
		world.entities.push_back(entity);
		for (auto component : entity.components) {
			cout << "this entity has a component!\n";
		}
	}
} /* gws */