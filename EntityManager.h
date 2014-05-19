// EntityManager.h
// EntityManager header
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Entity.h"
#include "World.h"

namespace gws {
	class EntityManager {
	public:
		EntityManager(World& world);
		~EntityManager();
		void addEntity(Entity& entity);
		void addRandomEntity();
		void addRandomLake();
		void addRandomPlant();
	private:
		World& world;
		int nextEntityID;
	};
} /* gws */
#endif
