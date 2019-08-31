#ifndef tree_h
#define tree_h


// CPP
#include <stdio.h>

// LOCAL
#include "game_object.h"

class Tree : public GameObject
{
public:
	Tree(int x, int y);
	
	static GameObject* GetTree(int x, int y);
};

#endif /* tree_h */


