//
//  background_manager.hpp
//  T-Rex-Runner
//
//  Created by Tim on 2016-06-05.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef background_manager_hpp
#define background_manager_hpp


// LOCAL
#include "game_object.hpp"
#include "objects_manager.hpp"
#include "renderer.hpp"

#include "road.hpp"
#include "cloud.hpp"


class BackgroundManager : public ObjectsManager
{
public:
	BackgroundManager();
	~BackgroundManager();
	
	void Init();
	void Render(Renderer& renderer);
	bool CollidedWith(const GameObject& obj);
	void UpdateLocation(double time);
	
private:
	void RenderList(std::deque<GameObject*>& list, Renderer& renderer);
	static TRex::Object getRoad();
	
	std::deque<GameObject*> roads_;
	std::deque<GameObject*> clouds_;
};


#endif /* background_manager_hpp */
