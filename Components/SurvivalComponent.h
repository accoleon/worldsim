// SurvivalComponent.h
// Sam Cagle
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-19

#ifndef SURVIVAL_COMPONENT_H
#define SURVIVAL_COMPONENT_H
#include "Component.h"
namespace gws {
	enum SurvivalStrategy {
		EXPLORE,
		STATIONARY,
		BREED,
		NORTH,
		EAST,
		SOUTH,
		WEST
	};
	struct SurvivalComponent : Component {
		SurvivalComponent(
			SurvivalStrategy strat,
			int nutrientRequirement,
			int waterRequirement) : 
			strategy(strat),
			nutrientRequirement(nutrientRequirement),
			waterRequirement(waterRequirement) {}
		ComponentType getType() { return Survival; }
		SurvivalStrategy strategy;
		int nutrientRequirement;
		int waterRequirement;
	};
} /* gws */
#endif