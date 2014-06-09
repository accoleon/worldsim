// SurvivalSystem.h
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#ifndef SURVIVAL_SYSTEM_H
#define SURVIVAL_SYSTEM_H
#include "System.h"

namespace gws {
	class World;
	class SurvivalSystem : public System {
	enum SurvivalStrategy {EXPLORE, STATIONARY, NORTH, EAST, SOUTH, WEST};
	public:
		SurvivalSystem(World& world);
		~SurvivalSystem();
		void update();
		std::string getName();
		SystemType getType();
		std::string getSurvivalType(int index);
		void setSurvivalType(int index, SurvivalStrategy new_type);
	private:
		World& world;
		SurvivalStrategy survival_types[];
		
	};
} /* gws */
#endif

