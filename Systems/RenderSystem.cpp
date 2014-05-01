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
	RenderSystem::RenderSystem(World& world, SDL_Window* window) : world(world), window(window) {
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr){
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			return ;
		}
	  SDL_Texture * texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
	  Uint32 * pixels = new Uint32[640 * 480];
	  memset(pixels, 255, 640 * 480 * sizeof(Uint32));
		bool leftMouseButtonDown = false;
	  bool quit = false;
	  SDL_Event event;
	  while (!quit)
	  {
	      SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
	      SDL_WaitEvent(&event);

	      switch (event.type)
	      {
	      case SDL_QUIT:
	          quit = true;
	          break;
	      }
				for (size_t i = 0; i < 50; ++i) {
					int randomX = rand() % 640;
					int randomY = rand() % 480;
					pixels[randomY * 640 + randomX] = rand() % 255;
				}
				
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