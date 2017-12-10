// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Game_Object.h"

// includes for forward declarations
#include "../game/game_world/Game_World.h"
#include "components/Component.h"
#include "Camera.h"

//
// Game_Object
//
Game_Object::Game_Object (std::vector<Component*> components, int x, int y, int vel_x, int vel_y)
  : components_ (components)
  , x_ (x)
  , y_ (y)
  , vel_x_ (vel_x)
  , vel_y_ (vel_y)
  , alive_ (true)
{
}

//
// ~Game_Object
//
Game_Object::~Game_Object (void)
{
  for(size_t i = 0; i < this->components_.size(); i++) {
    delete this->components_[i];
  }
}

//
// update
//
void Game_Object::update (Game_World & world, Camera & camera)
{
  for(size_t i = 0; i < this->components_.size(); i++) {
    this->components_[i]->update(*this, world, camera);
  }
}

//
// clone
//
Game_Object * Game_Object::clone (void)
{
  // TODO: add copy constructor to components and copy
  return new Game_Object(components_, this->x_, this->y_, this->vel_x_, this->vel_y_);
}

//
// send
//
void Game_Object::send (int message)
{
  for(size_t i = 0; i < this->components_.size(); i++) {
    this->components_[i]->recieve(message);
  }
}
