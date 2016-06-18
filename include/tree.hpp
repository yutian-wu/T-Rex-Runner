//
//  tree.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp


// CPP
#include <stdio.h>

// LOCAL
#include "game_object.hpp"

class Tree : public GameObject
{
public:
	Tree(int x, int y);
	~Tree();
	
	static GameObject* GetTree(int x, int y);
};

#endif /* tree_hpp */
