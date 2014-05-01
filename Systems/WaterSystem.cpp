// WaterSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include <iostream>
using std::cout;
#include "WaterSystem.h"

namespace gws {
	WaterSystem::WaterSystem(World& world) : world(world) {
		cout << "WaterSystem attached to world\n";
	}
	WaterSystem::~WaterSystem() {}
	void WaterSystem::Update() {
		for(auto wc : world.waters) {
			cout << "a block of water here\n";
		}
	}
} /* gws */