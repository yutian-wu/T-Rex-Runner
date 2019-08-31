#ifndef input_h
#define input_h


// LOCAL
#include "TRexGame.h"


class Input
{
public:
	virtual ~Input();
  
	virtual void Init() = 0;
	virtual GameCommand GetCommand() = 0;
};


#endif /* input_h */
