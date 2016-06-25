//
//  collide_detector.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef collide_detector_h
#define collide_detector_h

// LOCAL
#include "game_object.h"
#include "objects_manager.h"


class CollisionDetector
{
public:
	CollisionDetector(ObjectsManager* obstacles, GameObject* dino);
	~CollisionDetector();
	
	void Run();
	
private:
	ObjectsManager* obstacles_;
	GameObject* dinosaur_;
};



#endif /* collide_detector_h */
