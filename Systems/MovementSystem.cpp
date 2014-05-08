// MovementSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

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
} /* gws */