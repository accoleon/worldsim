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
#include "Components/NutrientComponent.h"
#include "Components/RenderComponent.h"
#include "Components/WaterComponent.h"
#include "Components/SurvivalComponent.h"
#include "Systems/System.h"

// 2D world, maybe add the third z dimension later
// width/height refers to the size of the world being simulated, but
// also the width/height of the window of the visualization - tie the 2 
// together

namespace gws {
	class World {
	public:
		const static int default_width = 640;
		const static int default_height = 480;
		World(int width = default_width, int height = default_height);
		~World();
		int nextEntityID = 0;
		// We might not need concurrent_vectors since we try to make sure
		// there is no multithreaded writing to them. Performance-wise 
		// concurrent vectors are slower than contiguous STL vectors
		std::vector<System*> systems;
		//std::vector<Entity> entities;
		//tbb::concurrent_vector<PositionComponent*> positions;
		std::vector<PositionComponent> positions;
		// Especially when we use polymorphism - the objects are not in contiguous memory at all!
		tbb::concurrent_vector<Component*> nutrients;
		tbb::concurrent_vector<Component*> renders;
		//tbb::concurrent_vector<WaterComponent*> waters;
		std::vector<WaterComponent> waters;
		tbb::concurrent_vector<SurvivalComponent*> survivors;
		
		int width;
		int height;
		
		int addEntity();
		int addRandomLake();
		int addRandomPlant();
		void addSystem(System& system);
		void runSystems();		
	private:
	};
} /* gws */
#endif
