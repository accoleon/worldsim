// WaterComponent.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#ifndef WATER_COMPONENT_H
#define WATER_COMPONENT_H
#include <cstdlib>

#include "Component.h"
namespace gws {
	struct WaterComponent : gws::Component {
		int waterLevel;
		const int min = 0;
		const int max = 255;
		WaterComponent(int waterLevel) : waterLevel(waterLevel){}
		WaterComponent() { // default constructor - randomized
			waterLevel = rand() % max + min;
		}
		ComponentType getType() { return Water; }
	};
} /* gws */
#endif
