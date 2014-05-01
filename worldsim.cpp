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

const int screenWidth(640);
const int screenHeight(480);
SDL_Window* window;

void createWindow() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}
	window = SDL_CreateWindow("Hello World!", 0, 0, screenWidth, screenHeight,
		SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
	/*
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
*/
}
void destroyWindow() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void createUnits(World& world) {
	cout << "Creating units...\n";
	EntityManager entityManager(world);
	// Create a pond;
	Entity pond;
	PositionComponent position(1,1);
	WaterComponent water(10);
	pond.addComponent(position);
	pond.addComponent(water);
	entityManager.addEntity(pond);
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
	// Initialize SDL and create window
	createWindow();

	// Initialize the world
	World world;
	
	// Add rendering
	RenderSystem renderSystem(world, window);
	world.addSystem(renderSystem);
	
	// Add some water
	WaterSystem waterSystem(world);
	world.addSystem(waterSystem);
	
	// create units
	createUnits(world);
	// run world
	runWorld();
	// teardown
	teardown();
	destroyWindow();
	return 0;
}