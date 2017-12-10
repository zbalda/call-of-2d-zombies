// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _CO2DZ_GAME_MENU_H_
#define _CO2DZ_GAME_MENU_H_

#include "Game_Menu.h"

class Co2dz_Game_Menu : public Game_Menu
{
public:
    /// default constructor
    Co2dz_Game_Menu (void);

    /// destructor
    ~Co2dz_Game_Menu (void);

    // initialize and load media
    virtual void initialize (void);
    virtual void load (void);

    // restart the game
    virtual void restart (void);

    // handle event
    virtual void handle_event (SDL_Event e);

    // update and draw
    virtual void update (SDL_Renderer & renderer, Uint32 lag);

private:
    // globally used font
    TTF_Font * font_;

    // event queue
    std::vector <SDL_Event> events_;

    int timer; // REMOVE
};

#endif  //  !defined _CO2DZ_GAME_MENU_H_
