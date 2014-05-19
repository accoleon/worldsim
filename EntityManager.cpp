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
#include "Components/SurvivalComponent.h"
#include "Components/PositionComponent.h"
#include "Components/RenderComponent.h"
#include "Components/NutrientComponent.h"


namespace gws {
	EntityManager::EntityManager(World& world) : world(world), nextEntityID(0) {}
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
				world.positions.push_back(static_cast<PositionComponent*>(component));
				break;
			case Water:
				world.waters.push_back(static_cast<WaterComponent*>(component));
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
	
	void EntityManager::addRandomPlant() {
		// Create a random plant-type entity
		Entity plant;
		plant.addComponent(new PositionComponent());
		plant.addComponent(new RenderComponent());
	}
	void EntityManager::addRandomLake() {
		Entity lake;
		lake.addComponent(new WaterComponent());
		lake.addComponent(new PositionComponent());
		lake.addComponent(new RenderComponent());
		addEntity(lake);
	}
} /* gws */
