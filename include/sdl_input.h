//
//  sdl_input.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-19.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef sdl_input_h
#define sdl_input_h

// LOCAL
#include "TRexGame.h"
#include "input.h"

class SDLInput : public Input
{
	
public:
	SDLInput();
	~SDLInput();
	
	void Init();
	GameCommand GetCommand();
};


#endif /* sdl_input_h */
