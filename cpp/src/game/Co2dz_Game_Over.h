// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _CO2DZ_GAME_OVER_H_
#define _CO2DZ_GAME_OVER_H_

#include "Game_Over.h"

class Co2dz_Game_Over : public Game_Over
{
public:
    /// default constructor
    Co2dz_Game_Over (void);

    /// destructor
    ~Co2dz_Game_Over (void);

    // initialize and load media
    virtual void initialize (void);
    virtual void load (void);

    // restart the game
    virtual void restart (void);

    // update and draw
    virtual void update (void);
    virtual void draw (SDL_Renderer & renderer, Uint32 lag);
};

#endif  //  !defined _CO2DZ_GAME_OVER_H_
