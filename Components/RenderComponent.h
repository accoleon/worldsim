// RenderComponent.h
// RenderComponent header
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18

#include "Component.h"
#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H
namespace gws {
	struct RenderComponent : gws::Component {
		RenderComponent() : visible(true) {}
		bool visible;
	};
} /* gws */
#endif

