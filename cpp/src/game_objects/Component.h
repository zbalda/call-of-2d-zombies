// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

class Component
{
public:
  // virtual destructor
  virtual ~Component (void) { }

  // recieve message broadcasted by Game_Object
  virtual void recieve (int message) = 0;
}

#endif  //  !defined _COMPONENT_H_
