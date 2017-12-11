// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#ifndef _GAME_OBECT_FACTORY_H_
#define _GAME_OBECT_FACTORY_H_

#include "../Game_Object.h"

/**
 * @class Game_Object_Factory
 *
 * An interface for creating game objects.
 */
class Game_Object_Factory
{
public:
    // virtual destructor
    virtual ~Game_Object_Factory (void) { }

    // virtual game object creation methods
    virtual Game_Object * create_player (void) = 0;
    virtual Game_Object * create_enemy (int x, int y) = 0;
    virtual Game_Object * create_terrain (int r, int g, int b, int a) = 0;
};

#endif  // !defined _GAME_OBECT_FACTORY_H_
