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
void Camera::update (SDL_Renderer & renderer, int screen_width, int screen_height, Game_Object & actor)
{
  // update renderer
  this->renderer_ = &renderer;

  // update screen width and heights
  screen_width_ = screen_width;
  screen_height_ = screen_height;

  if(elasticity_ != 0) {
    x_ += ((actor.get_x() + (actor.get_width() / 2)) - (this->x_ + (screen_width_ / 2))) / elasticity_;
    y_ += ((actor.get_y() - (actor.get_height() / 2))  - (this->y_ - (screen_height_ / 2))) / elasticity_;
  } else {
    x_ += (actor.get_x() - (actor.get_width() / 2)) - (this->x_ + (screen_width_ / 2));
    y_ += (actor.get_y() - (actor.get_height() / 2)) - (this->y_ - (screen_height_ / 2));
  }
}

//
// draw
//
void Camera::draw (Game_Object & object, int R, int G, int B, int A)
{
  // render rectangle
  SDL_Rect object_rectangle = { 0 - (this->x_ - object.get_x()), this->y_ - object.get_y(), object.get_width(), object.get_height() };
  SDL_SetRenderDrawColor( this->renderer_, R, G, B, A );
  SDL_RenderFillRect( this->renderer_, &object_rectangle );
}
