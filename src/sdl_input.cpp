//
//  sdl_input.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-19.
//  Copyright © 2016 Tim. All rights reserved.
//


// SDL
#include <SDL2/SDL.h>

// LOCAL
#include "sdl_input.h"



SDLInput::SDLInput() {}


SDLInput::~SDLInput() {}


GameCommand SDLInput::GetCommand()
{
	SDL_Event e;
	while(SDL_PollEvent(&e) == 1)
	{
		if(e.type == SDL_QUIT)
		{
			return GameCommand::QUIT;
		}
		
		if (e.type == SDL_KEYDOWN)
		{
			return GameCommand::DOWN;
	
		}
		
		switch (e.key.keysym.sym)
		{
			case SDLK_SPACE:
				return GameCommand::SPACE;
			case SDLK_LEFT:
				return GameCommand::LEFT;
			case SDLK_RIGHT:
				return GameCommand::RIGHT;
			default:
				return GameCommand::NIL;
		}
	}
	return GameCommand::NIL;
}


void SDLInput::Init()
{
	SDL_FlushEvent(SDL_KEYDOWN);  
}

