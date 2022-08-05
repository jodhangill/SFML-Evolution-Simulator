# SFML-Evolution-Simulator

# ABOUT

My first repo on github!
This simulator helps visualize the process of evolution through SFML

Each generation has a certain amount of creatures dependent on the last. 
Each creature has 2 unique attributes: 
  **Speed** - The movement speed of the creature
  **Efficiency** - The amount of food needed to reproduce
  (Green creatures have high efficiency and low speed
 
Once all the food has been eaten, a new generation is created from the current creatures depending on the amount of food eaten by each creature and their respective efficiency. The offspring each have a high chance of mutating; represented by a different speed to efficiency ratio from the parent.

As the simulation progresses, the high efficiency creatures go extinct and speed proves the be the prevailing attribute.
  

# SREENSHOTS
![Screenshot 2022-08-05 140120](https://user-images.githubusercontent.com/87293665/183171596-9d20b5b6-1318-4ab5-8eb5-4d8bf2ed8dc9.png)

![image](https://user-images.githubusercontent.com/87293665/183172156-20c90846-51a9-406c-b04e-b99d24f6254b.png)

# HOW TO RUN

1. Download code

2. In SFML-Evolution-Simulator-main\Release run Evolution_Sim.exe

## OR (for Visual Studio 2017)

1. Download code

2. Create empty project and add source files to "Source Files"

3. Add SFML paths to project properties - https://www.sfml-dev.org/tutorials/2.5/start-vc.php

# FEATURES
###### UNFINISHED
- [ ] Realtime display of food and creature stats
- [ ] Creature life-span attribute
- [ ] Independent genernations

