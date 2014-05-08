// SurvivalSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef SURVIVAL_SYSTEM_H
#define SURVIVAL_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class SurvivalSystem : public System {
	public:
		SurvivalSystem(World& world);
		~SurvivalSystem();
		void Update();
		std::string getName();
	private:
		World& world;
	};
} /* gws */
#endif

