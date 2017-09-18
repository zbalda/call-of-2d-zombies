## NOTE: The Java version of this game has been depricated. See the C++ version for more features.

# Call of 2D Zombies
### A 2D Zombie Survival Game

Call of 2D Zombies is a two-dimensional zombie survival game with an overhead viewpoint. The player can move a character around the screen with keyboard input and aim a weapon with the mouse. Left clicking will fire a weapon in the direction of the mouse pointer. Zombies (squares) come in waves that increase in difficulty. The player has limited health, and each contact with a zombie decreases that health. The player’s goal is to shoot and kill the zombies, surviving for as long as possible.

Framework used: http://www.gametutorial.net/article/Java-game-framework
Provides capabilities for creating the game window, drawing to the window, creating the game loop, and collecting user input.


## Classes
1.	Window

Creates a full screen window and places an instance of Framework on it

2.	Canvas

Canvas extends JPanel
Listens for and tracks keyboard and mouse events
Handles graphics and drawing methods

3.	Framework

Framework extends Canvas
Is the main game loop that updates and draws the Game
Has an instance of the Game class
Handles a few mouse events

4.	Game

Has all game objects
Tracks game statistics
Handles updating game objects, components, and displays
Handles collision detection
Handles drawing game objects and display
Handles all other gameplay
