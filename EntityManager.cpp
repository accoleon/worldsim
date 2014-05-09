// EntityManager.cpp
// EntityManager definition
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18

#include <iostream>
using std::cout;
using std::endl;

#include "EntityManager.h"
#include "Components/Component.h"
#include "Components/PositionComponent.h"
#include "Components/RenderComponent.h"
#include "Components/WaterComponent.h"


namespace gws {
	EntityManager::EntityManager(World& world) : world(world) {}
	EntityManager::~EntityManager() {}
	void EntityManager::addEntity(Entity& entity) {
		world.entities.push_back(entity);
		for (auto component : entity.components) {
			/*if (component.type == Position) {
				world.positions.push_back(component)
			}*/
		}
	}
} /* gws */