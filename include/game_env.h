//
//  game_env.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef game_env_h
#define game_env_h

#include <stdio.h>


namespace TRex
{
#define T_REX_GAME_OBJECTS \
OBJ(ROAD, "road") \
OBJ(ROAD_UP, "road_up") \
OBJ(ROAD_DOWN, "road_down") \
OBJ(TREE, "one_tree_1") \
OBJ(DINOSAUR, "dino_stand") \
OBJ(DINOSAUR_HIT, "dino_hit") \
OBJ(DINOSAUR_JUMP, "dino_jump") \
OBJ(DINOSAUR_LEFT_FOOT, "dino_run1") \
OBJ(DINOSAUR_RIGHT_FOOT, "dino_run2") \
OBJ(CLOUD, "cloud") \
OBJ(LAST, "t-rex-runner")
	
	
#define OBJ(a, b) a,
	enum Object
	{
		T_REX_GAME_OBJECTS
	};
#undef OBJ
}


class GameParam
{
public:
	static const double kGravitationalAcceleration;
	
	static const unsigned int kSceneWidth;
	static const unsigned int kSceneHeight;
	static const unsigned int kHorizonHeight;

	static const unsigned int kInitX;
	static const unsigned int kInitY;
	
	static double kDinoSpeed;
	static const double kDinoMinSpeed;
	static const double kDinoMaxSpeed;
	
	static const double kCloudSpeed;
	
	static const unsigned int kRoadWidth;
	
	static const unsigned int kDinoJumpMax;
	
	static bool Quit();
	static void SetQuit(bool quit);
	
	static bool ObjectCollided();
	static void SetCollision(bool collided);
	
private:
	static void RunTimer();
	
	static const bool collided_;
	static unsigned int time_;
	static bool quit_;
};



#endif /* game_env_h */
