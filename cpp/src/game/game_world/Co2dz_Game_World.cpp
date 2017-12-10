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

  this->camera_ = new Camera (0, -100, 100);
  this->player_ = this->game_object_factory_->create_player();
  this->objects_.push_back(this->game_object_factory_->create_enemy(100, 100));
  this->objects_.push_back(this->game_object_factory_->create_enemy(200, 800));
  this->objects_.push_back(this->game_object_factory_->create_enemy(500, -200));
  this->objects_.push_back(this->game_object_factory_->create_enemy(1000, 400));
  this->objects_.push_back(this->game_object_factory_->create_enemy(-100, 650));
  this->objects_.push_back(this->game_object_factory_->create_enemy(900, 900));
  this->objects_.push_back(this->game_object_factory_->create_enemy(100, 600));
  this->objects_.push_back(this->game_object_factory_->create_enemy(0, -350));
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
void Co2dz_Game_World::update (SDL_Renderer & renderer, Uint32 lag, Uint32 screen_width, Uint32 screen_height)
{
  // event handler
  SDL_Event e;

  // process input
  for(std::vector<SDL_Event>::iterator it = this->events_.begin(); it != this->events_.end(); it++) {
		e = *it;
    if(e.type == SDL_KEYDOWN) {
    }
	}
  this->events_.clear();

  // update camera to follow player
  this->camera_->update(renderer, screen_width, screen_height, *this->player_);

  // update player
  this->player_->update(*this, *this->camera_);

  for(Uint32 i = 0; i < this->objects_.size(); i++) {
    this->objects_[i]->update(*this, *this->camera_);
  }
}

//
// resolve_collision
//
void Co2dz_Game_World::resolve_collision (Game_Object & object)
{
  // TODO: handle collision
}

//
// get_player_x
//
int Co2dz_Game_World::get_player_x (void)
{
  return this->player_->get_x();
}

//
// get_player_y
//
int Co2dz_Game_World::get_player_y (void)
{
  return this->player_->get_y();
}
