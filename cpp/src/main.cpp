// Honor Pledge:
//
// I pledge that I have neither given nor
// revieved any help on this assignment.
//
// zbalda

#include "Framework.h"

int main ( int argc, char* args[] )
{
  // create framework
  Framework * co2dz = new Framework();
  
	// play the game
	co2dz->start();

	// delete the game
	delete co2dz;

  return 0;
}
