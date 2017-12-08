// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Game_Object.h"

//
// Game_Object
//
Game_Object::Game_Object (std::vector<Component> components)
{
}

//
// ~Game_Object
//
Game_Object::~Game_Object (void)
{
}

//
// update
//
void Game_Object::update (Game_World & world, Game_Object & camera)
{
}

//
// send
//
void Game_Object::send (int message)
{
}

//
// is_alive
//
bool Game_Object::is_alive (void)
{
  return this->alive_;
}

//
// kill
//
void Game_Object::kill (void)
{
  this->alive_ = false;
}

//
// add_component
//
void Game_Object::add_component (Component & component)
{
}

//
// remove_component
//
void Game_Object::remove_component (size_t index)
{
}

//
// get_x
//
int Game_Object::get_x (void)
{
  return this->x_;
}

//
// get_y
//
int Game_Object::get_y (void)
{
  return this->y_;
}

//
// get_vel_x
//
int Game_Object::get_vel_x (void)
{
  return this->vel_x_;
}

//
// get_vel_y
//
int Game_Object::get_vel_y (void)
{
  return this->vel_y_;
}
