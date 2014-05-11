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
#include "Systems/NutrientSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/OxygenSystem.h"
#include "Systems/SurvivalSystem.h"
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
	window = SDL_CreateWindow("Genetic World Simulator", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		0, 0,
		SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
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
	NutrientComponent nutrient(10);
	pond.addComponent(position);
	pond.addComponent(nutrient);
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
	NutrientSystem nutrientSystem(world);
	world.addSystem(nutrientSystem);
	
	// create units
	createUnits(world);
	// run world
	runWorld();
	// teardown
	teardown();
	destroyWindow();
	return 0;
}
