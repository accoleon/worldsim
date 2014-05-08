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
	private:
		World& world;
	};
} /* gws */
#endif

