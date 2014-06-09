// RenderSystem.h
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#define GLEW_STATIC

#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <omp.h>

#include "System.h"

namespace gws {
	class World;
	class RenderSystem : public System {
	public:
		RenderSystem(World& world, SDL_Window* window);
		~RenderSystem();
		void Display_Init();
		void destroy();
		void update();
		void updateImage(int pArray);
		void updatePixel(int pArray);
		std::string getName();
		SystemType getType();
	private:
		World& world;
		SDL_Window* window;
		GLuint vbo;
		GLuint ebo;
		GLuint tex;
		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;
		int nextPixel;
	};
} /* gws */
#endif
