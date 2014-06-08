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
		const static int min = 0;
		const static int max = 100;
		SurvivalComponent(SurvivalStrategy strat, int nutrientRequirement, int waterRequirement) : 
			strategy(strat), nutrientRequirement(nutrientRequirement),waterRequirement(waterRequirement) {
			active = true;
		}
		SurvivalComponent(bool isActive) {
			if(isActive) {
				active = true;
				strategy = SurvivalStrategy(rand() % 7);
				nutrientRequirement = rand() % max + min;
				waterRequirement =rand() % max + min;
			} else {
				active = false;
			}
		}
		ComponentType getType() { return Survival; }
		SurvivalStrategy strategy;
		int nutrientRequirement;
		int waterRequirement;
	};
} /* gws */
#endif
