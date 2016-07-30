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
	void Update(double time_interval);
  void AccelerateGame(double delta_a);
	
	static const double kGameMaxSpeed;
	static const double kGameMinSpeed;
	
	Input* input_;
	Renderer* renderer_;
	Dinosaur* dinosaur_;
  ObjectsManager* obstacle_manager_;
	ObjectsManager* background_manager_;
  CollisionDetector* collision_detector_;

  int score_;
  double collided_;
	double game_speed_;
	double time_interval_;
	double render_interval_;
};

#endif /* TRexGame_h */
