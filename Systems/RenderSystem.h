// RenderSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include "System.h"
#include "../World.h"

namespace gws {
	class RenderSystem : public System {
	public:
		RenderSystem(World& world);
		~RenderSystem();
		void Update();
	private:
		World& world;
	};
} /* gws */
#endif
