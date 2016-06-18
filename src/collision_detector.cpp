//
//  collide_detector.cpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//


// LOCAL
#include "collision_detector.hpp"
#include "game_env.hpp"


CollisionDetector::CollisionDetector(ObjectsManager* obstacles, GameObject* dino)
	:obstacles_(obstacles), dinosaur_(dino) {}


CollisionDetector::~CollisionDetector() {}


void CollisionDetector::Run()
{
	while (!GameParam::Quit())
	{
		if (obstacles_->CollidedWith(*dinosaur_))
		{
			GameParam::SetCollision(true);
		}
	}
}

