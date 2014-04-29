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
#include <SDL.h>

#include "units.hpp"
using namespace gensim;

units world;

// Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void createUnits() {
	cout << "Creating units...\n";
	// Create a basic plant;
	
}

void runWorld() {
	cout << "Running world...\n";
}

void teardown()
{
	cout << "Tearing down...\n";
}

int main (int, char**)
{
	// Setup Window
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		// Create Window
		window = SDL_CreateWindow("WorldSim",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL){
			printf("Cannot create window: SDL_Error: %s\n", SDL_GetError());
		} else {
			screenSurface = SDL_GetWindowSurface(window);
			// Fill white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			// Update surface
			SDL_UpdateWindowSurface(window);
			
		}
	}
	// create units
	createUnits();
	// run world
	runWorld();
	// teardown
	teardown();
	// Wait
	SDL_Delay(2000);
	// Destroy Window
	SDL_DestroyWindow(window);
	// Exit SDL Subsystem
	SDL_Quit();
	
	return 0;
}