# Rhombi-vs-Hexagons
  Homework implemented in Elements of Computer Graphics course.
  
## Gameplay:

  This game implements the logic of "Plants vs Zombies" game at a lower level.

  The game takes place within 3 rows, each containing 3 columns. From the right side, outside the screen, "bad" hexagon enemies appear at random intervals, moving across a row to the left side of the screen. Once a hexagon traverses the entire row, the player loses a life. Once all 3 lives are gone, the game is lost.

  To combat the "bad" hexagons, the player has the ability to place a saving rhombus in one of the 3 cells on each row, which launches projectiles moving to the right along the row where the rhombus that launched the projectile is located. Upon encountering a hexagon, the projectile damages the hexagon, and after 3 hits, the hexagon dies.

  However, the player faces two drawbacks. They cannot place as many rhombuses as they want, as each placed rhombus costs a certain number of stars. Stars appear at random intervals on the scene, and the player must collect them. Additionally, each rhombus can only harm a specific type of hexagon, based on the color each one has.

## Code implementation:

### Tema1.cpp
  Important functions:
    - Init(): main logic of the game. 
    - RenderMap(): Initializing the necessary Mashes, screen resolution, camera position, translations steps, scale factors and adding static elements like the 3 lives and 3 stars given to the player at the begining of each game.
    - Update(): Render the mashes for the grid and the user interface's elements (the possible rhombuses, how mamy stars each consts and the number of lives and stars a player has).
    - OnMouseBtnPress(): verify if a players has clicked on an element (rhombus or collectable star) and check if the criteria for each action to be performed are met. (contains the drag-and-drop functionality for moving the rhombuses around the screen) 
    - OnMouseBtnRelease(): verify if a rhombus has been placed corectly inside a grid's square.
  
### Tema1.h
  Classes for the game's main elements: rhombuses, stars, grid squares, hexagons, collected stars and hearts.

### objects2D.cpp 
  Functions for creating the shapes used in the game: star, hexagon, rhombus, heart, square and ractagular.

### transform2D.h
  Making custom functions for rotating, scaling and translating a matrix.
