// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Player_Physics_Component.h"

//
// Player_Physics_Component
//
Player_Physics_Component::Player_Physics_Component (void)
{
}

//
// ~Player_Physics_Component
//
Player_Physics_Component::~Player_Physics_Component (void)
{
}

//
// recieve
//
void Player_Physics_Component::recieve (int message)
{
}

//
// update
//
void Player_Physics_Component::update (Game_Object & object, Game_World & world, Camera & camera)
{
  object.move();
  if(world.resolve_collision(object)) {
    object.move_back();
  }
}

//
// clone
//
Component * Player_Physics_Component::clone (void)
{
  return new Player_Physics_Component();
}
