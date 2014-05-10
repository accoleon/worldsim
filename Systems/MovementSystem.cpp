// MovementSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "MovementSystem.h"

namespace gws {
	MovementSystem::MovementSystem(World& world) : world(world) {

	}
	MovementSystem::~MovementSystem() {}
	void MovementSystem::Update() {
	}
	string MovementSystem::getName() {
		return "MovementSystem";
	}
	int MovementSystem::getMovement(int index){
		return movement_stats[index];
	}
	void MovementSystem::setMovement(int index, int set){
		movement_stats[index] = set;
	}
	int MovementSystem::compareMovements(int former, int latter){
		if(movement_stats[former] > movement_stats[latter]){
			return 1;
		}else if (movement_stats[former] == movement_stats[latter]){
			return 0;
		}else{
			return -1;
		}
	}
	void MovementSystem::reduceMovement(int index, int reduction){
		movement_stats[index] -= reduction;
	}
	void MovementSystem::increaseMovement(int index, int addition){
		movement_stats[index] += addition;
	}	
} /* gws */