#ifndef game_object_h
#define game_object_h


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
#include "renderer.h"
#include "game_env.h"


class GameObject
{
public:
	GameObject(double x, double y, std::string texture_file);
  explicit GameObject(TRex::Object obj, double x = 0, double y = 0);
	virtual ~GameObject();
	
  /* Accessors */
	double GetX();
	double GetY();
	double GetVX();
	double GetVY();
  int GetWidth();
  int GetHeight();
  double GetTopRightX();
	
	/* Setters */
	void SetVx(double v_x);
	void SetVy(double v_y);
	void SpeedUp(double scale);
  void SetSize(int width, int height);
	void SetPosition(double x = -1, double y = -1);

	virtual void UpdateLocation(double time);
	virtual void Render(Renderer& renderer);
	virtual bool CollidedWith(const GameObject& obj, int width = -1, int height = -1) const;
	
protected:
	/* Coordinate */
	double x_;
	double y_;
	
  /* Size */
  int width_;
  int height_;
  
	/* Velocity */
	double v_x_;
	double v_y_;
	
	/* Accelerations */
	double a_x_;
	double a_y_;
  
  bool collided_;
  TRex::Object obj_;
  ObjectState state_;
};

typedef std::deque<GameObject*> GameObjectContainer; 

#endif /* game_object_h */
