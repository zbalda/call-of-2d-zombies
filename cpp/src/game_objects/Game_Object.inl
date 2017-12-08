// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

//
// is_alive
//
inline
bool Game_Object::is_alive (void) const
{
  return this->alive_;
}

//
// kill
//
inline
void Game_Object::kill (void)
{
  this->alive_ = false;
}

//
// get_x
//
inline
int Game_Object::get_x (void) const
{
  return this->x_;
}

//
// get_y
//
inline
int Game_Object::get_y (void) const
{
  return this->y_;
}

//
// get_vel_x
//
inline
int Game_Object::get_vel_x (void) const
{
  return this->vel_x_;
}

//
// get_vel_y
//
inline
int Game_Object::get_vel_y (void) const
{
  return this->vel_y_;
}
