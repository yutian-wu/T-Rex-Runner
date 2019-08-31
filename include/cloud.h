#ifndef cloud_h
#define cloud_h



// CPP
#include <stdio.h>

// LOCAL
#include "game_object.h"

class Cloud : public GameObject
{
public:
	Cloud();
	explicit Cloud(int x, int y);

  bool CollidedWith(const GameObject& obj) const;
	static GameObject* GetCloud(int x = -1, int y = -1);

private:
	void Init();
};






#endif /* cloud_h */
