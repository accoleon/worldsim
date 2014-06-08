// MovementSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <cilk/cilk.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "MovementSystem.h"
#include "../World.h"

namespace gws {
	MovementSystem::MovementSystem(World& world) : world(world) {

	}
	MovementSystem::~MovementSystem() {}
	void MovementSystem::update() {
		int targetX ;
		int targetY;
		auto end = world.survivors.size();
		cilk_for (auto i = 0; i < end; ++i) {
			targetX = world.positions[i].x;
			targetY = world.positions[i].y;
			if (world.survivors[i].active) {
				switch(world.survivors[i].strategy) {
					case EXPLORE:
						break;
					case STATIONARY:
						break;
					case BREED:
						break;
					case NORTH:
						targetY--;
						break;
					case EAST:
						targetX++;
						break;
					case SOUTH:
						targetY++;
						break;
					case WEST:
						targetX--;
						break;
				}
				if (targetX < 800 && targetX >= 0) {
					world.positions[i].x = targetX;
				}
				if (targetY < 600 && targetY >= 0) {
					world.positions[i].y = targetY;
				}
			}
		}
	}
	string MovementSystem::getName() {
		return "MovementSystem";
	}
	SystemType MovementSystem::getType() {
		return RenderSys;
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
