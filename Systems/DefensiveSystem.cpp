// DefensiveSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-07

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>
#include "DefensiveSystem.h"

namespace gws {
		DefensiveSystem::DefensiveSystem(World& world) : world(world) {
	}
	DefensiveSystem::~DefensiveSystem() {}
	void DefensiveSystem::update() {
	}
	string DefensiveSystem::getName() {
		return "DefensiveSystem";
	}
	int DefensiveSystem::getDefenseStat(int index){
		return defensive_stats[index];
	}
	void DefensiveSystem::setDefenseStat(int index, int set){
		defensive_stats[index] = set;
	}
	int DefensiveSystem::compareDefenses(int former, int latter){
		if(defensive_stats[former] > defensive_stats[latter]){
			return 1;
		}else if (defensive_stats[former] == defensive_stats[latter]){
			return 0;
		}else{
			return -1;
		}
	}
	void DefensiveSystem::reduceDefense(int index, int reduction){
		defensive_stats[index] -= reduction;
	}
	void DefensiveSystem::increaseDefense(int index, int addition){
		defensive_stats[index] += addition;
	}
} /* gws */
