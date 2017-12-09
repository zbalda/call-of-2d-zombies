// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GAME_H_
#define _GAME_H_

// using SDL, SDL_image, and SDL_ttf
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// using strings, IO streams, and string streams
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Game
{
public:
    /// virtual destructor
    virtual ~Game (void) { }

    // initialize and load media
    virtual void initialize (void) = 0;
    virtual void load (void) = 0;

    // restart the game
    virtual void restart (void) = 0;

    // handle event
    virtual void handle_event (SDL_Event e) = 0;

    // update and draw
    virtual void update (void) = 0;

    virtual void draw (SDL_Renderer & renderer, Uint32 lag) = 0;
};

#endif  //  !defined _GAME_H_
