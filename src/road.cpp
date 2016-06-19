//
//  road.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

// CPP
#include <iostream>
#include <string>
#include <stdlib.h>

// LOCAL
#include "road.h"
#include "game_env.h"



Road::Road(int x, int y): GameObject(TRex::ROAD, x, y)
{
	Init();
}

Road::Road(): GameObject(TRex::ROAD)
{
	Init();
}

Road::Road(TRex::Object obj, int x, int y): GameObject(obj, x, y)
{
	Init();
}

Road::~Road() {}


void Road::Init()
{
	y_ = GameParam::kSceneHeight - GameParam::kHorizonHeight;
	v_x_ = (-1)*GameParam::kDinoSpeed;
	width_ = GameParam::kRoadWidth;
	height_ = kRoadHeight;
}


bool Road::CollidedWith(const GameObject& obj) const
{
	return false;
}

GameObject* Road::GetRoad(int x, int y)
{
	Road* road = NULL;
	
	int num = rand() % 20;
	
	if (num == 0)
	{
		road = new Road(TRex::Object::ROAD_UP);
	}
	else if (num == 1)
	{
		road = new Road(TRex::Object::ROAD_DOWN);
	}
	else
	{
		road = new Road(TRex::ROAD);
	}
	road->SetPosition(x);
	
	return road;
}
