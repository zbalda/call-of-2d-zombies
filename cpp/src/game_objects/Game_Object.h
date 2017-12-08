// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

// using cstring and vector
#include <cstring>
#include <vector>

// using Game_Object and Game_World
#include "Game_Object.h"
#include "Component.h"
#include "../game/Game_World.h"


class Game_Object
{
public:
  /// default constructor
  Game_Object (std::vector<Component> & components);

  /// destructor
  ~Game_Object (void);

  /*
   * Updates each component.
   *
   * param[in]    world     Game world
   * param[in]    camera    Camera to render to
   */
  void update (Game_World & world, Game_Object & camera);

  /*
   * Broadcasts message to components.
   *
   * param[in]    message   Message code
   */
  void send (int message);

  /*
   * Checks if object is alive.
   *
   * @return  True if object is alive
   */
  bool is_alive (void);

  /*
   * Marks object as dead.
   */
  void kill (void);

  /*
   * Adds component to end of list.
   *
   * param[in]    component   Component to add
   */
  void add_component (Component & component);

  /*
   * Removes component at given index.
   *
   * param[in]    index   Component to remove
   */
  void remove_component (size_t index);

  /*
   * Get x position of object.
   *
   * @return    x    Objects x position
   */
  int get_x (void);

  /*
   * Get y position of object.
   *
   * @return    y   Objects y position
   */
  int get_y (void);

  /*
   * Get x velocity of object.
   *
   * @return    vel_x    Objects x velocity
   */
  int get_vel_x (void);

  /*
   * Get y velocity of object.
   *
   * @return    vel_y   Objects y velocity
   */
  int get_vel_y (void);

private:
  // object components
  std::vector <Component*> * components_;

  // object position
  int x_, y_;

  // object velocity
  int vel_x_, vel_y_;

  // for tracking if object is alive
  bool alive_;
}

#include "Game_Object.inl"

#endif  //  !defined _GAME_OBJECT_H_
