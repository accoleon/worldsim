// worldsim.cpp
// worldsim main simulation file - loads world and objects
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-16

#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <SDL2/SDL.h>

#include "Entity.h"
#include "EntityManager.h"
#include "units.h"
#include "Systems/RenderSystem.h"
#include "Systems/SystemManager.h"
#include "Systems/WaterSystem.h"
#include "World.h"
using namespace gws;

units world;

void setupGraphics() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}
	SDL_Window *window = SDL_CreateWindow("Hello World!", 0, 0, -1, -1,
		SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return ;
	}
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	cout << "current w: " << current.w << " current h: " << current.h << endl;
  SDL_Texture * texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, current.w, current.h);
  Uint32 * pixels = new Uint32[current.w * current.h];
  memset(pixels, 255, current.w * current.h * sizeof(Uint32));
	bool leftMouseButtonDown = false;
  bool quit = false;
  SDL_Event event;
  while (!quit)
  {
      SDL_UpdateTexture(texture, NULL, pixels, current.w * sizeof(Uint32));
      SDL_WaitEvent(&event);

      switch (event.type)
      {
      case SDL_MOUSEBUTTONUP:
          if (event.button.button == SDL_BUTTON_LEFT)
              leftMouseButtonDown = false;
          break;
      case SDL_MOUSEBUTTONDOWN:
          if (event.button.button == SDL_BUTTON_LEFT)
              leftMouseButtonDown = true;
      case SDL_MOUSEMOTION:
          if (leftMouseButtonDown)
          {
              int mouseX = event.motion.x;
              int mouseY = event.motion.y;
              pixels[mouseY * current.w + mouseX] = 0;
          }
          break;
      case SDL_QUIT:
          quit = true;
          break;
      }

      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
  }

  delete[] pixels;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
void teardownGraphics() {

}

void createUnits(World& world) {
	cout << "Creating units...\n";
	// Create a basic plant;
	// Entities should be added to the world here
}

void runWorld() {
	cout << "Running world...\n";
	// Simulation loop should be here
	
	// Run Systems
}

void teardown()
{
	cout << "Tearing down...\n";
}

int main (int, char**)
{
	setupGraphics();
	EntityManager man;
	Entity ents;
	// Initialize the world
	World world;
	// Add some water
	WaterSystem waterSystem(world);
	// Add rendering
	RenderSystem renderSystem(world);
	// create units
	createUnits(world);
	// run world
	runWorld();
	// teardown
	teardown();
	teardownGraphics();
	return 0;
}