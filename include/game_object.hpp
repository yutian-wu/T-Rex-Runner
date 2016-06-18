//
//  game_object.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef game_object_hpp
#define game_object_hpp


enum ObjectState
{
	Out,
	Collided,
	Moving,
	Static,
};



// CPP
#include <deque>
#include <string>

// LOCAL
#include "renderer.hpp"
#include "game_env.hpp"


class GameObject
{
public:
	GameObject(TRex::Object obj, double x = 0, double y = 0);
	GameObject(double x, double y, std::string texture_file);
	virtual ~GameObject();
	
	int GetWidth();
	int GetHeight();
	double GetX();
	double GetY();
	double GetVX();
	double GetVY();
	double GetTopRightX();
	
	/* Setters */
	void SetVx(double v_x);
	void SetVy(double v_y);
	void SetSize(int width, int height);
	void SetPosition(double x = -1, double y = -1);
	void SpeedUp(double scale);
	
	virtual void UpdateLocation(double time);
	virtual void Render(Renderer& renderer);
	virtual bool CollidedWith(const GameObject& obj, int width = -1, int height = -1) const;
	
protected:
	
	std::string kTextureFile;
	bool collided_;
	ObjectState state_;
	
	/* Size */
	int width_;
	int height_;
	
	/* Coordinate */
	double x_;
	double y_;
	
	/* Velocity */
	double v_x_;
	double v_y_;
	
	/* Accelerations */
	double a_x_;
	double a_y_;

	TRex::Object obj_;
};

typedef std::deque<GameObject*> GameObjectContainer; 

#endif /* game_object_hpp */
