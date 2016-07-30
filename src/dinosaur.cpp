//
//  dinosaur.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//


// CPP
#include <iostream>

// LOCAL
#include "dinosaur.h"
#include "game_env.h"
#include "renderer.h"

double Dinosaur::kJumpVy = 78;
double Dinosaur::kFeetSwitchFreq = 1;


Dinosaur::Dinosaur(int x, int y): GameObject(TRex::DINOSAUR, x, y) {}

void Dinosaur::UpdateLocation(double time)
{
	GameObject::UpdateLocation(time);
	
  /* Walking */
  /* Switch foot at certain frequency */
	if (y_ == GameParam::kInitY)
	{
		time_ += time;
		if (time_ >= 1 / (double)kFeetSwitchFreq)
		{
      obj_ = (TRex::DINOSAUR_LEFT_FOOT == obj_)?
              TRex::DINOSAUR_RIGHT_FOOT : TRex::DINOSAUR_LEFT_FOOT;
			time_ = 0;
		}
	}
  /* Falling onto the ground */
	else if (y_ > GameParam::kInitY)
	{
		a_y_ = 0;
		v_y_ = 0;
		y_ = GameParam::kInitY;
		obj_ = TRex::DINOSAUR_LEFT_FOOT;
	}
}

bool Dinosaur::CollidedWith(const GameObject& obj, int width, int height) const
{
	int collision_width = 43;
	int collision_height = 50;
	return GameObject::CollidedWith(obj, collision_width, collision_height);
}

void Dinosaur::Jump(double v0)
{
	v_y_ = (-1)*v0;
  obj_ = TRex::DINOSAUR_JUMP;
	a_y_ = (-1)*GameParam::kGravitationalAcceleration;
}



bool Dinosaur::IsJumping()
{
	return (obj_ == TRex::DINOSAUR_JUMP);
}

void Dinosaur::Init()
{
	v_x_ = 0;
	v_y_ = 0;
	a_y_ = 0;
  time_ = 0;
	width_ = 56;
	height_ = 59;
	y_ = GameParam::kInitY;
  obj_ = TRex::DINOSAUR_LEFT_FOOT;
}


DINO_STATE Dinosaur::State()
{
	return state_;
}

