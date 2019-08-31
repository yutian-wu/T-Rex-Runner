#include "game_env.h"

namespace GameParam
{
  extern const double  kGravitationalAcceleration = -30;
  
  extern const unsigned int  kSceneWidth = 600;
  extern const unsigned int  kSceneHeight = 250;
  extern const unsigned int  kHorizonHeight = 20;
  
  extern const unsigned int  kInitX = 10;
  extern const unsigned int  kInitY = kSceneHeight - kHorizonHeight - 53;
  
  extern const double  kCloudSpeed = 50;
  
  extern const double  kDinoMinSpeed = 30;
  extern const double  kDinoMaxSpeed = 80;
  
  extern const unsigned int  kRoadWidth = 22;
  extern const unsigned int  kDinoJumpMax = 70;
  
  double gDinoSpeed = 40;
  bool gCollided = false;
  bool gQuit = false;
};
