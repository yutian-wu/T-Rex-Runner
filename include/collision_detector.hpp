//
//  collide_detector.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef collide_detector_hpp
#define collide_detector_hpp

// LOCAL
#include "game_object.hpp"
#include "objects_manager.hpp"


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



#endif /* collide_detector_hpp */
