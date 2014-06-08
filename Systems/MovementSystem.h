// MovementSystem.h
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H
#include "System.h"



namespace gws {
	// Forward declarations
	class World;
	
	class MovementSystem : public System {
	public:
		MovementSystem(World& world);
		~MovementSystem();
		void update();
		std::string getName();
		SystemType getType();
		int getMovement(int index);
		void setMovement(int index, int set);
		int compareMovements(int former, int latter);
		void reduceMovement(int index, int reduction);
		void increaseMovement(int index, int addition);
	private:
		World& world;
		int movement_stats[];
	};
} /* gws */
#endif

