// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Co2dz_Game_Options.h"

//
// Co2dz_Game_Options
//
Co2dz_Game_Options::Co2dz_Game_Options (void)
{
}

//
// ~Co2dz_Game_Options
//
Co2dz_Game_Options::~Co2dz_Game_Options (void)
{
}

//
// initialize
//
void Co2dz_Game_Options::initialize (void)
{
}

//
// load
//
void Co2dz_Game_Options::load (void)
{
}

//
// restart
//
void Co2dz_Game_Options::restart (void)
{
}

//
// handle event
//
void Co2dz_Game_Options::handle_event (SDL_Event e)
{
  this->events_.push(e);
}

//
// update
//
void Co2dz_Game_Options::update (void)
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
void Co2dz_Game_Options::draw (SDL_Renderer & renderer, Uint32 lag)
{
}
