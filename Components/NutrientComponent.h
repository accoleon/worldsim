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
		const static int max = 255;
		NutrientComponent(int nutrientLevel) : nutrientLevel(nutrientLevel) {
			active = true;
		}
		NutrientComponent() : NutrientComponent(rand() % max + min) {}
	};
} /* gws */
#endif
