//
//  cloud.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef cloud_hpp
#define cloud_hpp



// CPP
#include <stdio.h>

// LOCAL
#include "game_object.hpp"

class Cloud : public GameObject
{
public:
	Cloud();
	Cloud(int x, int y);
	~Cloud();
	
	static GameObject* GetCloud(int x = -1, int y = -1);
	bool CollidedWith(const GameObject& obj) const;
	
private:
	void Init();
};






#endif /* cloud_hpp */
