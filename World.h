// world.h
// World object header file
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef WORLD_H
#define WORLD_H

#include "tbb/concurrent_vector.h"

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
		tbb::concurrent_vector<int> x;
		tbb::concurrent_vector<int> y;
	
	private:
		int width;
		int height;
	};
} /* gws */
#endif
