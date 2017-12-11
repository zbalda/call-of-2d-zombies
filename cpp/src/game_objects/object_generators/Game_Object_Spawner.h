// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GAME_OBJECT_SPAWNER_H_
#define _GAME_OBJECT_SPAWNER_H_

#include "../Game_Object.h"

#include <iostream>

class Game_Object_Spawner {
public:
  // constructor
  Game_Object_Spawner (Game_Object & prototype, int spawn_delay);

  // destructor
  virtual ~Game_Object_Spawner (void);

  // create new object
  Game_Object * spawn (void);

  // update and possibly spawn
  void update (std::vector<Game_Object*> * objects);

  // get spawn delay
  int get_spawn_delay (void);

  // set spawn delay
  void set_spawn_delay (int spawn_delay);

  // decrease spawn delay
  void decrease_spawn_delay (int amount);

private:
  // object to clone
  Game_Object * prototype_;

  // spawn delay
  int spawn_delay_;

  // time since last spawn
  int timer_;
};

#endif  //  !defined _GAME_OBJECT_H_
