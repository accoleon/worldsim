// Component.h
// Component header
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-18

#ifndef COMPONENT_H
#define COMPONENT_H
namespace gws {
	enum ComponentType {
		Nutrient,
		Position,
		Render,
		Water
	};
	
	struct Component {
		virtual ComponentType getType() = 0;
		int ID;
	};
} /* gws */
#endif

