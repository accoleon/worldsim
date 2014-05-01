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
#include "WaterSystem.h"

namespace gws {
	WaterSystem::WaterSystem(World& world) : world(world) {

	}
	WaterSystem::~WaterSystem() {}
	void WaterSystem::Update() {
	}
	string WaterSystem::getName() {
		return "WaterSystem";
	}
} /* gws */