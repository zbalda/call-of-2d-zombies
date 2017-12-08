// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Co2dz_Game_Over.h"

//
// Co2dz_Game_Over
//
Co2dz_Game_Over::Co2dz_Game_Over (void)
{
}

//
// ~Co2dz_Game_Over
//
Co2dz_Game_Over::~Co2dz_Game_Over (void)
{
}

//
// initialize
//
void Co2dz_Game_Over::initialize (void)
{
}

//
// load
//
void Co2dz_Game_Over::load (void)
{
}

//
// restart
//
void Co2dz_Game_Over::restart (void)
{
}

//
// handle event
//	: events_ (0)

void Co2dz_Game_Over::handle_event (SDL_Event e)
{
  this->events_.push(e);
}

//
// update
//
void Co2dz_Game_Over::update (void)
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
void Co2dz_Game_Over::draw (SDL_Renderer & renderer, Uint32 lag)
{
}
