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
Game_Object::Game_Object (std::vector<Component> & components)
  : components_ (0)
  , x_ (0)
  , y_ (0)
  , vel_x_ (0)
  , vel_y_ (0)
  , alive_ (0)
{
  this->components_ = components;
  this->alive_ = true;
}

//
// ~Game_Object
//
Game_Object::~Game_Object (void)
{
  for(size_t i = 0; i < this->components_->size(); i++) {
    delete this->components_[i];
  }
  delete this->components_;
}

//
// update
//
void Game_Object::update (Game_World & world, Game_Object & camera)
{
  for(size_t i = 0; i < this->components_->size(); i++) {
    this->components_[i].update(world, camera);
  }
}

//
// send
//
void Game_Object::send (int message)
{
  for(size_t i = 0; i < this->components_->size(); i++) {
    this->components_[i].recieve(world, camera);
  }
}

//
// add_component
//
void Game_Object::add_component (Component & component)
{
  this->components_->push_back(component);
}

//
// remove_component
//
void Game_Object::remove_component (size_t index)
{
  this->components_->erase(index);
}
