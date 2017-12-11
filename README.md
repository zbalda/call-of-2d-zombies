# Call of 2D Zombies
### A 2D Zombie Survival Game

Call of 2D Zombies is a two-dimensional zombie survival game written in C++ using SDL libraries. The player controls a small blue character using the arrow keys and tries to avoid enemies that chase it.

![cod2z.png](cpp/src/resources/co2dz.png)


## Goal
The goal of this project was to refactor a simple two-dimensional game I had created in CSCI 24000. The purpose was to apply good software design principles, use design patterns where they were suitable, and eliminate as much code rot as possible.

## Design
![UML_Diagram.png](cpp/src/resources/UML_Diagram.png)

#### MVC and the Game Loop
The core design patterns of this game, or of most games for that matter, are probably the Model View Controller and the Game Loop. Like most UI programs, this game utilizes the MVC pattern to collect input from the user, update the game model based on that input and render the view. Unlike other event driven UI applications and event driven games, this game also runs on a game loop. Game loops are useful when the game model needs to advance continuously - which is the case here.

##### The game loop timer
A simple implementation of a game loop might mark the start time of an "MVC cycle", run that cycle (i.e. process input, update model, render view), then sleep for however much time is left until the next cycle should start.

The biggest problem with this implementation, in my opinion, is that it doesn't account for the case in which processing input, updating, and rendering takes longer than the tick rate of the game (i.e. how often the game should perform an "MVC cycle").

Instead of sleeping for the remainder of the cycle, my game loop updates and renders the appropriate amount of times on each game loop based on how lagged behind the current state and view of the game is. Lag, in this case, is the number of milliseconds the current game model and view is behind the current time. Lag is updated each game loop, and the game model is only updated and rendered every time the lag reaches the tick rate (i.e. milliseconds per update). After which, lag is updated (i.e. milliseconds per update is subtracted from lag). This implementation handles the case in which the game needs to play "catch up" by dynamically updating and rendering the appropriate amount of times based on how lagged behind it is.

#### Component
A game world is composed of game objects. Players, enemies, terrian, cameras for rendering views, etc.. My initial idea for structuring these objects was to create a base object class and have all concrete objects inherit from it. I started by creating a base object class with position, velocity, and health. Shortly after, I created a camera object and a static terrain object. I quickly realized that the camera didn't need health, and the static terrain object didn't need velocity. I could move health and velocity into a movable object class, but where would the camera fit into that? The camera needs to move too, but it doesn't make since to give the camera health.

The solution to this mess is the component patter. Using the component pattern I created a base Game_Object "container". Game objects


#### Prototype


## Results

## Challanges

## Known Problems

## Additional Notes



## Other

### Useful Resources

#### [Game Programming Patterns](http://gameprogrammingpatterns.com/contents.html)

#### [SDL Tutorials](http://lazyfoo.net/tutorials/SDL/index.php)


### Built with

#### [SDL](https://www.libsdl.org/)

##### SDL Install

`apt-cache search libsdl2`

`sudo apt install libsdl2-dev`

##### SDL Image Install

`apt-cache search libsdl2-image`

`sudo apt install libsdl2-image-dev`

##### SDL Fonts Install

`apt-cache search libsdl2-ttf`

`sudo apt install libsdl2-ttf-dev`
