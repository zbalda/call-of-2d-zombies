// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Enemy_AI_Component.h"

//
// Enemy_AI_Component
//
Enemy_AI_Component::Enemy_AI_Component (void)
{
}

//
// ~Enemy_AI_Component
//
Enemy_AI_Component::~Enemy_AI_Component (void)
{
}

//
// recieve
//
void Enemy_AI_Component::recieve (int message)
{
}

//
// update
//
void Enemy_AI_Component::update (Game_Object & object, Game_World & world, Camera & camera)
{
  // calculate angle between enemy and player
  float radians = atan2(world.get_player_y() - object.get_y(), world.get_player_x() - object.get_x());

  // follow player
  object.set_vel_x(acos(radians) * object.get_max_velocity());
  object.set_vel_y(asin(radians) * object.get_max_velocity());

  // move and check collision
  object.move();
  world.resolve_collision(object);
}
