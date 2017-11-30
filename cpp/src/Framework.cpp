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
  , game_states_ (0)
{
  // create game state objects
  this->game_menu_ = new Co2dz_Game_Menu ();
  this->game_world_ = new Co2dz_Game_World ();
  this->game_over_ = new Co2dz_Game_Over ();

  // set game states
  this->game_states_ = { MAIN_MENU, PLAYING, OPTIONS, GAMEOVER };

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
  this->game_loop();
}

// TODO: Switch to using exception handling
//
// initialize
//
void Framework::initialize (void)
{
  // initialization flag
	bool success = true;

	// initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		// set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		// create window
		window_ = SDL_CreateWindow( "Call of 2D Zombies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window_ == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			// create vsynced renderer for window
			renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( renderer_ == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				// initialize renderer color
				SDL_SetRenderDrawColor( renderer_, 0xFF, 0xFF, 0xFF, 0xFF );

				// initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				 // initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}
}

// TODO: switch to using exception handling
//
// load
//
void Framework::load (void)
{
  // loading success flag
	bool success = true;

	// open the font
	font_ = TTF_OpenFont( "open-sans/OpenSans-Regular.ttf", 28 );
	if( font_ == NULL )
	{
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		// set text color as black
		SDL_Color textColor = { 0, 0, 0, 255 };

		// load prompt texture
		if( !gPromptTextTexture.loadFromRenderedText( "Press Enter to Reset Start Time.", textColor, font_, renderer_ ) )
		{
			printf( "Unable to render prompt texture!\n" );
			success = false;
		}
	}
}

//
// close
//
void Framework::close (void)
{
	// free global font
	TTF_CloseFont( font_ );
	font_ = NULL;

	// destroy window
	SDL_DestroyRenderer( renderer_ );
	SDL_DestroyWindow( window_ );
	window_ = NULL;
	renderer_ = NULL;

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
  bool quit = false;
  while(!quit) {
    // TODO: implement timer for game loop

    // clear screen
    SDL_SetRenderDrawColor(this->renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->renderer_);

    // update and draw appropriate game state objects
    switch(this->game_state_) {
      case MAIN_MENU :
        this->game_menu_->update();
        this->game_menu_->draw();
        break;
      case PLAYING :
        this->game_world_->update();
        this->game_world_->draw();
        break
      case OPTIONS :
        this->game_world_->draw();
        this->game_options_->update();
        this->game_options_->draw();
        break
      case GAME_OVER :
        this->game_world->draw();
        this->game_over_->update();
        this->game_over_->draw();
        break
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
