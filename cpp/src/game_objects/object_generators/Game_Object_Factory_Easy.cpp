// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// zbalda

#include "Game_Object_Factory_Easy.h"

// constructor
Game_Object_Factory_Easy::Game_Object_Factory_Easy (void)
{
}

// virtual destructor
Game_Object_Factory_Easy::~Game_Object_Factory_Easy (void)
{
}

//
// create_player
//
Game_Object * Game_Object_Factory_Easy::create_player (void)
{
  // create player
  std::vector<Component*> components;
  components.push_back(new Player_Input_Component());
  components.push_back(new Player_Physics_Component());
  components.push_back(new Player_Graphics_Component(66, 134, 244, 255));
  return new Game_Object (components, 0, 0, 0, 0, 10, 40, 40);
}

//
// create_enemy
//
Game_Object * Game_Object_Factory_Easy::create_enemy (int x, int y, int speed, int height, int width, int r, int g, int b, int a)
{
  // create enemy
  std::vector<Component*> components;
  components.push_back(new Enemy_AI_Component());
  components.push_back(new Player_Graphics_Component(r, g, b, a));
  return new Game_Object (components, x, y, 0, 0, speed, height, width);
}

//
// create_terrain
//
Game_Object * Game_Object_Factory_Easy::create_terrain (int r, int g, int b, int a)
{
  // create terrain
  std::vector<Component*> components;
  components.push_back(new Player_Graphics_Component(r, g, b, a));
  return new Game_Object (components, 0, 0, 0, 0, 0, 0, 0);
}
