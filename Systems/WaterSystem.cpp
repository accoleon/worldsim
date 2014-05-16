// WaterSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <iostream>
using std::cout;
using std::endl;
#include <string>

using std::string;
#include <map>
#include "WaterSystem.h"

namespace gws {
	WaterSystem::WaterSystem(World& world) : world(world) {

	}
	WaterSystem::~WaterSystem() {}
	void WaterSystem::update() {
	}
	string WaterSystem::getName() {
		return "WaterSystem";
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
		water_levels[index] -= reduction;
	}
	void WaterSystem::increaseWater(int index, int addition){
		water_levels[index] += addition;
	}
	
} /* gws */