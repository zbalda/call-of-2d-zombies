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
{
}

//
// ~Co2dz_Game_World
//
Co2dz_Game_World::~Co2dz_Game_World (void)
{
}

//
// initialize
//
void Co2dz_Game_World::initialize (void)
{
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
void Co2dz_Game_World::update (void)
{
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

  // get key states
  const Uint8* key_states = SDL_GetKeyboardState(NULL);
  if(key_states[SDL_SCANCODE_UP]) {
    std::cout << "up button" << std::endl;
  }
}

//
// draw
//
void Co2dz_Game_World::draw (SDL_Renderer & renderer, Uint32 lag)
{
}
