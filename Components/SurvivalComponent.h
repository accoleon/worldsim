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
		const static int minReq= 1;
		const static int maxReq = 10;
		const static int minLev = 1;
		const static int maxLev = 100;
		SurvivalComponent(SurvivalStrategy strat, int nutrientRequirement, int waterRequirement, int nutrientSupply, int waterSupply) : 
			strategy(strat), nutrientRequirement(nutrientRequirement), waterRequirement(waterRequirement), 
			nutrientSupply(nutrientSupply), waterSupply(waterSupply) {
			active = true;
		}
		SurvivalComponent(bool isActive) {
			if(isActive) {
				active = true;
				strategy = SurvivalStrategy(rand() % 7);
				nutrientRequirement = rand() % maxReq + minReq;
				waterRequirement = rand() % maxReq + minReq;
				nutrientSupply= rand() % maxLev + minLev;
				waterSupply = rand() % maxLev + minLev;
			} else {
				active = false;
			}
		}
		ComponentType getType() { return Survival; }
		SurvivalStrategy strategy;
		int nutrientRequirement;
		int waterRequirement;
		int nutrientSupply;
		int waterSupply;
	};
} /* gws */
#endif
