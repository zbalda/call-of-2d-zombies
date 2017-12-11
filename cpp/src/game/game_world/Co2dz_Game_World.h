// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _CO2DZ_GAME_WORLD_H_
#define _CO2DZ_GAME_WORLD_H_

#include "Game_World.h"
#include "../../game_objects/Camera.h"
#include "../../game_objects/object_generators/Game_Object_Factory.h"
#include "../../game_objects/object_generators/Game_Object_Factory_Easy.h"

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
    virtual void update (SDL_Renderer & renderer, Uint32 lag, Uint32 screen_width, Uint32 screen_height);

    // resolve collision
    virtual void resolve_collision (Game_Object & object);

    // get players x position
    virtual int get_player_x (void);

    // get players y position
    virtual int get_player_y (void);

    // draw map
    virtual void draw_map (void);

private:
  // event queue
  std::vector <SDL_Event> events_;

  // game object factory
  Game_Object_Factory * game_object_factory_;

  // camera
  Camera * camera_;

  // player
  Game_Object * player_;

  // game objects
  std::vector <Game_Object*> objects_;

  // terrain texture
  Game_Object * terrain_texture_;
};

#endif  //  !defined _CO2DZ_GAME_WORLD_H_
