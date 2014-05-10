// NutrientComponent.h
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include "Component.h"
#ifndef NUTRIENT_COMPONENT_H
#define NUTRIENT_COMPONENT_H
namespace gws {
	struct NutrientComponent : Component {
		NutrientComponent(int nutrientLevel) : nutrientLevel(nutrientLevel){}
		int nutrientLevel;
	};
} /* gws */
#endif
