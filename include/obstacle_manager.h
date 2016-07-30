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
#include "tree.h"
#include "renderer.h"
#include "game_object.h"
#include "objects_manager.h"


class ObstacleManager : public ObjectsManager
{
public:
	ObstacleManager();
	~ObstacleManager();
	
	void Init();
	void Render(Renderer& renderer);
  void UpdateLocation(double time);
  bool CollidedWith(const GameObject& obj);
	
private:
	std::deque<GameObject*> trees_;
	bool SpawnATree(double likelihood);
};


#endif /* obstacle_manager_h */
