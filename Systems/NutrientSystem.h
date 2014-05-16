// NutrientSystem.h
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#ifndef NUTRIENT_SYSTEM_H
#define NUTRIENT_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class NutrientSystem : public System {
	public:
		NutrientSystem(World& world);
		~NutrientSystem();
		void update();
		std::string getName();
		int getNutrient(int index);
		void setNutrient(int index, int set);
		int compareNutrient(int former, int latter);
		void reduceNutrient(int index, int reduction);
		void increaseNutrient(int index, int addition);
	private:
		World& world;
		int nutrient_levels[];
	};
} /* gws */
#endif

