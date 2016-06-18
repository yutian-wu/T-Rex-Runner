//
//  TRexGame.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef TRexGame_hpp
#define TRexGame_hpp


// LOCAL
#include "game_object.hpp"
#include "objects_manager.hpp"
#include "dinosaur.hpp"
#include "renderer.hpp"
#include "collision_detector.hpp"


class TRexGame
{
public:
	TRexGame(Renderer* renderer);
	~TRexGame();
	
	void Play();

private:
	bool AcceptInput();
	void AccelerateGame(double delta_a);
	
	static const double kGameMaxSpeed;
	static const double kGameMinSpeed;
	
	Renderer* renderer_;
	CollisionDetector* collision_detector_;
	ObjectsManager* background_manager_;
	ObjectsManager* obstacle_manager_;
	Dinosaur* dinosaur_;
	double game_speed_;
};

#endif /* TRexGame_hpp */
