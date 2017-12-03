// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GAME_H_
#define _GAME_H_

// using SDL
#include <SDL2/SDL.h>

// using strings
#include <string>

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

    // update and draw
    virtual void update (void) = 0;
    //virtual void draw (SDL_Renderer & renderer, float lag, std::string text) = 0;
    virtual void draw (SDL_Renderer & renderer) = 0;
};

#endif  //  !defined _GAME_H_
