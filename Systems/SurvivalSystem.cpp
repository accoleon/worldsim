// SurvivalSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <cilk/cilk.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <stdlib.h>
#include <time.h>
using std::string;
#include "SurvivalSystem.h"
#include "../World.h"

namespace gws {
	SurvivalSystem::SurvivalSystem(World& world) : world(world) {}
	SurvivalSystem::~SurvivalSystem() {}
	void SurvivalSystem::update() {
		/* 
		 * Refactor, very inefficient. maybe use a map like other systems 
		 * to store a copy of all positions in 1 iteration.
		 */
		auto end1 = world.survivors.size();
		cilk_for(auto i = 0; i < end1; ++i){
			auto end2 = world.waters.size();
			if(world.survivors[i].active) {
				for(auto j = 0; j < end2; ++j){
					if( i == j){
						/* Don't eat yourself.. */
						continue;
					}
					if(world.positions[i].y == world.positions[j].y && world.positions[i].x == world.positions[j].x){
						if(world.waters[j].active){
							int tempWaterSupply = world.survivors[i].waterSupply + world.waters[j].waterLevel;
							if(tempWaterSupply > world.survivors[i].maxLev) {
								world.waterSystem.setWater(j, tempWaterSupply - world.survivors[i].maxLev);
								world.survivors[i].waterSupply = world.survivors[i].maxLev;
							} else {
								world.waterSystem.setWater(j, 0);
								world.survivors[i].waterSupply = tempWaterSupply;
							}
						}
						/* All herivores for now */
						if(world.nutrients[j].active && !world.survivors[j].active) {
							int tempNutrientSupply = world.survivors[i].nutrientSupply + world.nutrients[j].nutrientLevel;
							if(tempNutrientSupply > world.survivors[i].maxLev) {
								world.nutrientSystem.setNutrient(j, tempNutrientSupply - world.survivors[i].maxLev);
								world.survivors[i].nutrientSupply = world.survivors[i].maxLev;
							} else {
								world.nutrientSystem.setNutrient(j, 0);
								world.survivors[i].nutrientSupply = tempNutrientSupply;
							}
						}
					}
				}
				world.survivors[i].waterSupply -= world.survivors[i].nutrientRequirement;
				world.survivors[i].nutrientSupply -= world.survivors[i].waterRequirement;
				if(world.survivors[i].waterSupply <= 0 || world.survivors[i].nutrientSupply <= 0 ){
					world.survivors[i].active = false;
					world.positions[i].active = false;
					world.nutrients[i].active = false;
				}
			}
		}

	}

	string SurvivalSystem::getName() {
		return "SurvivalSystem";
	}
	SystemType SurvivalSystem::getType() {
		return SurvivalSys;
	}
	void SurvivalSystem::setSurvivalType(int index, SurvivalStrategy new_type){
		survival_types[index] = new_type;
	}
	string SurvivalSystem::getSurvivalType(int index){
		SurvivalStrategy stype = survival_types[index];
		switch(stype){
			case EXPLORE:
				return "EXPLORE";
			case STATIONARY:
				return "STATIONARY";
			case NORTH:
				return "NORTH";
			case EAST:
				return "EAST";
			case SOUTH:
				return "SOUTH";
			case WEST:
				return "WEST";
		}
		return "ERROR: no type for given index specified";
	}
} /* gws */
