// WaterSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef WATER_SYSTEM_H
#define WATER_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class WaterSystem : public System {
	public:
		WaterSystem(World& world);
		~WaterSystem();
		void Update();
	private:
		World& world;
	};
} /* gws */
#endif

