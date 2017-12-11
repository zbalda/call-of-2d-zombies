// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#ifndef _GAME_OBECT_FACTORY_EASY_H_
#define _GAME_OBECT_FACTORY_EASY_H_

#include "Game_Object_Factory.h"

#include <vector>

#include "../components/graphics_components/Player_Graphics_Component.h"
#include "../components/input_components/Player_Input_Component.h"
#include "../components/physics_components/Player_Physics_Component.h"
#include "../components/ai_components/Enemy_AI_Component.h"

/**
 * @class Game_Object_Factory_Easy
 *
 * An factory for creating game objects.
 */
class Game_Object_Factory_Easy
{
public:
    // constructor
    Game_Object_Factory_Easy (void);

    // virtual destructor
    virtual ~Game_Object_Factory_Easy (void);

    // virtual game object creation methods
    virtual Game_Object * create_player (void);
    virtual Game_Object * create_enemy (int x, int y);
    virtual Game_Object * create_terrain (int r, int g, int b, int a);
};

#endif  // !defined _GAME_OBECT_FACTORY_EASY_H_
