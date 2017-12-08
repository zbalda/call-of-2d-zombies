// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GRAPHICS_COMPONENT_H_
#define _GRAPHICS_COMPONENT_H_

#include "../Component.h"

class Graphics_Component : public Component
{
public:
  // virtual destructor
  virtual ~Component (void) { }

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message) = 0;

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Game_Object & camera) = 0;
}

#endif  //  !defined _GRAPHICS_COMPONENT_H_
