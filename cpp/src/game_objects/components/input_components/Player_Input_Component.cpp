// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Player_Input_Component.h"

//
// Player_Input_Component
//
Player_Input_Component::Player_Input_Component (void)
{
}

//
// ~Player_Input_Component
//
Player_Input_Component::~Player_Input_Component (void)
{
}

//
// recieve
//
void Player_Input_Component::recieve (int message)
{
}

//
// update
//
void Player_Input_Component::update (Game_Object & object, Game_World & world, Camera & camera)
{
  // get key states
  const Uint8* key_states = SDL_GetKeyboardState(NULL);

  // update velocity
  int new_velocity;
  if(!(key_states[SDL_SCANCODE_UP] || key_states[SDL_SCANCODE_DOWN] || key_states[SDL_SCANCODE_LEFT] || key_states[SDL_SCANCODE_RIGHT])) {
    if(object.get_vel_x() > 0) {
      new_velocity = object.get_vel_x() - ACCELERATION;
      object.set_vel_x(new_velocity);
    } else if(object.get_vel_x() < 0) {
      new_velocity = object.get_vel_x() + ACCELERATION;
      object.set_vel_x(new_velocity);
    }
    if(object.get_vel_y() > 0) {
      new_velocity = object.get_vel_y() - ACCELERATION;
      object.set_vel_y(new_velocity);
    } else if(object.get_vel_y() < 0) {
      new_velocity = object.get_vel_y() + ACCELERATION;
      object.set_vel_y(new_velocity);
    }
  } else {
    if(key_states[SDL_SCANCODE_UP]) {
      new_velocity = object.get_vel_y() + ACCELERATION;
      object.set_vel_y(new_velocity);
    }
    if(key_states[SDL_SCANCODE_DOWN]) {
      new_velocity = object.get_vel_y() - ACCELERATION;
      object.set_vel_y(new_velocity);
    }
    if(key_states[SDL_SCANCODE_LEFT]) {
      new_velocity = object.get_vel_x() - ACCELERATION;
      object.set_vel_x(new_velocity);
    }
    if(key_states[SDL_SCANCODE_RIGHT]) {
      new_velocity = object.get_vel_x() + ACCELERATION;
      object.set_vel_x(new_velocity);
    }
  }
}

//
// clone
//
Component * Player_Input_Component::clone (void)
{
  return new Player_Input_Component();
}
