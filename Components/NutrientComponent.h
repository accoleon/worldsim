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
		NutrientComponent(int nutrientLevel) : nutrientLevel(nutrientLevel){}
		int nutrientLevel;
		ComponentType getType() { return Nutrient; }
	};
} /* gws */
#endif
