
// CPP
#include <stdlib.h>
#include <iostream>

// LOCAL
#include "objects_manager.h"
#include "obstacle_manager.h"
#include "game_env.h"
#include "road.h"
#include "utility.h"


const int kTreeInterval = 230;
const double kTreeFreq = 0.08;

ObstacleManager::ObstacleManager() {}


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
	if (tree <= 1)
  {
    trees_.push_back(Tree::GetTree(GameParam::kSceneWidth, 0));
    return true;
  }
  return false;
}


void ObstacleManager::UpdateLocation(double time)
{
	ObjectsManager::UpdateLocation(trees_, time);
	
	double prob = time*kTreeFreq;
	
	// Spawn a new tree if
  //  1) There is currently no tree
	if (trees_.size() == 0)
	{
		SpawnATree(prob);
	}
	else
	{
    // 2) There are trees and the rightmost one is not so close
		int prev_tree_dist = GameParam::kSceneWidth -
                         (*(--trees_.end()))->GetTopRightX();
		if (prev_tree_dist > kTreeInterval)
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

