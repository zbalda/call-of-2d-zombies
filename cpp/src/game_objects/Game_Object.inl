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
// move
//
inline
void Game_Object::move (void)
{
  // track previous position
  this->prev_x_ = this->x_;
  this->prev_y_ = this->y_;

  // move object by its velocities
  this->x_ += this->vel_x_;
  this->y_ += this->vel_y_;
}

//
// move_back
//
inline
void Game_Object::move_back (void)
{
  // move object back
  this->x_ = this->prev_x_;
  this->y_ = this->prev_y_;
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
// set_x
//
inline
int Game_Object::set_x (int x)
{
  this->x_ = x;
}

//
// set_y
//
inline
int Game_Object::set_y (int y)
{
  this->y_ = y;
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
  if(this->vel_x_ > max_velocity_) {
    this->vel_x_ = max_velocity_;
  } else if (this->vel_x_ < 0 - max_velocity_) {
    this->vel_x_ = 0 - max_velocity_;
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
  if(this->vel_y_ > max_velocity_) {
    this->vel_y_ = max_velocity_;
  } else if (this->vel_y_ < 0 - max_velocity_) {
    this->vel_y_ = 0 - max_velocity_;
  }
}

//
// get_max_velocity
//
inline
int Game_Object::get_max_velocity (void)
{
  return max_velocity_;
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

//
// set_height
//
inline
int Game_Object::set_height (int height)
{
  this->height_ = height;
}

//
// set_width
//
inline
int Game_Object::set_width (int width)
{
  this->width_ = width;
}
