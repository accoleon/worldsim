// RenderSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01
//
// Li, Juston
// University of Oregon
// 2014-05-19
//

#include <cilk/cilk.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "RenderSystem.h"
#include "../World.h"

#define BROWN 	0xFF8B4513
#define CYAN	0xFF00FFFF
#define LIME	0xFF00FF00
#define MAGENTA	0xFFFF00FF


namespace gws {
	const int screenWidth(800);
	const int screenHeight(600);
	GLuint pixelArray[2][screenWidth * screenHeight];
	// Shader sources
	const GLchar* vertexSource =
		"#version 120\n"
		"attribute vec2 position;"
		"attribute vec2 texcoord;"
		"varying vec2 Position;"
		"varying vec2 Texcoord;"
		"void main() {"
		"    Texcoord = texcoord;"
		"    gl_Position = vec4(position, 0.0, 1.0);"
		"}";
	const GLchar* fragmentSource =
		"#version 120\n"
		"varying vec2 Texcoord;"
		"uniform sampler2D tex;"
		"void main() {"
		"    gl_FragColor = texture2D(tex, Texcoord);"
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
		GLsizei length1[100];
		GLchar vertexLog[100];
		glGetShaderInfoLog(vertexShader, 100, length1, vertexLog);
		cout << "VertexShader Log:" << vertexLog << endl;

		// Create and compile the fragment shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);
		GLsizei length2[100];
		GLchar fragmentLog[100];
		glGetShaderInfoLog(fragmentShader, 100, length2, fragmentLog);
		cout << "FragmentShader Log:" << fragmentLog << endl;

		// Link the vertex and fragment shader into a shader program
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		glUseProgram(shaderProgram);

		// Specify the layout of the vertex data
		GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

		GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
		glEnableVertexAttribArray(texAttrib);
		glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

		// Load texture
		glGenTextures(1, &tex);

		//Empty world - brown 
		cilk_for (int i = 0; i < screenWidth * screenHeight; ++i){
			pixelArray[0][i] = BROWN;
			pixelArray[1][i] = BROWN;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, screenWidth, screenHeight, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pixelArray[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		nextPixel = 0;

		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

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
		if(nextPixel == 0) {
			cilk_spawn(updateImage(0));
			updatePixel(1);
		} else {
			cilk_spawn(updateImage(1));
			updatePixel(0);
		}
		nextPixel = (nextPixel + 1) % 2;
	}
	void RenderSystem::updateImage(int pArray) {
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, screenWidth,screenHeight, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pixelArray[pArray]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		SDL_GL_SwapWindow(window);
	}
	void RenderSystem::updatePixel(int pArray) {
		/*Need an empty world to draw updates on*/
		cilk_for (int i = 0; i < screenWidth * screenHeight; ++i){
			pixelArray[pArray][i] = BROWN;
		}
		/*All vectors should be same size*/
		auto end = world.waters.size();
		cilk_for (auto i = 0; i < end; ++i) {
			/*Start colors as light Reducing the a component will make the desired color
			  more apparent, giving a relatively darker color.
			  Use waterLevel,nutrientRequirement and waterRequirement as scale 0-100*/
			if(world.survivors[i].active){
				pixelArray[pArray][world.positions[i].y * screenWidth + world.positions[i].x] =
					MAGENTA - 0x00000001 * world.survivors[i].nutrientSupply * 2.55;
			} else if(world.waters[i].active) {
				pixelArray[pArray][world.positions[i].y * screenWidth + world.positions[i].x] =
					CYAN - 0x00000100 * world.waters[i].waterLevel * 2.55;
			} else if(world.nutrients[i].active) {
				pixelArray[pArray][world.positions[i].y * screenWidth + world.positions[i].x] =
					/*Green scale is halved as we want LIME FF to GREEN 80*/
					LIME - 0x00000100 * world.nutrients[i].nutrientLevel * 1.22;
			}			
		}
	}
	string RenderSystem::getName() {
		return "RenderSystem";
	}
	
	SystemType RenderSystem::getType() {
		return RenderSys;
	}
} /* gws */
