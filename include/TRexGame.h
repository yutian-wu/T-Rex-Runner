//
//  TRexGame.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef TRexGame_h
#define TRexGame_h


// LOCAL
#include "game_object.h"
#include "objects_manager.h"
#include "dinosaur.h"
#include "renderer.h"
#include "collision_detector.h"


enum GameCommand
{
	NIL,
	QUIT,
	SPACE,
	LEFT,
	RIGHT,
	DOWN
};

class Input;

class TRexGame
{
public:
	explicit TRexGame(Renderer* renderer, Input* input);
	~TRexGame();
	
	void Play();

private:
	void GameInit();
	bool AcceptInput();
	void AccelerateGame(double delta_a);
	void Update(double time_interval);
	
	static const double kGameMaxSpeed;
	static const double kGameMinSpeed;
	
	Input* input_;
	Renderer* renderer_;
	CollisionDetector* collision_detector_;
	ObjectsManager* background_manager_;
	ObjectsManager* obstacle_manager_;
	Dinosaur* dinosaur_;
	
	double game_speed_;
	double render_interval_ ;
	double time_interval_ ;
	double collided_;
	int score_;
};

#endif /* TRexGame_h */
