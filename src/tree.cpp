// CPP
#include <iostream>

// LOCAL
#include "game_env.h"
#include "tree.h"
#include "renderer.h"


const int kTreeWidth = 22;
const int kTreeHeight = 44;
const int kInitY = GameParam::kSceneHeight - GameParam::kHorizonHeight - 33;


Tree::Tree(int x, int y): GameObject(TRex::TREE, x, kInitY)
{
	width_ = kTreeWidth;
	height_ = kTreeHeight;
  v_x_ = (-1) * GameParam::gDinoSpeed;
}


GameObject* Tree::GetTree(int x, int y)
{
	return new Tree(x, y);
}

