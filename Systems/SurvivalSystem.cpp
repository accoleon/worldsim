// SurvivalSystem.cpp
// 
// Cagle, Sam
// University of Oregon
// 2014-05-10

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "SurvivalSystem.h"

namespace gws {
	SurvivalSystem::SurvivalSystem(World& world) : world(world) {

	}
	SurvivalSystem::~SurvivalSystem() {}
	void SurvivalSystem::Update() {
	}
	string SurvivalSystem::getName() {
		return "SurvivalSystem";
	}
} /* gws */