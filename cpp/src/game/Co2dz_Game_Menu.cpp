// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Co2dz_Game_Menu.h"

//
// Co2dz_Game_Menu
//
Co2dz_Game_Menu::Co2dz_Game_Menu (void)
{
}

//
// ~Co2dz_Game_Menu
//
Co2dz_Game_Menu::~Co2dz_Game_Menu (void)
{
	// TODO: remove repeated code between Co2dz Game destructors
	// free global font
	TTF_CloseFont(this->font_);
	this->font_ = NULL;

	// quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
}

//
// initialize
//
void Co2dz_Game_Menu::initialize (void)
{
	// TODO: remove repeated initialize code between Co2dz Game classes
	// initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags)) {
    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
    throw std::exception();
	}

	 // initialize SDL_ttf
	if(TTF_Init() == -1) {
    std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    throw std::exception();
	}
}

//
// load
//
void Co2dz_Game_Menu::load (void)
{
	// TODO: remove repeated load code between Co2dz Game classes
  // open the font
	this->font_ = TTF_OpenFont("../resources/open-sans/OpenSans-Regular.ttf", 28);
  if(this->font_ == NULL) {
    std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
    throw std::exception();
	}
}

//
// restart
//
void Co2dz_Game_Menu::restart (void)
{
}

//
// update
//
void Co2dz_Game_Menu::update (void)
{
}

//
// draw
//
void Co2dz_Game_Menu::draw (SDL_Renderer & renderer, float lag)
{
	// set text color as black
	SDL_Color text_color = { 0, 0, 0, 255 };

	// in memory text stream
	std::stringstream time_text;

	time_text.str("");
	time_text << "Milliseconds since start time " << lag;

	//TODO: render text
}
