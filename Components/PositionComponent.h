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
		int ID;
		const static int minX = 0;
		const static int minY = 0;
		const static int maxX = 800;
		const static int maxY = 600; // have to find some way to link this with screenWidth/height
		PositionComponent(int x, int y) : x(x), y(y) {
			active = true;
		}
		PositionComponent(bool isActive) {
			if(isActive) {
				active = true;
				x = rand() % maxX + minX;
				y = rand() % maxY + minY;
			} else {
				active = false;
			}
		}
	};
} /* gws */
#endif
