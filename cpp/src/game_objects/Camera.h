// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _CAMERA_H_
#define _CAMERA_H_

// using SDL
#include <SDL2/SDL.h>

class Game_Object;

class Camera
{
public:
  /// default constructor
  Camera (int elasticity, int x, int y);

  /// destructor
  ~Camera (void);

  /*
   * Updates each component.
   *
   * param[in]    world     Game world
   * param[in]    camera    Camera to render to
   */
  void update (Game_Object & actor);

  // TODO: take in renderer to render object to
  /*
   * Draws rectangle if it is visable by camera.
   *
   * param[in]    object    Rectangle object to draw
   * param[in]    x         x coordinate of rectangle
   * param[in]    y         y coordinate of rectangle
   */
  void draw (SDL_Rect object, int x, int y);

private:
  // how "tightly" camera follows object
  int elasticity_;

  // camera position
  int x_, y_;
};

#endif  //  !defined _CAMERA_H_
