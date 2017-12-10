// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _PLAYER_GRAPHICS_COMPONENT_H_
#define _PLAYER_GRAPHICS_COMPONENT_H_

#include "Graphics_Component.h"

class Player_Graphics_Component : public Graphics_Component
{
public:
  /// default constructor
  Player_Graphics_Component (void);

  /// destructor
  virtual ~Player_Graphics_Component (void);

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message);

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Camera & camera);
};

#endif  //  !defined _PLAYER_GRAPHICS_COMPONENT_H_
