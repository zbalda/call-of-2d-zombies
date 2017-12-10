// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _ENEMY_AI_COMPONENT_H_
#define _ENEMY_AI_COMPONENT_H_

#include "AI_Component.h"

#include <math.h>

class Enemy_AI_Component : public AI_Component
{
public:
  /// default constructor
  Enemy_AI_Component (void);

  /// destructor
  virtual ~Enemy_AI_Component (void);

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message);

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Camera & camera);
};

#endif  //  !defined _ENEMY_AI_COMPONENT_H_
