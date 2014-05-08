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
	private:
		World& world;
	};
} /* gws */
#endif

