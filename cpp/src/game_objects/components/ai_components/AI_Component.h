// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _AI_COMPONENT_H_
#define _AI_COMPONENT_H_

#include "../Component.h"
#include "../../Game_Object.h"

class AI_Component : public Component
{
public:
  // virtual destructor
  virtual ~AI_Component (void) { }

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message) = 0;

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Camera & camera) = 0;

  // clone component
  virtual Component * clone (void) = 0;
};

#endif  //  !defined _AI_COMPONENT_H_
