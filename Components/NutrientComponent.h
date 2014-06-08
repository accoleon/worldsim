// NutrientComponent.h
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#ifndef NUTRIENT_COMPONENT_H
#define NUTRIENT_COMPONENT_H
#include "Component.h"
using namespace gws;
namespace gws {
	struct NutrientComponent : Component {
		int nutrientLevel;
		const static int min = 0;
		const static int max = 100;
		NutrientComponent(int nutrientLevel) : nutrientLevel(nutrientLevel) {
			active = true;
		}
		NutrientComponent(bool isActive) {
			if(isActive) {
				active = true;
				nutrientLevel = rand() % max + min;
			} else {
				active = false;
			}
		}
	};
} /* gws */
#endif
