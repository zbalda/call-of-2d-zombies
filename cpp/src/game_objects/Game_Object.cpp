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
Game_Object::Game_Object (std::vector<Component> & components, int x, int y, int vel_x, int vel_y, bool alive)
  : components_ (components)
  , x_ (x)
  , y_ (y)
  , vel_x_ (vel_x)
  , vel_y_ (vel_y)
  , alive_ (alive)
{
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
    this->components_[i].update(*this, world, camera);
  }
}

//
// clone
//
Game_Object * clone (void)
{
  // TODO: add copy constructor to components and copy
  return new Game_Object(this->components_, this->x, this->y, this->vel_x_, this->vel_y_, this->alive_)
}

//
// send
//
void Game_Object::send (int message)
{
  for(size_t i = 0; i < this->components_->size(); i++) {
    this->components_[i].recieve(*this, world, camera);
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
