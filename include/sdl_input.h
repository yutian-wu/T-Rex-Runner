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
