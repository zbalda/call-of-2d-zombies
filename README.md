# Call of 2D Zombies
### A 2D Zombie Survival Game

Call of 2D Zombies is a two-dimensional zombie survival game written in C++ using SDL libraries. The player controls a small blue character using the arrow keys and tries to avoid enemies that chase it.

![cod2z.png](cpp/src/resources/co2dz.png)


## Goal
The goal of this project was to refactor a simple two-dimensional game I had created in my Intro to Computing. The purpose was to apply good software design principles, use design patterns where they were suitable, and eliminate as much code rot as possible.

## Design
![UML_Diagram.png](cpp/src/resources/UML_Diagram.png)

#### MVC and the Game Loop
The core design patterns of this game, or of most games for that matter, are probably the Model View Controller and the Game Loop. Like most UI programs, this game utilizes the MVC pattern to collect input from the user, update the game model based on that input and render the view. Unlike other event driven UI applications and event driven games, this game also runs on a game loop. Game loops are useful when the game model needs to advance continuously - which is the case here.

##### The game loop timer
A simple implementation of a game loop might mark the start time of an "MVC cycle", run that cycle (i.e. process input, update model, render view), then sleep for however much time is left until the next cycle should start.

One problem with this implementation is that it doesn't account for the case in which processing input, updating, and rendering takes longer than the "tick rate" of the game.

Instead of sleeping for the remainder of the cycle, my game loop updates and renders the appropriate amount of times on each game loop based on how lagged behind the current state and view of the game is. Lag, in this case, is the number of milliseconds the current game model and view is behind the current time. Lag is updated each game loop, and the game model is only updated and rendered every time the lag reaches the tick rate (i.e. milliseconds per update). After which, lag is updated (i.e. milliseconds per update is subtracted from lag). This implementation handles the case in which the game needs to play "catch up" by dynamically updating and rendering the appropriate amount of times based on how lagged behind it is.

#### Component
A game world is composed of game objects. Players, enemies, terrian, cameras for rendering views, etc.. My initial idea for structuring these objects was to create a base object class and have all concrete objects inherit from it. I started by creating a base object class with position, velocity, and health. Shortly after, I created a camera object and a static terrain object. I quickly realized that the camera didn't need health, and the static terrain object didn't need velocity. I could move health and velocity into a movable object class, but where would the camera fit into that? The camera needs to move too, but it doesn't make since to give the camera health.

The solution to this inheritance mess is the component pattern. Using the component pattern, I created a base Game_Object container. This game objects container stores a vector of components. These components can handle user input, physics, graphics, ai, etc. A game object can be constructed of whatever components it needs to operate the way it needs. When a game object is updated it simply updates each of its components. It passes itself to each of the components so that each component can update any shared properties of the game object. Any properties that do not need to be shared are stored in the components themselves. Message broadcasting is also implemented for sharing data between components.

When a game object is updated, it is given the game world and a camera. It uses the game world to update its physics component and the camera for rendering with its graphics component.

##### The camera
My initial plan was to have the camera be a game object but this did not end up working well at all. For my implementation I wanted the camera to take a game object on each update and follow that object. The issue with using the camera as a game object is that is should only be updated once per cycle. Updating it to follow an object on each cycle works, but when the camera is passed to other game objects for those game object to render to it, there is no way to render without updating again. One hack would be to add a render function to the game object, but this would be an anti pattern. Not all game objects need a render function. The component pattern works best with its only methods are those needed by all container objects, usually just an update method.

In the end I simply created a camera object that has methods for both updating and rendering.


#### The Factory and the Prototype
The factory pattern is used to create game objects and the prototype pattern is used to spawn new objects throughout the game. During initialization, the game world uses the factory to create objects that it creates spawners from, and uses those spawners throughout the game to spawn enemies.

I chose the factory over the builder because even though a game object can be "built of components", there isn't much variation in the game objects. A player has components for input, physics, and graphics, an enemy has components for AI and rendering, and a terrain object has a component for graphics. A builder might be useful for constructing more complex game objects, but for the simple game this is the factory makes things easier.

To implement the prototype pattern I added a clone method to each game object. Clone copies an object and all of its components. A spawner, rather than being used by other objects to spawn game objects, spawns game objects itself. The game world has a collection of spawners that it updates at the end of each game loop. If the spawners timer reaches zero, it spawns its game object, adds the object to the vector of game objects in the game world, and resets its timer. Spawn delay can be decreased over time to increase the rate at which enemies spawn.


## Results
Planning and implementing the game loop and update method took the most time overall. Specifically, the update method was difficult to figure out. I initially planned to update all objects first, then check for collisions. However, because of how the component pattern updates and renders on each update, it made more since to have update and render on each update.

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
