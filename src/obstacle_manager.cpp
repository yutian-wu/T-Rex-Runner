//
//  obstacle_manager.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//


// CPP
#include <stdlib.h>
#include <iostream>

// LOCAL
#include "objects_manager.hpp"
#include "obstacle_manager.hpp"
#include "game_env.hpp"
#include "road.hpp"
#include "utility.hpp"


const int kTreeInterval = 230;
const double kTreeFreq = 0.08;

ObstacleManager::ObstacleManager()
{
	Init();
}


ObstacleManager::~ObstacleManager()
{
	DestroyObjects(trees_);
}


void ObstacleManager::Init()
{
	DestroyObjects(trees_);
}


bool ObstacleManager::SpawnATree(double probability)
{
	int tree = rand() % (int)(1/probability);
	if (tree > 1) return false;
	GameObject* new_tree = Tree::GetTree(GameParam::kSceneWidth, 0);
	trees_.push_back(new_tree);
	return true;
}


void ObstacleManager::UpdateLocation(double time)
{
	ObjectsManager::UpdateLocation(trees_, time);
	
	double prob = time*kTreeFreq;
	
	// Spawn a new tree if previous one is not so close
	if (trees_.size() == 0)
	{
		SpawnATree(prob);
	}
	else
	{
		int prev_tree_dist = GameParam::kSceneWidth - (*(--trees_.end()))->GetTopRightX();
		if (prev_tree_dist > kTreeInterval || within(prev_tree_dist, 22, 30))
		{
			SpawnATree(prob);
		}
	}
}



void ObstacleManager::Render(Renderer& renderer)
{
	/* Render some trees */
	ObjectsManager::Render(renderer, trees_);
}


bool ObstacleManager::CollidedWith(const GameObject& obj)
{
	return ObjectsManager::CollidedWith(obj, trees_);
}

