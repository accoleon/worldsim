// EntityManager.cpp
// EntityManager definition
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18

#include <iostream>
using std::cout;
using std::endl;

#include "EntityManager.h"
//#include "Components/Component.h"
#include "Components/PositionComponent.h"
#include "Components/RenderComponent.h"
#include "Components/NutrientComponent.h"


namespace gws {
	EntityManager::EntityManager(World& world) : world(world) {}
	EntityManager::~EntityManager() {}
	void EntityManager::addEntity(Entity& entity) {
		entity.setID(nextEntityID++);
		world.entities.push_back(entity);
		for (auto component : entity.components) {
			switch (component->getType()) {
			case Nutrient:
				world.nutrients.push_back(component);
				break;
			case Position:
				world.positions.push_back(component);
				break;
			case Water:
				world.waters.push_back(component);
				break;
			case Render:
				world.renders.push_back(component);
				break;
			}
		}
	}
	void EntityManager::addRandomEntity() {
		// Create a random entity with random parameters
		
	}
	void EntityManager::addRandomLake() {
		Entity lake;
		lake.addComponent(new WaterComponent());
		lake.addComponent(new PositionComponent());
		lake.addComponent(new RenderComponent());
		addEntity(lake);
	}
} /* gws */
