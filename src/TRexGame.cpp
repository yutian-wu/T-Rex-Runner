
// SDL2
#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"

// CPP
#include <thread>
#include <chrono>
#include <iomanip>
#include <iostream>

// LOCAL
#include "input.h"
#include "utility.h"
#include "game_env.h"
#include "TRexGame.h"
#include "dinosaur.h"
#include "sdl_renderer.h"
#include "obstacle_manager.h"
#include "collision_detector.h"
#include "background_manager.h"


const int kFrameRate = 30;

const double TRexGame::kGameMaxSpeed = 2.0;
const double TRexGame::kGameMinSpeed = 0.5;


TRexGame::TRexGame(Renderer* renderer, Input* input)
{
	input_ = input;
	renderer_ = renderer;
	obstacle_manager_ = new ObstacleManager();
	background_manager_ = new BackgroundManager();
  dinosaur_ = new Dinosaur(GameParam::kInitX, GameParam::kInitY);
	collision_detector_ = new CollisionDetector(obstacle_manager_, dinosaur_);
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
	GameInit();
  
	while (!GameParam::gQuit && !collided_)
	{
		GameCommand cmd = input_->GetCommand();
		switch (cmd)
    {
      case NIL:
        break;
      case QUIT:
        GameParam::gQuit = true; 
        return;
      case SPACE:
        if (!dinosaur_->IsJumping())
        {
          dinosaur_->Jump();
        }
        break;
      case LEFT:
        AccelerateGame(-0.1);
        time_interval_ = render_interval_ * game_speed_;
        break;
      case RIGHT:
        AccelerateGame(0.1);
        time_interval_ = render_interval_ * game_speed_;
        break;
      case DOWN:
        if (dinosaur_->GetVY() > 0)
        {
          dinosaur_->SpeedUp(1.2);
        }
        break;
      default: break;
		}
		
		renderer_->Clear();
		Update(time_interval_);
		renderer_->Present();

		collided_ = obstacle_manager_->CollidedWith(*dinosaur_);
		if (collided_)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2*1000));
			GameInit();
		}
    std::this_thread::sleep_for(std::chrono::milliseconds((int)render_interval_*1000));
	}
}


void TRexGame::Update(double time_interval)
{
	background_manager_->UpdateLocation(time_interval);
	background_manager_->Render(*renderer_);

	obstacle_manager_->UpdateLocation(time_interval);
	obstacle_manager_->Render(*renderer_);

	dinosaur_->UpdateLocation(time_interval);
	dinosaur_->Render(*renderer_);
}


void TRexGame::GameInit()
{
	score_ = 0;
	game_speed_ = 0.1;
  collided_ = false;
	render_interval_ = (double)1 / kFrameRate;
	time_interval_ = render_interval_ * game_speed_;
	
  input_->Init();
  dinosaur_->Init();
	obstacle_manager_->Init();
	background_manager_->Init();
}

