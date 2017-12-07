// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Framework.h"

#define DEFAULT_SCREEN_WIDTH 640
#define DEFAULT_SCREEN_HEIGHT 480
#define MS_PER_UPDATE 16

//
// Framework
//
Framework::Framework (void)
  : window_ (NULL)
  , renderer_ (NULL)
  , game_menu_ (0)
  , game_world_ (0)
  , game_options_ (0)
  , game_over_ (0)
{
  // TODO: initialize game objects with screen size
  // create game state objects
  this->game_menu_ = new Co2dz_Game_Menu ();
  this->game_world_ = new Co2dz_Game_World ();
  this->game_options_ = new Co2dz_Game_Options ();
  this->game_over_ = new Co2dz_Game_Over ();

  // initialize SDL and load media
  this->initialize();

  // set game state to main menu
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
  delete this->game_options_;
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
}

//
// close
//
void Framework::close (void)
{
	// destroy window
	SDL_DestroyRenderer(this->renderer_);
	SDL_DestroyWindow(this->window_);
	this->window_ = NULL;
	this->renderer_ = NULL;

  // quit SDL
	SDL_Quit();
}

//
// game_loop
//
void Framework::game_loop (void)
{
	// timer
	Uint32 previous = SDL_GetTicks();
  Uint32 current = SDL_GetTicks();
  Uint32 elapsed = current - previous;
  Uint32 lag = 0;

  // main loop flag
	bool quit = false;

  // game loop
  while(!quit) {
    // update timer
    current = SDL_GetTicks();
    elapsed = current - previous;
    previous = current;
    lag += elapsed;

    // handle input
    quit = this->process_input();

    // update
    lag = this->update(lag);

    // render
    this->render(lag);
  }
}

//
// process_input
//
bool Framework::process_input (void)
{
  // event handler
	SDL_Event e;

  // process input
	while(SDL_PollEvent(&e) != 0) {
		// quit on user request
		if(e.type == SDL_QUIT) {
			return true;
		}
    // handle event
    switch(this->game_state_) {
      case MAIN_MENU :
        this->game_menu_->handle_event(e);
        break;
      case PLAYING :
        this->game_world_->handle_event(e);
        break;
      case OPTIONS :
        this->game_options_->handle_event(e);
        break;
      case GAME_OVER :
        this->game_over_->handle_event(e);
        break;
      default:
        std::cout << "Error: Invalid game state." << std::endl;
    }
  }

  // user did not quit
  return false;
}

//
// update
//
Uint32 Framework::update (Uint32 lag)
{
  // while not updated to current time
  while(lag >= MS_PER_UPDATE) {
    // update
    switch(this->game_state_) {
      case MAIN_MENU :
        this->game_menu_->update();
        break;
      case PLAYING :
        this->game_world_->update();
        break;
      case OPTIONS :
        this->game_options_->update();
        break;
      case GAME_OVER :
        this->game_over_->update();
        break;
      default:
        std::cout << "Error: Invalid game state." << std::endl;
    }
    // track update
    lag -= MS_PER_UPDATE;
  }
  return lag;
}

//
// render
//
void Framework::render (Uint32 lag)
{
  // clear screen
  SDL_SetRenderDrawColor(this->renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(this->renderer_);

  // render
  switch(this->game_state_) {
    case MAIN_MENU :
      this->game_menu_->draw(*this->renderer_, lag);
      break;
    case PLAYING :
      this->game_world_->draw(*this->renderer_, lag);
      break;
    case OPTIONS :
      this->game_world_->draw(*this->renderer_, 0);
      this->game_options_->draw(*this->renderer_, lag);
      break;
    case GAME_OVER :
      this->game_world_->draw(*this->renderer_, 0);
      this->game_over_->draw(*this->renderer_, lag);
      break;
    default:
      std::cout << "Error: Invalid game state." << std::endl;
  }

  // draw to screen
  SDL_RenderPresent(this->renderer_);
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
