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
	this->initialize();
	this->load();
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
	this->font_ = TTF_OpenFont("../resources/open-sans/OpenSans-Regular.ttf", 20);
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
	// set text color to black
	SDL_Color text_color = { 0, 0, 0, 255 };

	// set time string
	std::stringstream time_text;
	time_text.str("");
	time_text << "Milliseconds since start time " << lag;

	int w = 0;
	int h = 0;
	// render text
	SDL_Surface * text_surface = TTF_RenderText_Solid(this->font_, time_text.str().c_str(), text_color);
	if(text_surface != NULL) {
		SDL_Texture * text_texture = SDL_CreateTextureFromSurface(&renderer, text_surface);
		if(text_texture == NULL) {
			std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
		} else {
			w = text_surface->w;
			h = text_surface->h;
		}
		SDL_FreeSurface(text_surface);

		SDL_Rect render_quad = { (640 - w) / 2, (480 - h) / 2, text_surface->w, text_surface->h };
		SDL_Rect * clip = NULL;
		double angle = 0.0;
		SDL_Point * center = NULL;
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		SDL_RenderCopyEx(&renderer, text_texture, clip, &render_quad, angle, center, flip);

		if( text_texture != NULL )
		{
			SDL_DestroyTexture( text_texture );
			text_texture = NULL;
		}
	} else {
		std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
	}
}
