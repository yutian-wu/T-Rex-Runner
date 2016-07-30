//
//  obstacle_manager.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

// CPP
#include <deque>
#include <iostream>

// LOCAL
#include "objects_manager.h"
#include "game_object.h"


ObjectsManager::~ObjectsManager() {}


void ObjectsManager::DestroyObjects(GameObjectContainer& objects)
{
	while (!objects.empty())
	{
		delete objects.front();
		objects.pop_front();
	}
}


void ObjectsManager::UpdateLocation(GameObjectContainer& list, double time, bool outOfBoundCleared)
{
	/* Update Location */
	std::deque<GameObject*>::const_iterator it = list.begin();
	for(; it != list.end(); ++it)
	{
		(*it)->UpdateLocation(time);
	}
	
	/* Clear Objects out of bound */
	if (outOfBoundCleared)
	{
		it = list.begin();
		for(; it != list.end() && list.size() != 0 && (*it)->GetTopRightX() <= 0; ++it)
		{
			delete list.front();
      list.pop_front();
			it = list.begin();
		}
	}
}

void ObjectsManager::Render(Renderer& renderer, const GameObjectContainer& objects)
{
	GameObjectContainer::const_iterator it = objects.begin();
	for(; it != objects.end(); ++it)
	{
		(*it)->Render(renderer);
	}
}




bool ObjectsManager::CollidedWith(const GameObject& object, const GameObjectContainer& objects)
{
	GameObjectContainer::const_iterator it = objects.begin();
	for(; it != objects.end(); ++it)
	{
		if (object.CollidedWith(**it)) return true;
	}
	return false;
}

