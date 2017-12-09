// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _INPUT_COMPONENT_H_
#define _INPUT_COMPONENT_H_

#include "../Component.h"

class Input_Component : public Component
{
public:
  // virtual destructor
  virtual ~Component (void) { }

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message) = 0;

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Camera & camera) = 0;
}

#endif  //  !defined _INPUT_COMPONENT_H_
