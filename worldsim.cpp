// worldsim.cpp
// worldsim main simulation file - loads world and objects
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-16

#include <cilk/cilk.h>
#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <SDL2/SDL.h>

#include "Components/Component.h"
#include "Components/NutrientComponent.h"
#include "Components/PositionComponent.h"
#include "units.h"
//#include "Systems/NutrientSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/OxygenSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/SurvivalSystem.h"
#include "Systems/SystemManager.h"
#include "Systems/WaterSystem.h"
#include "World.h"

using namespace gws;

const int screenWidth(800);
const int screenHeight(600);
const double FPSLock = 24;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;


void createWindow() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}
	window = SDL_CreateWindow("Genetic World Simulator", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN); 

	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
	/*
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return ;
	}
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, screenWidth, screenHeight); */
}
void destroyWindow() {
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void createEntities(World& world, int num_ents) {
	world.reserve(num_ents*2); /*Find out why it needs *2*/
	cout << "Creating entities...\n";
	// Create random entities;
	int randEntity;
	for (size_t i =0; i < num_ents; ++i) {
		randEntity = rand() % 7;
		switch (randEntity) {
			case 0:
			case 1:
			case 2:
				world.addRandomLake();
				break;
			case 3:
				world.addRandomAnimal();
				break;
			case 4:
			case 5:
			case 6:
				world.addRandomPlant();
				break;
		}
	}

	// Entities should be added to the world here
}

void runWorld(World& world) {
	double frames = 0;
	cout << "Running world...\n";
	// Simulation loop should be here
	bool quit = false;
	SDL_Event event;
	double start = omp_get_wtime();
	while (!quit) {
		while(SDL_PollEvent(&event)) {
			//If the user has Xed out the window
			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)) {
			//Quit the program
				quit = true;
			}
		}
#ifdef FPS_LOCK
		double SPF = 1/FPSLock;
		double start = omp_get_wtime();
		world.runSystems();
		double end = omp_get_wtime();
		double secondsElapsed = end - start;
		double sleepTime = SPF-secondsElapsed;
		if (sleepTime > 0 ) {
			SDL_Delay(sleepTime*1000);
		}
#else 
		world.runSystems();
#endif
		frames++;
		
	}
	double end = omp_get_wtime();
	double time = end - start;
	double FPS = frames / time;
	cout << FPS << " FPS";
}

void teardown()
{
	cout << "Tearing down...\n";
}

int main (int argc, char** argv)
{
	// Initialize SDL and create window
	createWindow();

	// Initialize the world
	int entities = 5000; //Default 1000
	World world(window, screenWidth, screenHeight);
	if(argv[1] != NULL){
		entities = atoi(argv[1]);
	}	
	createEntities(world, entities);
	
	// Run simulation
	runWorld(world);
	
	
	
	// Teardown
	teardown();
	destroyWindow(); // Destroy SDL constructs
	return 0;
}
