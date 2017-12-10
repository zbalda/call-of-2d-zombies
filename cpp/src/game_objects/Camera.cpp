// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Camera.h"

#include "Game_Object.h"

//
// Camera
//
Camera::Camera (int elasticity, int x, int y)
  : renderer_ (0)
  , elasticity_ (elasticity)
  , x_ (x)
  , y_ (y)
{
}

//
// ~Camera
//
Camera::~Camera (void)
{
}

//
// update
//
void Camera::update (SDL_Renderer & renderer, Game_Object & actor)
{
  this->renderer_ = &renderer;
}

//
// draw
//
void Camera::draw (Game_Object & object, Uint32 R, Uint32 G, Uint32 B, Uint32 A)
{
  
}
