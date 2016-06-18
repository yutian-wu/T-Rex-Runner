//
//  sdl_renderer.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef sdl_renderer_hpp
#define sdl_renderer_hpp

// CPP
#include <vector>
#include <string>

// SDL2
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

// LOCAL
#include "renderer.hpp"

class SDLRenderer : public Renderer
{
public:
	SDLRenderer();
	~SDLRenderer();
	
	void Init();
	void Clear();
	void Present();
	void GetSceneSize(int& width, int& height);
	
	void Render(const TRex::Object& obj, const GameShape* src, const GameShape* dest);
	
	void Render(const TRex::Object& obj,
							const int x, const int y, const int w = 0, const int h = 0);
	
private:
	SDL_Texture* LoadTexture(std::string file);
	void DestroyTextures();
	
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	std::vector<SDL_Texture*> textures_;
	std::vector<SDL_Rect> texture_sizes_; 
};

#endif /* sdl_renderer_hpp */
