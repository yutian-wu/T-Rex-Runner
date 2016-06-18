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
#include "objects_manager.hpp"
#include "game_object.hpp"




ObjectsManager::~ObjectsManager() {}


void ObjectsManager::Run()
{
	// TO DO
}



void ObjectsManager::DestroyObjects(GameObjectContainer& objects)
{
	while (!objects.empty())
	{
		GameObject* temp = objects.front();
		delete temp;
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
		for(; it < list.end(); ++it)
		{
			if (list.size() == 0 || (*it)->GetX() + (*it)->GetWidth() > 0)
			{
				break;
			}
			GameObject* old_obj = list.front();
			list.pop_front();
			delete old_obj;
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

