//
//  road.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef road_h
#define road_h

// CPP
#include <stdio.h>

// LOCAL
#include "game_object.h"

class BackgroundManager;

class Road : public GameObject
{
  friend class BackgroundManager;
	
public:
	explicit Road(int x, int y);
	Road();
	~Road();
	
	static GameObject* GetRoad(int x, int y);
	bool CollidedWith(const GameObject& obj) const;
	
private:
	explicit Road(TRex::Object obj, int x = 0, int y =0);
	void Init();
	
	static const int kRoadHeight = 15;
};

#endif /* road_h */
