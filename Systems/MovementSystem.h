// MovementSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class MovementSystem : public System {
	public:
		MovementSystem(World& world);
		~MovementSystem();
		void Update();
		std::string getName();
	private:
		World& world;
	};
} /* gws */
#endif

