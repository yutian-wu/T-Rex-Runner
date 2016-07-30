//
//  renderer.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef renderer_h
#define renderer_h

// CPP
#include <string>

// LOCAL
#include "game_env.h"

extern const std::string GAME_OBJECT_IMAGE[];

struct GameShape
{
	int x, y;
	int w, h;
};

class Renderer
{
public:
	virtual ~Renderer();
	
	virtual void Init() = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual void GetSceneSize(int& width, int& height) = 0;
	virtual void Render(const TRex::Object& obj, const GameShape* src,
                      const GameShape* dest) = 0;
	virtual void Render(const TRex::Object& obj, const int x, const int y,
											const int w = 0, const int h = 0) = 0;
};



#endif /* renderer_h */

