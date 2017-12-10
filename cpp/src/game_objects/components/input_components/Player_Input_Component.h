// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _PLAYER_INPUT_COMPONENT_H_
#define _PLAYER_INPUT_COMPONENT_H_

#include "Input_Component.h"

class Player_Input_Component : public Input_Component
{
public:
  /// default constructor
  Player_Input_Component (void);

  /// destructor
  virtual ~Player_Input_Component (void);

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message);

  // update game object
  virtual void update (Game_Object & object, Game_World & world, Camera & camera);
};

#endif  //  !defined _PLAYER_INPUT_COMPONENT_H_
