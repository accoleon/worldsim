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

#include "Components/Component.h"
#include "Components/NutrientComponent.h"
#include "Components/PositionComponent.h"
#include "Entity.h"
#include "EntityManager.h"
#include "units.h"
#include "Systems/NutrientSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/OxygenSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/SurvivalSystem.h"
#include "Systems/SystemManager.h"
#include "Systems/WaterSystem.h"
#include "World.h"
using namespace gws;

const int screenWidth(640);
const int screenHeight(480);
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;
World world;

void createWindow() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}
	window = SDL_CreateWindow("Genetic World Simulator", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		0, 0,
		SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return ;
	}
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, screenWidth, screenHeight);
}
void destroyWindow() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void createEntities() {
	cout << "Creating entities...\n";
	EntityManager entityManager(world);
	// Create 1000 random lakes;
	for (size_t i = 0; i < 1000; ++i) {
		entityManager.addRandomLake();
		cout << "Lake " << i << " added\n";
	}
	// Entities should be added to the world here
}

void addSystems() {
	NutrientSystem nutrientSystem(world);
	world.addSystem(nutrientSystem);
	
	WaterSystem waterSystem(world);
	world.addSystem(waterSystem);
	
	// Add rendering
	RenderSystem renderSystem(world, window, renderer, texture);
	world.addSystem(renderSystem);
}

void runWorld() {
	cout << "Running world...\n";
	// Simulation loop should be here
  bool quit = false;
  SDL_Event event;
  while (!quit) {
		while(SDL_PollEvent(&event)) {
      //If the user has Xed out the window
      if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)) {
          //Quit the program
          quit = true;
      }
		}
		world.runSystems();
  }
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
	createEntities();
	addSystems();
	
	// Run simulation
	runWorld();
	
	// Teardown
	teardown();
	destroyWindow(); // Destroy SDL constructs
	return 0;
}
