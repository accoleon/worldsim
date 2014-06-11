// WaterSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <cilk/cilk.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>

using std::string;
#include <map>
#include "WaterSystem.h"
#include "../World.h"

namespace gws {
	WaterSystem::WaterSystem(World& world) : world(world) {

	}
	WaterSystem::~WaterSystem() {}
	void WaterSystem::update() {
		/* Update changes made by other systems */
		for (std::map<int, int>::iterator it = water_levels.begin(); it != water_levels.end(); ++it) {
			world.waters[it->first].waterLevel = water_levels[it->second];
		}
		auto end = world.waters.size();
		cilk_for (auto i = 0; i < end; ++i) {
			if(world.waters[i].active) {
				/*Increment all waters*/
				world.waters[i].waterLevel++;
				/*Cap water levels*/
				if(world.waters[i].waterLevel > world.waters[i].max) {
					world.waters[i].waterLevel = world.waters[i].max;
				}
			}
		}
		water_levels.clear();
	}
	string WaterSystem::getName() {
		return "WaterSystem";
	}
	SystemType WaterSystem::getType() {
		return WaterSys;
	}
	int WaterSystem::getWater(int index){
		return water_levels[index];
	}
	void WaterSystem::setWater(int index, int set){
		water_levels[index] = set;
	}
	int WaterSystem::compareWater(int former, int latter){
		if(water_levels[former] > water_levels[latter]){
			return 1;
		}else if (water_levels[former] == water_levels[latter]){
			return 0;
		}else{
			return -1;
		}
	}
	void WaterSystem::reduceWater(int index, int reduction){
		water_levels[index] = world.waters[index].waterLevel - reduction;
	}
	void WaterSystem::increaseWater(int index, int addition){
		water_levels[index] = world.waters[index].waterLevel + addition;
	}
	
} /* gws */
