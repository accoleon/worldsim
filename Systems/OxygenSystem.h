// OxygenSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef OXYGEN_SYSTEM_H
#define OXYGEN_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class OxygenSystem : public System {
	public:
		OxygenSystem(World& world);
		~OxygenSystem();
		void Update();
		std::string getName();
		int getOxygen(int index);
		void setOxygen(int index, int set);
		int compareOxygen(int former, int latter);
		void reduceOxygen(int index, int reduction);
		void increaseOxygen(int index, int addition);
	private:
		World& world;
		std::map<int, int> oxygen_levels;
	};
} /* gws */
#endif

