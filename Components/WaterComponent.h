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
	struct WaterComponent : Component {
		int waterLevel;
		const static int min = 0;
		const static int max = 255;
		WaterComponent(int waterLevel) : waterLevel(waterLevel) {
			active = true;
		}
		WaterComponent() : WaterComponent(rand() % max + min) {}
	};
} /* gws */
#endif
