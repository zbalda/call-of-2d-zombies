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
  : gWindow (NULL)
  , gRenderer (NULL)
  , gFont (NULL)
  , gTimeTextTexture (NULL)
  , gPromptTextTexture (NULL)
{
  this->initialize();
  this->loadMedia();
}

//
// ~Framework
//
Framework::~Framework (void)
{
  // TODO: delete game
  // destroy media and close SDL
  this->close();
}

//
// initialize
//
bool Framework::initialize (void)
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
		gWindow = SDL_CreateWindow( "Call of 2D Zombies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			// create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				// initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

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

	return success;
}

//
// load
//
bool Framework::load (void)
{
  // loading success flag
	bool success = true;

	// open the font
	gFont = TTF_OpenFont( "open-sans/OpenSans-Regular.ttf", 28 );
	if( gFont == NULL )
	{
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		// set text color as black
		SDL_Color textColor = { 0, 0, 0, 255 };

		// load prompt texture
		if( !gPromptTextTexture.loadFromRenderedText( "Press Enter to Reset Start Time.", textColor, gFont, gRenderer ) )
		{
			printf( "Unable to render prompt texture!\n" );
			success = false;
		}
	}

	return success;
}

//
// close
//
void Framework::close (void)
{
  // free loaded images
	gTimeTextTexture.free();
	gPromptTextTexture.free();

	// free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	// destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

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
  
}

//
// draw
//
void Framework::draw (void)
{
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
void Framework::close (void)
{
}
