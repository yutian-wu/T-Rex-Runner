//
//  background_manager.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//


// CPP
#include <math.h>
#include <stdlib.h>
#include <iostream>

// LOCAL
#include "objects_manager.h"
#include "background_manager.h"
#include "game_env.h"
#include "road.h"
#include "cloud.h"
#include "renderer.h"

const int kNumOfRoads = GameParam::kSceneWidth / GameParam::kRoadWidth + 1;


BackgroundManager::BackgroundManager() {}


void BackgroundManager::Init()
{
	DestroyObjects(roads_);
	DestroyObjects(clouds_);
	
	int x = 0;
	int count = kNumOfRoads;
	while (count--)
	{
		GameObject* road = Road::GetRoad(x, -1);
		roads_.push_back(road);
		x += GameParam::kRoadWidth;
	}
}

BackgroundManager::~BackgroundManager()
{
	DestroyObjects(roads_);
	DestroyObjects(clouds_);
}


void BackgroundManager::UpdateLocation(double time)
{	
	/* Update Location */
	ObjectsManager::UpdateLocation(roads_, time);
	ObjectsManager::UpdateLocation(clouds_, time);
	
	/* Randomly spawn a cloud */
  if (rand()%(int)(10/time) == 0 && (clouds_.size() == 0 ||
       GameParam::kSceneWidth - clouds_.back()->GetTopRightX() > 60))
  {
    clouds_.push_back(Cloud::GetCloud());
  }
  
	/* Supply new Road if necessary */
	while (roads_.back()->GetTopRightX() < GameParam::kSceneWidth)
	{
		GameObject* new_road = Road::GetRoad(roads_.back()->GetTopRightX(), 0);
		roads_.push_back(new_road);
	}
}

void BackgroundManager::RenderList(std::deque<GameObject*>& list, Renderer& renderer)
{
	std::deque<GameObject*>::const_iterator it = list.begin();
	for(; it != list.end(); ++it)
	{
		(*it)->Render(renderer);
	}
}


void BackgroundManager::Render(Renderer& renderer)
{
	/* Render the road */
	RenderList(roads_, renderer);
	
	/* Render the clouds */
	RenderList(clouds_, renderer);
}


bool BackgroundManager::CollidedWith(const GameObject& obj)
{
	return false;
}


