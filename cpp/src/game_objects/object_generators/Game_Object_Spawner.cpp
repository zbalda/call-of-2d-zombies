// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Game_Object_Spawner.h"

//
// Game_Object_Spawner
//
Game_Object_Spawner::Game_Object_Spawner (Game_Object & prototype, int spawn_delay)
  : prototype_ (&prototype)
  , spawn_delay_ (spawn_delay)
  , timer_ (0)
{
}

//
// ~Game_Object_Spawner
//
Game_Object_Spawner::~Game_Object_Spawner (void)
{
  // remove prototype
  delete this->prototype_;
}

//
// spawn
//
Game_Object * Game_Object_Spawner::spawn (void)
{
  // spawn prototype
  return this->prototype_->clone();
}

//
// spawn
//
void Game_Object_Spawner::update(std::vector<Game_Object*> objects)
{
  // decrement timer
  this->timer_ -= 1;

  // if timer ends
  if(this->timer_ <= 0) {
    // spawn object
    objects.push_back(this->spawn());
    // reset timer
    this->timer_ = this->spawn_delay_;
  }
}

//
// spawn
//
int Game_Object_Spawner::get_spawn_delay (void)
{
  return this->spawn_delay_;
}

//
// spawn
//
void Game_Object_Spawner::set_spawn_delay (int spawn_delay)
{
  this->spawn_delay_ = spawn_delay;
}

//
// increase_spawn_delay
//
void Game_Object_Spawner::decrease_spawn_delay (int amount)
{
  // decrease spawn delay by amount
  this->spawn_delay_ -= amount;
  if(this->spawn_delay_ < 1) {
    this->spawn_delay_ = 1;
  }
}
