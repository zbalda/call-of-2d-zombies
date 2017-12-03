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

// using strings, IO streams, and string streams
#include <string>
#include <iostream>
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

class Framework
{
public:
    /// default constructor
    Framework (void);

    /// destructor
    ~Framework (void);

    /**
     * Start the game.
     */
    void start (void);

protected:
    /**
     * Initialize SDL.
     */
    void initialize (void);

    /**
     * Load media.
     */
    void load (void);

    /**
     * Free media and close SDL.
     */
    void close (void);

    /**
     * Start the game loop.
     */
    void game_loop (void);

    /**
     * Start a new game.
     */
    void new_game (void);

    /**
     * Restart the game.
     */
    void restart_game (void);

private:
    // the window to render to
    SDL_Window * window_;

    // the window renderer
    SDL_Renderer * renderer_;

    // globally used font
    TTF_Font * font_;

    // game state objects
    Co2dz_Game_Menu * game_menu_;
    Co2dz_Game_World * game_world_;
    Co2dz_Game_Over * game_over_;

    // game states
    enum game_states_ { MAIN_MENU, PLAYING, OPTIONS, GAMEOVER };;

    // current game states
    game_states_ game_state_;
};

#endif  //  !defined _FRAMEWORK_H_
