// PositionComponent.h
// PositionComponent header
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#include "Component.h"
#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H
namespace gws {
	struct PositionComponent : Component {
		PositionComponent(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
} /* gws */
#endif
