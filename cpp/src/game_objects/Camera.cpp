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
  // TODO: use screen size to dynamically render
  if(0) { // if object is on screen
    // calculate rectangle coordinates
    int x = 0; //x coordinate of rectangle on screen
    int y = 0; //y coordinate of rectangle on screen

    // render rectangle
    SDL_Rect object_rectangle = { x, y, object.get_width(), object.get_height() };
    SDL_SetRenderDrawColor( this->renderer_, R, G, B, A );
    SDL_RenderFillRect( this->renderer_, &object_rectangle );
  }
}
