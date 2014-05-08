// OffensiveSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <iostream>
using std::cout;
using std::endl;
#include <string>
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
} /* gws */