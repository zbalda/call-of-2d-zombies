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
  // horizontal and vertical distances between objects
  double horizontal_dist = world.get_player_x() - object.get_x();
  double vertical_dist = world.get_player_y() - object.get_y();

  // distance between objects
  double hypotenuse = sqrt((pow(horizontal_dist, 2.0)) + (pow(vertical_dist, 2.0)));

  // calculate horizontal and vertical magnitudes
  double horizontal_magnitude;
  double vertical_magnitude;
  if(hypotenuse == 0.0){
    horizontal_magnitude = 0.0;
    vertical_magnitude = 0.0;
  } else {
    horizontal_magnitude = horizontal_dist / hypotenuse;
    vertical_magnitude = vertical_dist / hypotenuse;
  }

  // follow player
  object.set_vel_x((int)(horizontal_magnitude * (double)object.get_max_velocity()));
  object.set_vel_y((int)(vertical_magnitude * (double)object.get_max_velocity()));

  // move and check collision
  object.move();
  world.resolve_collision(object);
}
