# AIR BATTLE 
## TABLE OF CONTENTS
* [INTRODUCTION](#introduction)
* [DISCRIPTION](#discription)
* [CONTROL](#control)
* [SEE ALSO](#see-also)
* [CONCLUSION](#conclusion)
 ## INTRODUCTION
- Full name: Dang Quang Huy - K68J - UET  
- Student ID: 23020671  
- Project: AIR BATTLE (INT2215_52 - Advanced Programming)  

## SETUP:
- Access the following Google Drive link:  
  https://drive.google.com/file/d/11CTW4Ws1uKX2mTCJGizQmrG9qtOG_tcW/view?usp=sharing  
- Download the **AIR BATTLE.rar** file and extract it into a folder.  
- Open the **AIR BATTLE** folder, navigate to the **Debug** subfolder, and run **AIR BATTLE.exe** to start playing.
## LINK YOUTUBE : 
https://youtu.be/21B0FujcbVE

## DISCRIPTION
### GAME DISCRIPTION AND INSTRUCTION :
- **AIR BATTLE** is a shoot 'em up (Shmup) game where the player controls a fighter aircraft to destroy all enemy planes and the final boss.  
  In addition to the main objective, the game also includes optional challenges based on time and score, adding more intensity and excitement.  
  Random support items will occasionally appear on the screen — collecting enough of them grants the player an extra life.
- In each session, the game randomly selects a background to create variety and enhance the player’s experience.
- The game features all essential functions: pause/resume using the **ESC** key, restart the game, view gameplay instructions, and exit the game with ease.
- Background music plays continuously throughout the game, along with engaging sound effects for shooting and explosions, adding to the excitement and immersion.
- **AIR BATTLE** promises to deliver an enjoyable and dynamic gaming experience with its exciting features and vivid graphics.
## CONTROL
| **KEYS** |    FUNCTION   |
|:--------:|:-------------:|
|     W    |       UP      |
|     S    |      DOWN     |
|     A    |      LEFT     |
|     D    |     RIGHT     |
|     K    |  LASER BULLET |
|     L    |  DART BULLET  |

## PREVIEW :
### MENU START :
![a1](https://github.com/user-attachments/assets/265ae344-c3a6-40db-8e13-d919d92fa4ff)
### GUIDE :
![a2](https://github.com/user-attachments/assets/17b997e4-1130-4bf3-b18e-f02587f4c876)

### FIGHT WITH BOSS :
![a6](https://github.com/user-attachments/assets/b80b6234-d53f-47bb-9ab6-c7b789b2ba28)

### DEFEAT :
![a4](https://github.com/user-attachments/assets/a3d0a305-47b5-467a-9b8a-6dcd2369d351)

### VICTORY :
![a5](https://github.com/user-attachments/assets/9776b6ed-6328-41dc-8f54-61cf170155bc)

## GRAPHIC :
### BULLET 
![dartbl](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/7f9d4870-9b61-4c5a-8204-f592b9483d89)
![laserbl](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/391e5a32-a6cc-41a0-9cd3-1565d03de254)
![bl4](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/bc340b9a-b545-4a67-8c6b-7d5443888d3a)
![bl8](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/d11f5a72-096f-47b2-ac8c-4d7a5cdb55ae)
### MAIN :
![c3](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/1c44586e-d904-4199-8f4d-70fed736b96d)
### THREATS :
![c2](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/4c50f4bb-cdf2-4811-a728-9d4842a9adbb)
### BOSS :
![c4](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/b3595259-b038-4470-9805-42bf75659317)
### EXPLOSION :
![expmain](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/51ff742b-ebfd-4347-92c8-cfeab0596d0a)
### SUPPORT ITEM :
![gold](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/3be7b99c-a9e2-4941-83e6-c7a79bc4af0b)
### LIFE :
![health](https://github.com/HuyDang05/BTL_LTNC/assets/161727773/26c91058-4f90-4887-a543-ffcd2c02d9e4)

## SEE ALSO
### Technologies and Techniques Used:
- Utilized the **SDL 2.0 library**, programmed in **C++**, and developed using **Visual Studio Code**.
- Applied **Object-Oriented Programming (OOP)** principles, with separation between `.cpp` and `.h` files for better code organization and maintainability.
- Created a variety of game objects: the main character, enemy planes, boss enemy, power-up items, bullets, text elements, and the main character's HP bar.
- Applied mathematical concepts to handle **collision detection** between objects: bullets and enemies, the main character and support items, etc.
- Handled **timing, scoring, mouse and keyboard interactions**, audio playback, rendering of images and text, and random background selection on game start.
- Implemented a menu system to enhance game realism: **start menu, instruction/help menu, victory menu, and game over menu**.
- Developed logic for **enemy shooting and horizontal movement**; when an enemy is defeated, it respawns at a random position on the screen.
- Designed the **Boss object** as a subclass of the enemy (threat) object, with extended features: higher HP, different and faster movement, more rapid shooting, etc.
- Utilized **class inheritance** from a base class to organize and extend game object behaviors.
- 
### References:
- **Installing SDL 2.0 in Visual Studio Code**: Referenced guides and discussions on Reddit, Stack Overflow, and Lazy Foo’.
- **Using the SDL 2.0 library and managing the program structure**: Referenced tutorials from Lazy Foo’, videos by Ms. Trần Thị Minh Châu, Stack Overflow, and YouTube channels such as Let's Make Games, Madsycode, and Phát Triển Phần Mềm 123 A-Z.
- **Images**: Sourced from Google and some simple assets were self-designed.
- **Audio**: Found via Google search and websites like [pixabay.com](https://pixabay.com).
- **Core game logic**: Based on YouTube tutorials from Phát Triển Phần Mềm 123 A-Z, with further custom development for features like support items, boss objects, menu system, and additional gameplay conditions involving time and score.

## CONCLUSION
- Significantly improved logical thinking, collision handling, and coding skills.
- Enhanced creativity, idea development, and skills in editing images and audio.
- Gained experience in setting up the development environment and working with external libraries.
- The program is structured in a way that makes it easy to **refactor** and **add new features**.
- Learned how to organize and structure code blocks for smooth and efficient performance, as well as how to write **clean**, **optimized**, and **maintainable** code, especially when handling core game logic.
- Acquired deeper understanding of the **SDL2 library**, including functions for handling graphics, audio, and text.
- 
### Future Improvements:
- Add a **leaderboard feature**, allowing players to enter their name and save their score after each game session.
- Introduce more types of **power-up items** with different effects.
- Add **obstacles and bombs** to increase the challenge and gameplay variety.
- Implement a **difficulty selection menu**, enabling players to choose enemy speed and quantity based on their skill level.
- Add a **two-player mode**, allowing two players to play together or compete against AI.

  
