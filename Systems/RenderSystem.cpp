// RenderSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#include <iostream>
using std::cout;

#include "RenderSystem.h"

namespace gws {
	RenderSystem::RenderSystem(World& world, SDL_Window* window) : world(world), window(window) {
		cout << "RenderSystem attached to world\n";
	}
	RenderSystem::~RenderSystem() {}
	void RenderSystem::Update() {}
} /* gws */