#ifndef dinosaur_h
#define dinosaur_h

// LOCAL
#include "game_object.h"

enum DINO_STATE
{
  DINO_JUMP,
	DINO_RUN,
	DINO_HIT
};


class Dinosaur : public GameObject
{
public:
	Dinosaur(int x, int y);

  void Init();
  bool IsJumping();
	DINO_STATE State();
	void Jump(double v0 = kJumpVy);
	virtual void UpdateLocation(double time);
  virtual bool CollidedWith(const GameObject& obj, int width = -1, int height = -1) const;
	
private:
	static double kJumpVy;
	static double kFeetSwitchFreq;
	
	DINO_STATE state_;
  double time_;
  int dino_run;
};


#endif /* dinosaur_h */
