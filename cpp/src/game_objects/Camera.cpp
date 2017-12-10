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
void Camera::update (SDL_Renderer & renderer, Uint32 screen_width, Uint32 screen_height, Game_Object & actor)
{
  // update renderer
  this->renderer_ = &renderer;

  // update screen width and heights
  screen_width_ = screen_width;
  screen_height_ = screen_height;
}

//
// draw
//
void Camera::draw (Game_Object & object, Uint32 R, Uint32 G, Uint32 B, Uint32 A)
{
  // render rectangle
  SDL_Rect object_rectangle = { 0 - (this->x_ - object.get_x()), this->y_ - object.get_y(), object.get_width(), object.get_height() };
  SDL_SetRenderDrawColor( this->renderer_, R, G, B, A );
  SDL_RenderFillRect( this->renderer_, &object_rectangle );
}
