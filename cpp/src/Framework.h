// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _FRAMEWORK_H_
#define _FRAMEWORK_H_

// using SDL, SDL_image, and SDL_ttf
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// using standard IO, strings, and string streams
#include <stdio.h>
#include <string>
#include <sstream>

// using Game, Game_Menu, Game_World, and Game_Over
#include "game/Game.h"
#include "game/Game_Menu.h"
#include "game/Game_World.h"
#include "game/Game_Over.h"

// using Co2dz Game_Menu, Game_World, and Game_Over
#include "game/Co2dz_Game_Menu.h"
#include "game/Co2dz_Game_World.h"
#include "game/Co2dz_Game_Over.h"

// using LTexture
#include "game_objects/LTexture.h"

class Framework
{
public:
    /// default constructor
    Framework (void);

    /// destructor
    ~Framework (void);

protected:
    /**
     * Initialize SDL.
     */
    bool initialize (void);

    /**
     * Load media.
     */
    bool load (void);

    /**
     * Free media and close SDL.
     */
    void close (void);

    /**
     * Main game loop.
     */
    void game_loop (void);

    /**
     * Draw rendered game to screen.
     */
    void draw (void);

    /**
     * Start new game.
     */
    void new_game (void);

    /**
     * Restart the game.
     */
    void restart_game (void);

private:
    // the window to render to
    SDL_Window * gWindow;

    // the window renderer
    SDL_Renderer * gRenderer;

    // globally used font
    TTF_Font * gFont;

    //Scene textures
    LTexture gTimeTextTexture;
    LTexture gPromptTextTexture;
};

#endif  //  !defined _FRAMEWORK_H_



















int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set text color as black
			SDL_Color textColor = { 0, 0, 0, 255 };

			//Current time start time
			Uint32 startTime = 0;

			//In memory text stream
			std::stringstream timeText;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//Reset start time on return keypress
					else if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN )
					{
						startTime = SDL_GetTicks();
					}
				}

				//Set text to be rendered
				timeText.str( "" );
				timeText << "Milliseconds since start time " << SDL_GetTicks() - startTime;

				//Render text
				if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor, gFont, gRenderer ) )
				{
					printf( "Unable to render time texture!\n" );
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render textures
				gPromptTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, 0, gRenderer);
				gTimeTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gPromptTextTexture.getHeight() ) / 2, gRenderer );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
