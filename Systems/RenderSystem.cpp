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
	RenderSystem::RenderSystem(World& world, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) : 
	world(world),
	window(window),
	renderer(renderer),
	texture(texture) {
		// Most of the code below should be moved into functions
		// KX: Actually I think most of these initialization stuff should be done in
		// the main game loop in worldsim.cpp, then this system focuses solely on 
		// updating the pixel map
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
		format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888);
	  pixels = new Uint32[width * height];
	  //memset(pixels, 100, width * height * sizeof(Uint32));
	}
	RenderSystem::~RenderSystem() {
		//SDL_FreeFormat(format);
		//delete pixels;
	}
	void RenderSystem::update() {
		// is renderComponent redundant? should we combine rendercomponent and
		// positioncomponent?
		// Render all waters in the world
		cilk_for (auto water = world.waters.cbegin(); water != world.waters.cend(); ++water) {
			for (auto position : world.positions) {
				if ((*water)->ID == position->ID) {
					//cout << "drawing x: " << position->x << " y: " << position->y << " level: " << water->waterLevel << "\r";
					pixels[position->y * width + position->x] = SDL_MapRGBA(format, 0, 0, (*water)->waterLevel, 255);
				}
			}
		}
		/*for (auto water : world.waters) {
			for (auto position : world.positions) {
				if (water->ID == position->ID) {
					//cout << "drawing x: " << position->x << " y: " << position->y << " level: " << water->waterLevel << "\r";
					pixels[position->y * width + position->x] = SDL_MapRGBA(format, 0, 0, water->waterLevel, 255);
				}
			}
		}*/
		/*for (size_t i = 0; i < width; ++i) {
			for (size_t j = 0; j < height; ++j) {
				pixels[j * width + i] = rand() % 294967295;
			}
		}*/
		SDL_UpdateTexture(texture, NULL, pixels, width * sizeof(Uint32));			
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
	}
	string RenderSystem::getName() {
		return "RenderSystem";
	}
} /* gws */