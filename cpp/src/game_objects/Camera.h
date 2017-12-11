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

#include <iostream>

class Game_Object;

class Camera
{
public:
  /// default constructor
  Camera (int elasticity, int x, int y);

  /// destructor
  ~Camera (void);

  // update renderer and camera
  void update (SDL_Renderer & renderer, int screen_width, int screen_height, Game_Object & actor);

  // draw object to screen
  void draw (Game_Object & object, int R, int G, int B, int A);

private:
  // the window renderer
  SDL_Renderer * renderer_;

  // screen width and height
  int screen_width_, screen_height_;

  // how "tightly" camera follows object
  int elasticity_;

  // camera position
  int x_, y_;
};

#endif  //  !defined _CAMERA_H_
