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
  // how far enemy is horizontally and vertically
  int horisontal_dist = world.get_player_x() - object.get_x();
  int vertical_dist = world.get_player_y() - object.get_y();

  // prevent division by 0
  if(horisontal_dist == 0) {
    horisontal_dist = 1;
  }
  if(vertical_dist == 0) {
    vertical_dist = 1;
  }

  // follow player
  object.set_vel_x((horisontal_dist / vertical_dist) * object.get_max_velocity());
  object.set_vel_y((vertical_dist / horisontal_dist) * object.get_max_velocity());

  // move and check collision
  object.move();
  world.resolve_collision(object);
}
