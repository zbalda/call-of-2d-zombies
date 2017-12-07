// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Co2dz_Game_World.h"

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
  this->events_.push(e);
}

//
// update
//
void Co2dz_Game_World::update (void)
{
  // event handler
	SDL_Event e;

	// process input
	while(!this->events_.empty()) {
		e = this->events_.front();
		this->events_.pop();
	}

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
