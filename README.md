# Rhombi-vs-Hexagons

### Gameplay:

This game implements the logic of "Plants vs Zombies" game at a lower level.

The game takes place within 3 rows, each containing 3 columns. From the right side, outside the screen, "bad" hexagon enemies appear at random intervals, moving across a row to the left side of the screen. Once a hexagon traverses the entire row, the player loses a life. Once all 3 lives are gone, the game is lost.

To combat the "bad" hexagons, the player has the ability to place a saving rhombus in one of the 3 cells on each row, which launches projectiles moving to the right along the row where the rhombus that launched the projectile is located. Upon encountering a hexagon, the projectile damages the hexagon, and after 3 hits, the hexagon dies.

However, the player faces two drawbacks. They cannot place as many rhombuses as they want, as each placed rhombus costs a certain number of stars. Stars appear at random intervals on the scene, and the player must collect them. Additionally, each rhombus can only harm a specific type of hexagon, based on the color each one has.

### Code implementation

