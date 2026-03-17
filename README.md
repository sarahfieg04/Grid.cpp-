* Maze Icon Descriptions 
   * "#" → border walls
   * "." → open spaces
    * "@" → obstacles 
    * "^ < v >"  → mover 
    * "*" → path the mover has already visited
 
* Maze Rules
  * the mover will start at a random position in the maze
  * there are 1-2 randomly placed objects in each maze
  * mover logic:
    * If the right side is open → turn right
    * Else if the front is blocked → turn left
    * Else if the front is blocked → turn left
  * Every time the mover leaves a space, it becomes a "*".
  * The mover cannot move onto "@" or "*".
  * When the mover reaches the border "#" it replaces the outiside wall and escapes

* Sample Run:
  * <img width="297" height="523" alt="image" src="https://github.com/user-attachments/assets/63c4eb89-8daf-4ff0-914a-8fddb51cc7f8" />


* How to Run:
  * Compile:  g++ trap.cpp Grid.cpp -o grid
  * Run: ./grid    
