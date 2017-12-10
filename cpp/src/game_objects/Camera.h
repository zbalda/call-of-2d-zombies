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
  void update (SDL_Renderer & renderer, Game_Object & actor);

  // TODO: take in renderer to render object to
  /*
   * Draws rectangle if it is visable by camera.
   *
   * param[in]    object    Rectangle object to draw
   */
  void draw (Game_Object & object, Uint32 R, Uint32 G, Uint32 B, Uint32 A);

private:
  // the window renderer
  SDL_Renderer * renderer_;

  // how "tightly" camera follows object
  int elasticity_;

  // camera position
  int x_, y_;
};

#endif  //  !defined _CAMERA_H_
