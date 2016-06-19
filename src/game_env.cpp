//
//  game_env.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#include "game_env.h"

const double GameParam::kGravitationalAcceleration = -30;

const unsigned int GameParam::kSceneWidth = 600;
const unsigned int GameParam::kSceneHeight = 250;
const unsigned int GameParam::kHorizonHeight = 20;

const unsigned int GameParam::kInitX = 10;
const unsigned int GameParam::kInitY = kSceneHeight - kHorizonHeight - 53;

const double GameParam::kCloudSpeed = 50;

double GameParam::kDinoSpeed = 40;
const double GameParam::kDinoMinSpeed = 30;
const double GameParam::kDinoMaxSpeed = 80;

const unsigned int GameParam::kRoadWidth = 22;
const unsigned int GameParam::kDinoJumpMax = 70;


bool GameParam::quit_ = false;
unsigned int GameParam::time_ = 0;
const bool GameParam::collided_ = false;


bool GameParam::Quit()
{
	// TO DO
	return quit_;
}

void GameParam::SetQuit(bool quit)
{
	// TO DO
	quit_ = quit;
}

bool GameParam::ObjectCollided()
{
  // TO DO
	return collided_;
}

void GameParam::SetCollision(bool collided)
{
  // TO DO
}


void GameParam::RunTimer()
{
  // TO DO
}
