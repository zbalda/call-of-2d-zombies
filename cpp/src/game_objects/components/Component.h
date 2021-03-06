// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "../Camera.h"
#include "../../game/game_world/Game_World.h"

class Game_Object;

class Component
{
public:
  // virtual destructor
  virtual ~Component (void) { }

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message) = 0;

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Camera & camera) = 0;

  // clone component
  virtual Component * clone (void) = 0;
};

#endif  //  !defined _COMPONENT_H_
