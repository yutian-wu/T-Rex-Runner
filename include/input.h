//
//  input.h
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef input_hpp
#define input_hpp


// LOCAL
#include "TRexGame.h"

class Input
{

public:
	virtual ~Input();
	virtual void Init() = 0;
	virtual GameCommand GetCommand() = 0;
};



#endif /* input_hpp */
