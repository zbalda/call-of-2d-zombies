// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _CO2DZ_GAME_WORLD_H_
#define _CO2DZ_GAME_WORLD_H_

#include "Game_World.h"

class Co2dz_Game_World : public Game_World
{
public:
    /// default constructor
    Co2dz_Game_World (void);

    /// destructor
    ~Co2dz_Game_World (void);

    // initialize and load media
    virtual void initialize (void);
    virtual void load (void);

    // restart the game
    virtual void restart (void);

    // handle event
    virtual void handle_event (SDL_Event e);

    // update and draw
    virtual void update (void);
    virtual void draw (SDL_Renderer & renderer, Uint32 lag);

private:
  // event queue
  std::queue<SDL_Event> events_;
};

#endif  //  !defined _CO2DZ_GAME_WORLD_H_
