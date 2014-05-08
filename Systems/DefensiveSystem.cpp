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
#include "DefensiveSystem.h"

namespace gws {
		DefensiveSystem::DefensiveSystem(World& world) : world(world) {

	}
	DefensiveSystem::~DefensiveSystem() {}
	void DefensiveSystem::Update() {
	}
	string DefensiveSystem::getName() {
		return "DefensiveSystem";
	}
} /* gws */
