// WaterComponent.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#include "Component.h"
#ifndef WATER_COMPONENT_H
#define WATER_COMPONENT_H
namespace gws {
	struct WaterComponent : Component {
		WaterComponent(int waterLevel) : waterLevel(waterLevel) : type(Water) {}
		int waterLevel;
	};
} /* gws */
#endif
