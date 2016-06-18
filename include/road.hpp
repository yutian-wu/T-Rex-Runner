//
//  road.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef road_hpp
#define road_hpp

// CPP
#include <stdio.h>

// LOCAL
#include "game_object.hpp"

class BackgroundManager;

class Road : public GameObject
{
	friend class BackgroundManager;
	
public:
	Road(int x, int y);
	Road();
	~Road();
	
	static GameObject* GetRoad(int x, int y);
	bool CollidedWith(const GameObject& obj) const;
	
private:
	explicit Road(TRex::Object obj, int x = 0, int y =0);
	void Init();
	
	static const int kRoadHeight = 15;
};




#endif /* road_hpp */
