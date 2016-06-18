//
//  sdl_renderer.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

// CPP
#include <iostream>

// SDL2
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

// LOCAL
#include "sdl_renderer.hpp"
#include "game_env.hpp"


const int WINDOW_X = 200;
const int WINDOW_Y = 200;


SDLRenderer::SDLRenderer()
{
	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		std::cerr << "SDL2 Initialization failed: " << SDL_GetError() << std::endl;
		throw "Failed";
	}else
	{
		std::cout << "SDL2 Initialization succeeded" << std::endl;
	}
	window_ = SDL_CreateWindow( "T-Rex Runner", WINDOW_X, WINDOW_Y,
														 GameParam::kSceneWidth, GameParam::kSceneHeight, SDL_WINDOW_SHOWN );
	if (window_ == NULL)
	{
		std::cerr << "SDL2 Window Initialization failed: " << SDL_GetError() << std::endl;
		throw "Failed";
	}else
	{
		std::cout << "SDL2 Window Initialization succeeded" << std::endl;
	}
	
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED & SDL_RENDERER_PRESENTVSYNC);
	if (renderer_ == NULL)
	{
		std::cerr << "SDL2 Renderer Initialization failed: " << SDL_GetError() << std::endl;
		throw "Failed";
	}else
	{
		std::cout << "SDL2 Renderer Initialization succeeded" << std::endl;
	}
	SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
	
	int img_flags = IMG_INIT_PNG;
	if(!(IMG_Init(img_flags)&img_flags))
	{
		std::cerr << "SDL2 Image System Initialization failed: "<< IMG_GetError() << std::endl;
		throw "Failed";
	}else
	{
		std::cout << "SDL2 Image System Initialization succeeded" << std::endl;
	}
}


SDLRenderer::~SDLRenderer()
{
	DestroyTextures();
	
	//Destroy window
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	window_ = NULL;
	renderer_ = NULL;
	
	IMG_Quit();
	SDL_Quit();
}



void SDLRenderer::Init()
{
	for (int i=0; i != TRex::LAST; i++)
	{
		SDL_Texture* texture = LoadTexture(GAME_OBJECT_IMAGE[i]);
		textures_.push_back(texture);
		int width = 0, height = 0;
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
		SDL_Rect size;
		size.h = height;
		size.w = width;
		texture_sizes_.push_back(size);
	}
}


void SDLRenderer::DestroyTextures()
{
	while (!textures_.empty())
	{
		SDL_Texture* texture = textures_.back();
		textures_.pop_back();
		SDL_DestroyTexture(texture);
	}
}


void SDLRenderer::Clear()
{
	SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer_);
}

void SDLRenderer::Present()
{
	SDL_RenderPresent(renderer_);
}




void SDLRenderer::Render(const TRex::Object& obj, const GameShape* src, const GameShape* dest)
{
	// std::cout << "Given " << obj << " rendered at " << dest->x << " " << dest->y << " w: " << src->w << " h: " << src->h;
	
	SDL_RenderCopy(renderer_, textures_[obj],
								 reinterpret_cast<const SDL_Rect*>(src),
								 reinterpret_cast<const SDL_Rect*>(dest));
}


void SDLRenderer::Render(const TRex::Object& obj, const int x, const int y, const int w, const int h)
{

	SDL_Rect src_rect = texture_sizes_[obj];
	SDL_Rect dest_rect = src_rect;
	src_rect.x = 0;
	src_rect.y = 0;
	dest_rect.x = x;
	dest_rect.y = y;
	if (w != 0)
	{
		src_rect.w = dest_rect.w = w;
	}
	if (h != 0)
	{
		src_rect.h = dest_rect.h = h;
	}
	SDL_RenderCopy(renderer_, textures_[obj], NULL, &dest_rect);
}




SDL_Texture* SDLRenderer::LoadTexture(std::string file)
{
	std::string path = "Resources/"+file+".png";
	
	SDL_Surface* surface = IMG_Load(path.c_str());
	if(surface == NULL)
	{
		std::cerr << "Loading Image Failure: " << path.c_str() <<  IMG_GetError() << std::endl;
		return NULL;
	}
	
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer_, surface);
	if(texture == NULL)
	{
		std::cerr << "Texture Creation Failure: " <<  IMG_GetError() << std::endl;
	}
	SDL_FreeSurface(surface);
	
	return texture;
}


void SDLRenderer::GetSceneSize(int& width, int& height)
{
	width  = GameParam::kSceneWidth;
	height = GameParam::kSceneHeight;
}

