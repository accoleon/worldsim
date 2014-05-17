// RenderSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01

#include <cilk/cilk.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "RenderSystem.h"

namespace gws {
	const int screenWidth(800);
	const int screenHeight(600);
	float pixelArray[screenWidth * screenHeight * 3];
	// Shader sources
	const GLchar* vertexSource =
		"#version 150 core\n"
		"in vec2 position;"
		"in vec3 color;"
		"in vec2 texcoord;"
		"out vec3 Color;"
		"out vec2 Texcoord;"
		"void main() {"
		"   Color = color;"
		"   Texcoord = texcoord;"
		"   gl_Position = vec4(position, 0.0, 1.0);"
		"}";
	const GLchar* fragmentSource =
		"#version 150 core\n"
		"in vec3 Color;"
		"in vec2 Texcoord;"
		"out vec4 outColor;"
		"uniform sampler2D tex;"
		"void main() {"
		"   outColor = texture(tex, Texcoord);"
		"}";

	RenderSystem::RenderSystem(World& world, SDL_Window* window) : world(world), window(window) {
		SDL_Init(SDL_INIT_VIDEO);
		//SDL_QueryTexture(texture, NULL, NULL, &screenWidth, &screenHeight);
		SDL_GL_CreateContext(window);
		glewExperimental = GL_TRUE;
		glewInit();
		Display_Init();
	}
	RenderSystem::~RenderSystem() {}
 
	void RenderSystem::Display_Init() {

		// Create a Vertex Buffer Object and copy the vertex data to it
		glGenBuffers(1, &vbo);

		GLfloat vertices[] = {
		//  Position   Color Texcoords
			-1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
			1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
			1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
			-1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
		};

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Create an element array
		glGenBuffers(1, &ebo);

		GLuint elements[] = {
			0, 1, 2,
			2, 3, 0
		};

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

		// Create and compile the vertex shader
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		// Create and compile the fragment shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		// Link the vertex and fragment shader into a shader program
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glBindFragDataLocation(shaderProgram, 0, "outColor");
		glLinkProgram(shaderProgram);
		glUseProgram(shaderProgram);

		// Specify the layout of the vertex data
		GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

		GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
		glEnableVertexAttribArray(colAttrib);
		glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

		GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
		glEnableVertexAttribArray(texAttrib);
		glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

		// Load texture
		glGenTextures(1, &tex);

		//Empty world - brown
		for (int i = 0; i < screenWidth * screenHeight * 3; i+=3){
			pixelArray[i] = 0.5f;
			pixelArray[i+1] = 0.35f;
			pixelArray[i+2] = 0.05f;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, screenWidth, screenHeight, 0, GL_RGB, GL_FLOAT, pixelArray);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw a rectangle from the 2 triangles using 6 indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap buffers
		SDL_GL_SwapWindow(window);
		
	}

	void RenderSystem::destroy(){
		glDeleteTextures(1, &tex);

		glDeleteProgram(shaderProgram);
		glDeleteShader(fragmentShader);
		glDeleteShader(vertexShader);

		glDeleteBuffers(1, &ebo);
		glDeleteBuffers(1, &vbo);
	}

	void RenderSystem::update() {
		//cout << "Updating\n";
		cilk_for (auto water = world.waters.cbegin(); water != world.waters.cend(); ++water) {
			for (auto position : world.positions) {
				if ((*water)->ID == position->ID) {
					//cout << "drawing x: " << position->x << " y: " << position->y << " level: " << water->waterLevel << "\r";
					pixelArray[position->y * screenWidth * 3 + position->x *3] = 0.0f;
					pixelArray[position->y * screenWidth * 3 + position->x *3 + 1] = 0.0f;
					pixelArray[position->y * screenWidth * 3 + position->x *3 + 2] = 1.0f;
				}
			}
		}
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, screenWidth,screenHeight, GL_RGB, GL_FLOAT, pixelArray);
		// Draw a rectangle from the 2 triangles using 6 indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		SDL_GL_SwapWindow(window);
	}
	string RenderSystem::getName() {
		return "RenderSystem";
	}
} /* gws */
