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

// forward declarations
class Game_World;
class Component;
class Camera;

class Game_Object
{
public:
  /// default constructor
  Game_Object (std::vector<Component*> components, int x, int y, int vel_x, int vel_y, int max_velocity, int height, int width);

  /// destructor
  ~Game_Object (void);

  /*
   * Updates each component.
   *
   * param[in]    world     Game world
   * param[in]    camera    Camera to render to
   */
  void update (Game_World & world, Camera & camera);

  /*
   * Clones self.
   *
   * @return    Clone of self
   */
  Game_Object * clone (void);

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
  bool is_alive (void) const;

  /*
   * Marks object as dead.
   */
  void kill (void);

  /*
   * Moves object by velocities.
   */
  void move (void);

  /*
   * Moves object back one step.
   */
  void move_back (void);

  /*
   * Get x position of object.
   *
   * @return    x_    Objects x position
   */
  int get_x (void) const;

  /*
   * Get y position of object.
   *
   * @return    y_   Objects y position
   */
  int get_y (void) const;

  /*
   * Set x position of object.
   */
  int set_x (int x);

  /*
   * set y position of object.
   */
  int set_y (int y);

  /*
   * Get x velocity of object.
   *
   * @return    vel_x_    Objects x velocity
   */
  int get_vel_x (void) const;

  /*
   * Get y velocity of object.
   *
   * @return    vel_y_    Objects y velocity
   */
  int get_vel_y (void) const;

  /*
   * Set x velocity of object.
   *
   * @param[in]    vel_x    Objects x velocity
   */
  void set_vel_x (int vel_x);

  /*
   * Set y velocity of object.
   *
   * @param[in]    vel_y   Objects y velocity
   */
  void set_vel_y (int vel_y);

  /*
   * Get max velocity.
   *
   * @return    Max velocity
   */
  int get_max_velocity (void);

  /*
   * Get height of object.
   *
   * @return    height_   Height of object
   */
  int get_height (void) const;

  /*
   * Get width of object.
   *
   * @return    width_    Width of object
   */
  int get_width (void) const;

  /*
   * Set height of object.
   */
  int set_height (int height);

  /*
   * Set width of object.
   */
  int set_width (int width);

private:
  // object components
  std::vector <Component*> components_;

  // object position
  int x_, y_;

  // objects previous position
  int prev_x_, prev_y_;

  // object velocity
  int vel_x_, vel_y_;

  // max velocity
  int max_velocity_;

  // object size
  int height_, width_;

  // for tracking if object is alive
  bool alive_;
};

#include "Game_Object.inl"

#endif  //  !defined _GAME_OBJECT_H_
