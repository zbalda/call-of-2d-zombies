// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GAME_MENU_H_
#define _GAME_MENU_H_

#include "Game.h"

class Game_Menu : public Game
{
public:
    /// virtual destructor
    virtual ~Game_Menu (void) { }

    // initialize and load media
    virtual void initialize (void) = 0;
    virtual void load (void) = 0;

    // restart the game
    virtual void restart (void) = 0;

    // update and draw
    virtual void update (void) = 0;
    virtual void draw (SDL_Renderer & renderer, Uint32 lag) = 0;
};

#endif  //  !defined _GAME_MENU_H_
