// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
    /// virtual destructor
    virtual ~Game (void) { }

    // initialize and load media
    virtual void initialize () = 0;
    virtual void load () = 0;

    // restart the game
    virtual void restart () = 0;

    // update and draw
    virtual void update () = 0;
    virtual void draw () = 0;
};

#endif  //  !defined _GAME_H_
