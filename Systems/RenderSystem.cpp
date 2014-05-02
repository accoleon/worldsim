// RenderSystem.cpp
// 
// Xu Junjie, Kevin
// University of Oregon
// 2014-05-01
#include <cstdlib>
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include "RenderSystem.h"

namespace gws {
	const int width(800);
	const int height(600);
	RenderSystem::RenderSystem(World& world, SDL_Window* window) : world(world), window(window) {
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr){
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			return ;
		}
	  SDL_Texture * texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	  Uint32 * pixels = new Uint32[width * height];
	  memset(pixels, 255, width * height * sizeof(Uint32));
		cout << pixels[0];
	  bool quit = false;
	  SDL_Event event;

	  while (!quit) {
			while(SDL_PollEvent(&event)) {
        //If the user has Xed out the window
        if( event.type == SDL_QUIT )
        {
            //Quit the program
            quit = true;
        }
			}
			for (size_t i = 0; i < width; ++i) {
				for (size_t j = 0; j < height; ++j) {
					pixels[j * width + i] = rand() % 294967295;
				}
			}
			SDL_UpdateTexture(texture, NULL, pixels, width * sizeof(Uint32));			
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
	  }
	}
	RenderSystem::~RenderSystem() {}
	void RenderSystem::Update() {}
	string RenderSystem::getName() {
		return "RenderSystem";
	}
} /* gws */