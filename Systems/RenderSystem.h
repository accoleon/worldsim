// RenderSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include <SDL2/SDL.h>

#include "System.h"
#include "../World.h"

namespace gws {
	class RenderSystem : public System {
	public:
		RenderSystem(World& world, SDL_Window* window);
		~RenderSystem();
		void Update();
	private:
		World& world;
		SDL_Window* window;
	};
} /* gws */
#endif
