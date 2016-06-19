//
//  TRexGame.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//


// SDL2
#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"

// CPP
#include <thread>
#include <chrono>
#include "pthread.h"
#include <iostream>
#include <iomanip>

// LOCAL
#include "game_env.hpp"
#include "TRexGame.hpp"
#include "dinosaur.hpp"
#include "collision_detector.hpp"
#include "background_manager.hpp"
#include "obstacle_manager.hpp"
#include "sdl_renderer.hpp"
#include "utility.hpp"


const int kFrameRate = 50;

const double TRexGame::kGameMaxSpeed = 2.0;
const double TRexGame::kGameMinSpeed = 0.5;


TRexGame::TRexGame(Renderer* renderer)
{
	renderer_ = renderer;
	background_manager_ = new BackgroundManager();
	obstacle_manager_ = new ObstacleManager();
	dinosaur_ = new Dinosaur(GameParam::kInitX, GameParam::kInitY);
	collision_detector_ = new CollisionDetector(obstacle_manager_, dinosaur_);
	game_speed_ = 1;
}


TRexGame::~TRexGame()
{
	delete background_manager_;
	background_manager_ = NULL;
	
	delete obstacle_manager_;
	obstacle_manager_ = NULL;
	
	delete dinosaur_;
	dinosaur_ = NULL;
}


void TRexGame::AccelerateGame(double delta_v)
{
	double accelerated = game_speed_ + delta_v;
	if (within(accelerated, kGameMinSpeed, kGameMaxSpeed))
	{
		game_speed_ = accelerated;
	}
}


void TRexGame::Play()
{
  double goal = 0;
	double render_interval = (double)1/kFrameRate;
	bool collided = false;
	
  std::cout << std::setprecision(3);
  
	while (!GameParam::Quit() && !collided)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e) == 1)
		{
			if(e.type == SDL_QUIT)
			{
				GameParam::SetQuit(true);
      }
      else if (e.type == SDL_KEYDOWN)
      {
        if (dinosaur_->IsJumping()) 
        {
          if (dinosaur_->GetVY() > 0 && e.key.keysym.sym == SDLK_DOWN)
            dinosaur_->SpeedUp(1.2); 
        }
        else
        {
          switch (e.key.keysym.sym)
          {
          case SDLK_SPACE:
              dinosaur_->Jump();
              break;
          case SDLK_LEFT:
              AccelerateGame(-0.1);
              break;
          case SDLK_RIGHT:
              AccelerateGame(0.1);
              break;
          default: break;
          }
        }
      }
    }
    
		renderer_->Clear();
		double time_interval = render_interval * game_speed_;
		
    goal += time_interval;
    // std::cout << time_interval << " Goal: " << goal << std::endl;
    
		background_manager_->UpdateLocation(time_interval);
		background_manager_->Render(*renderer_);
		
		obstacle_manager_->UpdateLocation(time_interval);
		obstacle_manager_->Render(*renderer_);
		
	  dinosaur_->UpdateLocation(time_interval);
		dinosaur_->Render(*renderer_);
		
		renderer_->Present();

		collided = obstacle_manager_->CollidedWith(*dinosaur_);
		
		if (collided)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2*1000));
			collided = false;
      game_speed_ = 1;
			obstacle_manager_->Init();
			background_manager_->Init();
      dinosaur_->Init();
      goal = 0;
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds((int)render_interval*1000));
	}
	
	while (!GameParam::Quit())
	{
		SDL_Event e;
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				GameParam::SetQuit(true);
			}
		}
	}
}




