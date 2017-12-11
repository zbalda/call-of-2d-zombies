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
Player_Graphics_Component::Player_Graphics_Component (int r, int g, int b, int a)
  : R (r)
  , G (g)
  , B (b)
  , A (a)
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
