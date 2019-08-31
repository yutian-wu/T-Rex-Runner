#ifndef game_env_h
#define game_env_h

#include <stdio.h>


namespace TRex
{
  #define T_REX_GAME_OBJECTS \
  OBJ(ROAD, "road") \
  OBJ(ROAD_UP, "road_up") \
  OBJ(ROAD_DOWN, "road_down") \
  OBJ(TREE, "one_tree_1") \
  OBJ(DINOSAUR, "dino_stand") \
  OBJ(DINOSAUR_HIT, "dino_hit") \
  OBJ(DINOSAUR_JUMP, "dino_jump") \
  OBJ(DINOSAUR_LEFT_FOOT, "dino_run1") \
  OBJ(DINOSAUR_RIGHT_FOOT, "dino_run2") \
  OBJ(CLOUD, "cloud") \
  OBJ(LAST, "t-rex-runner")
    
    
  #define OBJ(a, b) a,
    enum Object
    {
      T_REX_GAME_OBJECTS
    };
  #undef OBJ
}

namespace GameParam
{
  extern const double kGravitationalAcceleration;
  
  extern const unsigned int kSceneWidth;
  extern const unsigned int kSceneHeight;
  extern const unsigned int kHorizonHeight;
  
  extern const unsigned int kInitX;
  extern const unsigned int kInitY;
  
  extern const double kCloudSpeed;
  
  extern const double kDinoMinSpeed;
  extern const double kDinoMaxSpeed;
  
  extern const unsigned int kRoadWidth;
  extern const unsigned int kDinoJumpMax;
  
  extern double  gDinoSpeed;
  extern bool  gCollided;
  extern bool  gQuit;
};

#endif /* game_env_h */
