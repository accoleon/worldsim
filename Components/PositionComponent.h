// PositionComponent.h
// PositionComponent header
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H
#include <cstdlib>

#include "Component.h"
namespace gws {
	struct PositionComponent : gws::Component {
		int x;
		int y;
		const int minX = 0;
		const int minY = 0;
		const int maxX = 800;
		const int maxY = 600; // have to find some way to link this with screenWidth/height
		PositionComponent(int x, int y) : x(x), y(y) {
			active = true;
		}
		PositionComponent() : PositionComponent(rand() % maxX + minX, rand() % maxY + minY) {
		}
	};
} /* gws */
#endif
