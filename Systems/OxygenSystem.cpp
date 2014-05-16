// OxygenSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <map>
using std::string;
#include "OxygenSystem.h"

namespace gws {
	OxygenSystem::OxygenSystem(World& world) : world(world) {

	}
	OxygenSystem::~OxygenSystem() {}
	void OxygenSystem::update() {
	}
	string OxygenSystem::getName() {
		return "OxygenSystem";
	}
	int OxygenSystem::getOxygen(int index){
		return oxygen_levels[index];
	}
	void OxygenSystem::setOxygen(int index, int set){
		oxygen_levels[index] = set;
	}
	int OxygenSystem::compareOxygen(int former, int latter){
		if(oxygen_levels[former] > oxygen_levels[latter]){
			return 1;
		}else if (oxygen_levels[former] == oxygen_levels[latter]){
			return 0;
		}else{
			return -1;
		}
	}
	void OxygenSystem::reduceOxygen(int index, int reduction){
		oxygen_levels[index] -= reduction;
	}
	void OxygenSystem::increaseOxygen(int index, int addition){
		oxygen_levels[index] += addition;
	}
} /* gws */