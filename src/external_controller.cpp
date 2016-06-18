//
//  external_controller.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

// CPP
#include <thread>
#include <chrono>
#include "pthread.h"
#include <iostream>


// SDL2
#include <SDL2/SDL.h>
#include "SDL2/SDL_thread.h"

// LOCAL
#include "external_controller.hpp"
#include "sdl_renderer.hpp"
#include "TRexGame.hpp"
#include "game_env.hpp"



Controller::Controller() {}

Controller::~Controller() {}


int windowListener(void* data);

int checkQuit(void* data);

void Controller::Play()
{
	Renderer* renderer = new SDLRenderer();
	renderer->Init();
	
	TRexGame game(renderer);
	
	game.Play();
	
	delete renderer;
}



