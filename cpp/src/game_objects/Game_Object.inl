// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#define MAX_VELOCITY 3

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
// move
//
inline
void Game_Object::move (void)
{
  // move object by its velocities
  this->x_ += this->vel_x_;
  this->y_ += this->vel_y_;
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

//
// set_vel_x
//
inline
void Game_Object::set_vel_x (int vel_x)
{
  // change velocity by amount
  this->vel_x_ = vel_x;

  // cap velocity
  if(this->vel_x_ > MAX_VELOCITY) {
    this->vel_x_ = MAX_VELOCITY;
  } else if (this->vel_x_ < 0 - MAX_VELOCITY) {
    this->vel_x_ = 0 - MAX_VELOCITY;
  }
}

//
// set_vel_y
//
inline
void Game_Object::set_vel_y (int vel_y)
{
  // change velocity by amount
  this->vel_y_ = vel_y;

  // cap velocity
  if(this->vel_y_ > MAX_VELOCITY) {
    this->vel_y_ = MAX_VELOCITY;
  } else if (this->vel_y_ < 0 - MAX_VELOCITY) {
    this->vel_y_ = 0 - MAX_VELOCITY;
  }
}

//
// get_height
//
inline
int Game_Object::get_height (void) const
{
  return this->height_;
}

//
// get_width
//
inline
int Game_Object::get_width (void) const
{
  return this->width_;
}
