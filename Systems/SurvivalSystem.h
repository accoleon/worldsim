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
	enum survival_type {EXPLORE, STATIONARY, NORTH, EAST, SOUTH, WEST};
	public:
		SurvivalSystem(World& world);
		~SurvivalSystem();
		void update();
		std::string getName();
		SystemType getType();
		std::string getSurvivalType(int index);
		void setSurvivalType(int index, survival_type new_type);
		int tryRandom(int start_id);
		int tryClockwise(int start_id);
	private:
		World& world;
		survival_type survival_types[];
		
	};
} /* gws */
#endif

