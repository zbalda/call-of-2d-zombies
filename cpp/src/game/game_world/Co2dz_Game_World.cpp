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
  , collision_counter_ (0)
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
  for(int i = 0; i < this->objects_.size(); i++) {
    if(this->objects_[i] != 0) {
      delete this->objects_[i];
    }
  }

  // delete all game object spawners
  for(int i = 0; i < this->spawners_.size(); i++) {
    if(this->spawners_[i] != 0) {
      delete this->spawners_[i];
    }
  }
}

//
// initialize
//
void Co2dz_Game_World::initialize (void)
{
  // create camera, player, and terrain texture
  this->camera_ = new Camera (15, -500, 600);
  this->player_ = this->game_object_factory_->create_player();
  this->terrain_texture_ = this->game_object_factory_->create_terrain(245, 245, 245, 355);

  // TODO: read from file or database to build terrain and spawners
  // explicitly create spawners
  Game_Object * prototype1 = this->game_object_factory_->create_enemy(2500, 2000, 3, 100, 100, 95, 100, 80, 355);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype1, 200));

  Game_Object * prototype2 = this->game_object_factory_->create_enemy(-2000, 3000, 4, 70, 70, 190, 60, 70, 355);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype2, 220));

  Game_Object * prototype3 = this->game_object_factory_->create_enemy(-2250, -2750, 5, 45, 45, 75, 160, 100, 355);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype3, 180));

  Game_Object * prototype4 = this->game_object_factory_->create_enemy(3500, -3000, 6, 30, 30, 160, 190, 55, 355);
  this->spawners_.push_back(new Game_Object_Spawner(*prototype4, 240));
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
  this->collision_counter_ = 0;
  this->player_->update(*this, *this->camera_);

  // update game objects
  for(int i = 0; i < this->objects_.size(); i++) {
    this->collision_counter_ += 1;
    if(this->objects_[i]->is_alive()) {
      this->objects_[i]->update(*this, *this->camera_);
    }
  }

  // update spawners
  for(int i = 0; i < this->spawners_.size(); i++) {
    this->spawners_[i]->update(&this->objects_);
  }

  // delete all dead game objects
  for(int i = 0; i < this->objects_.size(); i++) {
    if(!this->objects_[i]->is_alive()) {
      delete objects_[i];
      this->objects_.erase(this->objects_.begin() + i);
    }
  }
}

//
// resolve_collision
//
void Co2dz_Game_World::resolve_collision (Game_Object & object)
{
  // resolve collision
  for(int i = this->collision_counter_; i < this->objects_.size(); i++) {
    // check if objects collide
    if( object.get_x() < this->objects_[i]->get_x() + this->objects_[i]->get_width() &&
        object.get_x() + object.get_width() > this->objects_[i]->get_x() &&
        object.get_y() > this->objects_[i]->get_y() - this->objects_[i]->get_height() &&
        object.get_y() - object.get_height() < this->objects_[i]->get_y() ) {

      // calculate velocity angles
      double vel_angle_1 = atan2(object.get_vel_y(), object.get_vel_x());
      if(vel_angle_1 < 0) {
        vel_angle_1 += 2 * M_PI;
      }
      double vel_angle_2 = atan2(this->objects_[i]->get_vel_y(), this->objects_[i]->get_vel_x());
      if(vel_angle_2 < 0) {
        vel_angle_2 += 2 * M_PI;
      }

      // check if objects are moving toward each other
      double angle = vel_angle_1 - vel_angle_2;
      if( (angle < 0 - M_PI / 2) || (angle > M_PI / 2) ) {
        // handle collision by swapping velocities
        int temp_vel_x = object.get_vel_x();
        int temp_vel_y = object.get_vel_y();
        object.set_vel_x(this->objects_[i]->get_vel_x());
        object.set_vel_y(this->objects_[i]->get_vel_y());
        this->objects_[i]->set_vel_x(temp_vel_x);
        this->objects_[i]->set_vel_y(temp_vel_y);
      }
    }
  }
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
  // TODO: dynamically render map (i.e. only render part of map camera can see)

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
