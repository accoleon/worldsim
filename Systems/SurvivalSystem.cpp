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
		//Main AI controller for how each Entity will move throughout the World
		auto end = world.survivors.size();
		cilk_for(auto i = 0; i < end; ++i){
			auto end = world.waters.size();
			if(world.survivors[i].active) {
				for(auto j = 0; j < end; ++j){
					if( i == j){
						/*Don't eat yourself..*/
						continue;
					}
					if(world.positions[i].y == world.positions[j].y && world.positions[i].x == world.positions[j].x){
						if(world.waters[j].active){
							world.survivors[i].waterSupply += world.waters[j].waterLevel;
							if(world.survivors[i].waterSupply > world.survivors[i].maxLev) {
								world.waters[j].waterLevel = world.survivors[i].waterSupply - world.survivors[i].maxLev;
								world.survivors[i].waterSupply = world.survivors[i].maxLev;
							} else {
								world.waters[j].waterLevel = 0;
							}
						}
						/*All herivores for now*/
						if(world.nutrients[j].active && !world.survivors[j].active) {
							world.survivors[i].nutrientSupply += world.nutrients[j].nutrientLevel;
							if(world.survivors[i].nutrientSupply > world.survivors[i].maxLev) {
								world.nutrients[j].nutrientLevel = world.survivors[i].nutrientSupply - world.survivors[i].maxLev;
								world.survivors[i].nutrientSupply = world.survivors[i].maxLev;
							} else {
								world.nutrients[j].nutrientLevel = 0;
							}
						}
					}
				}
				//world.survivors[i].waterSupply -= world.survivors[i].nutrientRequirement;
				//world.survivors[i].nutrientSupply -= world.survivors[i].waterRequirement;
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
