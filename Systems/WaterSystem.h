// WaterSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef WATER_SYSTEM_H
#define WATER_SYSTEM_H
#include "System.h"

namespace gws {
	class World;
	class WaterSystem : public System {
	public:
		WaterSystem(World& world);
		~WaterSystem();
		void update();
		std::string getName();
		SystemType getType();
		int getWater(int index);
		void setWater(int index, int set);
		int compareWater(int former, int latter);
		void reduceWater(int index, int reduction);
		void increaseWater(int index, int addition);
	private:
		World& world;
		std::map<int, int> water_levels;
	};
} /* gws */
#endif

