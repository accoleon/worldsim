// OffensiveSystem.cpp
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
#include "OffensiveSystem.h"

namespace gws {
	OffensiveSystem::OffensiveSystem(World& world) : world(world) {

	}
	OffensiveSystem::~OffensiveSystem() {}
	void OffensiveSystem::Update() {
	}
	string OffensiveSystem::getName() {
		return "OffensiveSystem";
	}
	int OffensiveSystem::getOffenseStat(int index){
		return offensive_stats[index];
	}
	void OffensiveSystem::setOffenseStat(int index, int set){
		offensive_stats[index] = set;
	}
	int OffensiveSystem::compareOffenses(int former, int latter){
		if(offensive_stats[former] > offensive_stats[latter]){
			return 1;
		}else if (offensive_stats[former] == offensive_stats[latter]){
			return 0;
		}else{
			return -1;
		}
	}
	void OffensiveSystem::reduceOffense(int index, int reduction){
		offensive_stats[index] -= reduction;
	}
	void OffensiveSystem::increaseOffense(int index, int addition){
		offensive_stats[index] += addition;
	}
} /* gws */