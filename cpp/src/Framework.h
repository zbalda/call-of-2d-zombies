// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _FRAMEWORK_H_
#define _FRAMEWORK_H_

// using SDL
#include <SDL2/SDL.h>

// using strings, IO streams, and string streams
#include <string>
#include <iostream>
#include <sstream>

// using Game, Game_Menu, Game_World, and Game_Over
#include "game/Game.h"
#include "game/game_menu/Game_Menu.h"
#include "game/game_world/Game_World.h"

// using Co2dz Game_Menu, Game_World, and Game_Over
#include "game/game_menu/Co2dz_Game_Menu.h"
#include "game/game_world/Co2dz_Game_World.h"

class Framework
{
public:
    /// default constructor
    Framework (void);

    /// destructor
    ~Framework (void);

    /**
     * Start the game loop.
     */
    void start (void);

protected:
    /**
     * Initialize SDL.
     */
    void initialize (void);

    /**
     * Free media and close SDL.
     */
    void close (void);

    /**
     * The main game loop.
     */
    void game_loop (void);

    /**
     * Process input.
     *
     * @return   true if user quits
     */
    bool process_input (void);

    /**
     * Update the game.
     *
     * @return   lag
     */
    Uint32 update (Uint32 lag);

    /**
     * Render the game.
     */
    void render (Uint32 lag);

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

    // game state objects
    Game_Menu * game_menu_;
    Game_World * game_world_;

    // game states
    enum game_states_ { MAIN_MENU, PLAYING };;

    // current game states
    game_states_ game_state_;
};

#endif  //  !defined _FRAMEWORK_H_
