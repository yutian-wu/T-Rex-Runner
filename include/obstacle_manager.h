//
//  obstacle_manager.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef OBSTACLE_MANAGER_HPP
#define OBSTACLE_MANAGER_HPP


// CPP
#include <deque>

// LOCAL
#include "game_object.h"
#include "objects_manager.h"
#include "renderer.h"
#include "tree.h"


class ObstacleManager : public ObjectsManager
{
public:
	ObstacleManager();
	~ObstacleManager();
	
	void Init();
	void UpdateLocation(double time);
	void Render(Renderer& renderer);
	bool CollidedWith(const GameObject& obj);
	
private:
	bool SpawnATree(double likelihood);
	
	std::deque<GameObject*> trees_;
};


#endif /* obstacle_manager_h */
