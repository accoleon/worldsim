// OxygenSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "OxygenSystem.h"

namespace gws {
	OxygenSystem::OxygenSystem(World& world) : world(world) {

	}
	OxygenSystem::~OxygenSystem() {}
	void OxygenSystem::Update() {
	}
	string OxygenSystem::getName() {
		return "OxygenSystem";
	}
} /* gws */