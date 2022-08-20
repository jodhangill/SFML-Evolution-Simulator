# SFML-Evolution-Simulator

# ABOUT

My first repo on github!
This simulator helps visualize the process of evolution through SFML

Each generation has a certain amount of pods (creatures) dependent on the last. 
Each pod has 2 unique attributes: 
  **Speed** - The movement speed of the creature
  **Efficiency** - The amount of food needed to reproduce
  (Green creatures have high efficiency and low speed
 
Once all the food has been eaten, a new generation is created from the current pods depending on the amount of food eaten by each pods and their respective efficiency. The offspring each have a high chance of mutating; represented by a different speed to efficiency ratio from the parent.

As the simulation progresses, the high efficiency pods go extinct and speed proves the be the prevailing attribute. This is a greedy form of evolution.
  

# SREENSHOTS
![image](https://user-images.githubusercontent.com/87293665/185724658-f703f852-ffad-4f8a-a7a3-3de82fdbc7b9.png)

![image](https://user-images.githubusercontent.com/87293665/185724662-9fa5f6ac-8f46-4b0b-98db-0e1571af92b9.png)

![image](https://user-images.githubusercontent.com/87293665/185724667-b0d22563-4dc0-4567-a3ca-d15d01547264.png)

![image](https://user-images.githubusercontent.com/87293665/185724671-4bcb7a04-1389-400f-9a2d-01aac00e7f9c.png)

![image](https://user-images.githubusercontent.com/87293665/185724840-39320b46-5c01-4921-981a-43dd83b53cf8.png)

![image](https://user-images.githubusercontent.com/87293665/185724687-02c377ce-d873-40b8-b026-a88c036402ff.png)


# HOW TO RUN

1. Download code

2. In SFML-Evolution-Simulator-main\Release    run Evolution_Sim.exe

## OR (for Visual Studio 2017)

1. Download code

2. Open solution to VS

3. Add SFML paths to project properties - https://www.sfml-dev.org/tutorials/2.5/start-vc.php

# FEATURES
- [x] Configurable starting food and pod amounts
###### UNFINISHED
- [ ] Realtime display of food and creature stats
- [ ] Creature life-span attribute
- [ ] Independent genernations

