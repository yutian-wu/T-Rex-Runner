#ifndef collide_detector_h
#define collide_detector_h

// LOCAL
#include "game_object.h"
#include "objects_manager.h"


class CollisionDetector
{
public:
	CollisionDetector(ObjectsManager* obstacles, GameObject* dino);
	~CollisionDetector();
	
	void Run();
	
private:
	ObjectsManager* obstacles_;
	GameObject* dinosaur_;
};



#endif /* collide_detector_h */
