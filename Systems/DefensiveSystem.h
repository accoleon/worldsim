// DefensiveSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef DEFENSIVE_SYSTEM_H
#define DEFENSIVE_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class DefensiveSystem : public System {
	public:
		DefensiveSystem(World& world);
		~DefensiveSystem();
		void Update();
		std::string getName();
		int getDefenseStat(int index);
		void setDefenseStat(int index, int set);
		int compareDefenses(int former, int latter);
		void reduceDefense(int index, int reduction);
		void increaseDefense(int index, int addition);
	private:
		World& world;
		std::map<int, int> defensive_stats;
	};
} /* gws */
#endif

