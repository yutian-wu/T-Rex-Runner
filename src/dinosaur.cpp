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

const bool kLeftFoot = true;
const bool kRightFoot = false;

Dinosaur::Dinosaur(int x, int y): GameObject(TRex::DINOSAUR, x, y) {}

Dinosaur::~Dinosaur() {}


void Dinosaur::UpdateLocation(double time)
{
	GameObject::UpdateLocation(time);
	// std::cout << "Dino: x " << x_ << " y " << y_ << " v_y " << v_y_ << " a_y " << a_y_ << std::endl;
	
	if (y_ == GameParam::kInitY)
	{
		time_ += time;
		if (time_ >= 1/(double)kFeetSwitchFreq)
		{
			foot_ = !foot_;
			time_ = 0;
		}
	}
	else if (y_ < GameParam::kInitY)
	{
		obj_ = TRex::DINOSAUR_JUMP;
	}
	else if (y_ > GameParam::kInitY)
	{
		a_y_ = 0;
		v_y_ = 0;
		y_ = GameParam::kInitY;
		obj_ = TRex::DINOSAUR_LEFT_FOOT;
	}
	
	SwitchFoot();
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
	a_y_ = (-1)*GameParam::kGravitationalAcceleration;
	obj_ = TRex::DINOSAUR_JUMP;	
}


void Dinosaur::SwitchFoot()
{
	if (obj_ != TRex::DINOSAUR_JUMP)
	{
		obj_ = (foot_ == kLeftFoot)? TRex::DINOSAUR_LEFT_FOOT : TRex::DINOSAUR_RIGHT_FOOT;
	}
}


bool Dinosaur::IsJumping()
{
	return (obj_ == TRex::DINOSAUR_JUMP);
}

void Dinosaur::Init()
{
	y_ = GameParam::kInitY;
	v_x_ = 0;
	v_y_ = 0;
	a_y_ = 0;
	width_ = 56;
	height_ = 59;
	time_ = 0;
	foot_ = kLeftFoot;
	obj_ = TRex::DINOSAUR_LEFT_FOOT;
}


DINO_STATE Dinosaur::State()
{
	return state_;
}

