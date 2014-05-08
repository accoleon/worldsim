// OffensiveSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef OFFENSIVE_SYSTEM_H
#define OFFENSIVE_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class OffensiveSystem : public System {
	public:
		OffensiveSystem(World& world);
		~OffensiveSystem();
		void Update();
		std::string getName();
		int getOffenseStat(int index);
		void setOffenseStat(int index, int set);
		int compareOffenses(int former, int latter);
		void reduceOffense(int index, int reduction);
		void increaseOffense(int index, int addition);
	private:
		World& world;
		std::map<int, int> offensive_stats;
	};
} /* gws */
#endif

