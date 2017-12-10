// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Player_Graphics_Component.h"

//
// Player_Graphics_Component
//
Player_Graphics_Component::Player_Graphics_Component (void)
  : R (0)
  , G (153)
  , B (255)
  , A (255)
{
}

//
// ~Player_Graphics_Component
//
Player_Graphics_Component::~Player_Graphics_Component (void)
{
}

//
// recieve
//
void Player_Graphics_Component::recieve (int message)
{
}

//
// update
//
void Player_Graphics_Component::update (Game_Object & object, Game_World & world, Camera & camera)
{
  camera.draw(object, R, G, B, A);
}
