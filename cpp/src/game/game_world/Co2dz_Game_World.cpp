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
  : events_ (0)
  , game_object_factory_ (0)
  , camera_ (0)
  , player_ (0)
  , objects_ (0)
  , spawners_ (0)
  , terrain_texture_ (0)
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
  delete this->terrain_texture_;

  // delete all game objects
  for(int i = 0; i < objects_.size(); i++) {
    delete objects_[i];
  }

  // delete all game object spawners
  for(int i = 0; i < spawners_.size(); i++) {
    delete spawners_[i];
  }
}

//
// initialize
//
void Co2dz_Game_World::initialize (void)
{
  // TODO: read from file or database to build terrain and spawners

  this->camera_ = new Camera (15, -500, 600);
  this->player_ = this->game_object_factory_->create_player();
  this->terrain_texture_ = this->game_object_factory_->create_terrain(245, 245, 245, 355);

  // explicitly create spawners
  Game_Object * prototype1 = this->game_object_factory_->create_enemy(100, 100);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype, 200));

  Game_Object * prototype2 = this->game_object_factory_->create_enemy(-100, 100);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype, 220));

  Game_Object * prototype3 = this->game_object_factory_->create_enemy(-100, -100);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype, 180));

  Game_Object * prototype4 = this->game_object_factory_->create_enemy(100, -100);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype, 240));
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
  // clear event list
  this->events_.clear();

  // event handler
  SDL_Event e;

  // process input
  for(std::vector<SDL_Event>::iterator it = this->events_.begin(); it != this->events_.end(); it++) {
		e = *it;
    if(e.type == SDL_KEYDOWN) {
    }
	}

  // draw map
  this->draw_map();

  // update camera to follow player
  this->camera_->update(renderer, screen_width, screen_height, *this->player_);

  // update player
  this->player_->update(*this, *this->camera_);

  // update game objects
  for(Uint32 i = 0; i < this->objects_.size(); i++) {
    this->objects_[i]->update(*this, *this->camera_);
  }

  // update spawners
  for(Uint32 i = 0; i < this->spawners_.size(); i++) {
    this->spawners_[i]->update(this->objects_);
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

//
// draw_map
//
void Co2dz_Game_World::draw_map (void)
{
  // loop through and render all vertical bars
  this->terrain_texture_->set_y(5000);
  for(int i = -5000; i < 5000; i += 100) {
    this->terrain_texture_->set_x(i);
    this->terrain_texture_->set_width(50);
    this->terrain_texture_->set_height(10000);

    // update player
    this->terrain_texture_->update(*this, *this->camera_);
  }

  // loop through and render all horizontal bars
  this->terrain_texture_->set_x(-5000);
  for(int i = -5000; i < 5000; i += 100) {
    this->terrain_texture_->set_y(i);
    this->terrain_texture_->set_width(10000);
    this->terrain_texture_->set_height(50);

    // update player
    this->terrain_texture_->update(*this, *this->camera_);
  }
}
