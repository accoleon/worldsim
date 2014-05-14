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

#include "System.h"
#include "../World.h"

namespace gws {
	class RenderSystem : public System {
	public:
		RenderSystem(World& world, SDL_Window* window);
		~RenderSystem();
		void Update();
		void Display_Init();
		void run();
		std::string getName();
	private:
		World& world;
		SDL_Window* window;
		GLuint vbo;
		GLuint ebo;
		GLuint tex;
		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;
	};
} /* gws */
#endif
