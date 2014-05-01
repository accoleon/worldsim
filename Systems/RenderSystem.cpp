// RenderSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include "RenderSystem.h"

namespace gws {
	RenderSystem::RenderSystem(World& world, SDL_Window* window) : world(world), window(window) {
		
	}
	RenderSystem::~RenderSystem() {}
	void RenderSystem::Update() {}
	string RenderSystem::getName() {
		return "RenderSystem";
	}
} /* gws */