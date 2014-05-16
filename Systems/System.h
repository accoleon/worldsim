// System.h
// Core system header
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <map>
namespace gws {
	class System {
	public:
		virtual void update() = 0;
		virtual std::string getName() = 0;
	};
} /* gws */
#endif

