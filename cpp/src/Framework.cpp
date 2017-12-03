// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Framework.h"

#define DEFAULT_SCREEN_WIDTH 640
#define DEFAULT_SCREEN_HEIGHT 480

//
// Framework
//
Framework::Framework (void)
  : window_ (NULL)
  , renderer_ (NULL)
  , font_ (NULL)
  , game_menu_ (0)
  , game_world_ (0)
  , game_over_ (0)
{
  // create game state objects
  this->game_menu_ = new Co2dz_Game_Menu ();
  this->game_world_ = new Co2dz_Game_World ();
  this->game_over_ = new Co2dz_Game_Over ();

  // set game states
  //this->game_states_ = { MAIN_MENU, PLAYING, OPTIONS, GAMEOVER };

  // initialize SDL and load media
  this->initialize();
  this->load();

  this->game_state_ = MAIN_MENU;
}

//
// ~Framework
//
Framework::~Framework (void)
{
  // delete game state objects
  delete this->game_menu_;
  delete this->game_world_;
  delete this->game_over_;

  // destroy media and close SDL
  this->close();
}

//
// start
//
void Framework::start (void)
{
  // start game loop
  this->game_loop();
}

// TODO: Create and use own exception class
//
// initialize
//
void Framework::initialize (void)
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    throw std::exception();
	}

	// set texture filtering to linear
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	}

	// create window
	this->window_ = SDL_CreateWindow("Call of 2D Zombies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(this->window_ == NULL) {
    std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
    throw std::exception();
	}

	// create vsynced renderer for window
	this->renderer_ = SDL_CreateRenderer(this->window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(this->renderer_ == NULL) {
    std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
    throw std::exception();
	}

	// initialize renderer color
	SDL_SetRenderDrawColor(this->renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

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

// TODO: create and use exception class
// TODO: possibly remove load class. Should Game's just load media?
//
// load
//
void Framework::load (void)
{
  // open the font
	this->font_ = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 28);
	if(this->font_ == NULL) {
    std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
    throw std::exception();
	}
}

//
// close
//
void Framework::close (void)
{
	// free global font
	TTF_CloseFont(this->font_);
	this->font_ = NULL;

	// destroy window
	SDL_DestroyRenderer(this->renderer_);
	SDL_DestroyWindow(this->window_);
	this->window_ = NULL;
	this->renderer_ = NULL;

	// quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

//
// game_loop
//
void Framework::game_loop (void)
{
  // main loop flag
	bool quit = false;

	// event handler
	SDL_Event e;

	// set text color as black
	SDL_Color textColor = { 0, 0, 0, 255 };

	// current time start time
	Uint32 start_time = 0;

	// in memory text stream
	std::stringstream time_text;

  // game loop
  while(!quit) {
    // TODO: implement timer for game loop

    // handle events on queue
		while(SDL_PollEvent( &e ) != 0) {
  		// quit on user request
			if(e.type == SDL_QUIT) {
        quit = true;
			}
			// reset start time on return keypress
			else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
				start_time = SDL_GetTicks();
			}
		}

    // TODO: make Game draw() accept and display text
    // set text to be rendered
    time_text.str("");
    time_text << "Milliseconds since start time " << SDL_GetTicks() - start_time;

    // clear screen
    SDL_SetRenderDrawColor(this->renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->renderer_);

    // TODO: make Game draw() accept this->renderer_
    // update and draw appropriate game state objects
    switch(this->game_state_) {
      case MAIN_MENU :
        this->game_menu_->update();
        this->game_menu_->draw(this->renderer_);
        break;
      case PLAYING :
        this->game_world_->update();
        this->game_world_->draw(this->renderer_);
        break;
      case OPTIONS :
        this->game_world_->draw(this->renderer_);
        this->game_options_->update();
        this->game_options_->draw(this->renderer_);
        break;
      case GAME_OVER :
        this->game_world->draw(this->renderer_);
        this->game_over_->update();
        this->game_over_->draw(this->renderer_);
        break;
      default:
        std::cout << "Invalid game state case." << std::endl;
    }

    // update screen
    SDL_RenderPresent(this->renderer_);
  }
}

//
// new_game
//
void Framework::new_game (void)
{
}

//
// restart_game
//
void Framework::restart_game (void)
{
}
