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
Game_Object::Game_Object (std::vector<Component*> components, int x, int y, int vel_x, int vel_y, int max_velocity, int height, int width)
  : components_ (components)
  , x_ (x)
  , y_ (y)
  , vel_x_ (vel_x)
  , vel_y_ (vel_y)
  , max_velocity_ (max_velocity)
  , height_ (height)
  , width_ (width)
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
  // for copying components
  std::vector <Component*> components;

  // copy components
  for(Uint32 i = 0; i < components_.size(); i++) {
    components.push_back(components_[i]->clone());
  }

  // return copy of game object
  return new Game_Object(components, this->x_, this->y_, this->vel_x_, this->vel_y_, this->max_velocity_, this->height_, this->width_);
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
