// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Co2dz_Game_World.h"

#include "../../game_objects/Game_Object.h"

//
// Co2dz_Game_World
//
Co2dz_Game_World::Co2dz_Game_World (void)
  : game_object_factory_ (0)
  , camera_ (0)
  , player_ (0)
  , objects_ (0)
{
  this->game_object_factory_ = (Game_Object_Factory*)(new Game_Object_Factory_Easy());
  this->initialize();
}

//
// ~Co2dz_Game_World
//
Co2dz_Game_World::~Co2dz_Game_World (void)
{
  // free data
  delete this->game_object_factory_;
  delete this->camera_;
  delete this->player_;

  // delete all game objects
  for(int i = 0; i < objects_.size(); i++) {
    delete objects_[i];
  }
}

//
// initialize
//
void Co2dz_Game_World::initialize (void)
{
  // TODO: read from file or database to build objects

  this->camera_ = new Camera (1, -200, 200);
  this->player_ = this->game_object_factory_->create_player();
}

//
// load
//
void Co2dz_Game_World::load (void)
{
}

//
// restart
//
void Co2dz_Game_World::restart (void)
{
}

//
// handle event
//
void Co2dz_Game_World::handle_event (SDL_Event e)
{
  this->events_.push_back(e);
}

//
// update
//
void Co2dz_Game_World::update (SDL_Renderer & renderer, Uint32 lag)
{
  // update camera to follow player
  this->camera_->update(renderer, *this->player_);

  // update player
  this->player_->update(*this, *this->camera_);

  // TODO: update game objects

  // event handler
	SDL_Event e;

	// process input
  for(std::vector<SDL_Event>::iterator it = this->events_.begin(); it != this->events_.end(); it++) {
		e = *it;
    if(e.type == SDL_KEYDOWN) {
      std::cout << "key pressed" << std::endl;
    }
	}
  this->events_.clear();
}

//
// resolve_collision
//
void Co2dz_Game_World::resolve_collision (Game_Object & object)
{
  // TODO: handle collision
}
