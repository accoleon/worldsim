// Entity.h
// Entity header file
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18
#ifndef ENTITY_H
#define ENTITY_H
#include <vector>

#include "Components/Component.h"

namespace gws {
	struct Entity {
		int id;
		std::vector<Component*> components;
		void addComponent(Component* component) {
			components.push_back(component);
		}
		void setID(int id) {
			for (auto component : components) {
				component->ID = id;
			}
		}
	};
} /* gws */

#endif
