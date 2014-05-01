// world.h
// World object header file
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef WORLD_H
#define WORLD_H
#include <vector>

#include "tbb/concurrent_vector.h"

#include "Components/PositionComponent.h"
#include "Components/WaterComponent.h"
#include "Components/RenderComponent.h"
#include "Systems/System.h"

// 2D world, maybe add the third z dimension later
// width/height refers to the size of the world being simulated, but
// also the width/height of the window of the visualization - tie the 2 
// together

namespace gws {
	const int default_width(640);
	const int default_height(480);
	class World {
	public:
		World(int width = default_width, int height = default_height);
		~World();
		std::vector<System*> systems;
		tbb::concurrent_vector<PositionComponent> positions;
		tbb::concurrent_vector<WaterComponent> waters;
		tbb::concurrent_vector<RenderComponent> renders;
	private:
		int width;
		int height;
	};
} /* gws */
#endif
