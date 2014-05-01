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
	SDL_Window *win = SDL_CreateWindow("Hello World!", 0, 0, -1, -1,
		SDL_WINDOW_FULLSCREEN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return ;
	}
	SDL_Surface *bmp = SDL_LoadBMP("osnap_logo.bmp");
	if (bmp == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return;
	}
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: "
			<< SDL_GetError() << std::endl;
		return;
	}
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);
	
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
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