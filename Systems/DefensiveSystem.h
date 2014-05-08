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
	private:
		World& world;
	};
} /* gws */
#endif

