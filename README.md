# COMP3016-CW1

# Overview

My game is a story-driven turn-based RPG with three levels of combat that increase in difficulty each level. The combat is based around type matchups where the type of the enemy is hidden to the player and they have to guess the enemy type and use super effective moves to progress. Each enemy has different strengths and weaknesses depending on their type. The goal of the game is to defeat the enemy on each floor and save your best friend from the top of the tower. The game is medieval-fantasy themed and is called "Help! My Best Friend Has Been Trapped in a Tower by an Evil Wizard! Lets go Save Her with the Power of Magic!" to mirror the common humorous trope in anime and manga of having long titles to portray a lighthearted feel.

# Dependencies

The dependencies I used were:
 - SDL2 Version 2.32.10 as the Simple Direct Media Layer
 - SDL2_image Version 2.0.1 to handle image assets
 - SDL2_ttf Version 2.24.0 to handle font assets
 - SDL2_mixer Version 2.8.1 to handle audio assets
They are all licenced under the zlib licence which can be found here: https://www.libsdl.org/license.php

# Use of AI Description
These were the Assisted Work Sections that my AI usage fell under:
A6 - After following many online tutorials about how to implement SDL2, I used AI to help bridge the gap between what I had learned and how I would refactor my code to fit my desired game to streamline production and improve scalability. I had one primary game loop that handled all the combat logic - however after learning about Screens I wanted to separate my logic. I used the AI to suggest improvements to my structure for where logic could be isolated.
A7 - I used this to help me learn how to implement Assets using the various SDL2 libraries available which had extremely limited documentation and tutorials.
A8 - When encountering errors, Visual Studio was not displaying them in user-friendly ways so I used AI to reformat the error message to one I could understand so I could then fix my code.
Partnered Work - I used Evanto MusicGen to generate the Intro Screen and Story Screen background music after being unable to find suitable music on royalty free sound libraries.

# Game Patterns I Used

Sequencing Patterns - for my turn based combat I used different combat loops to handle the logic, each of these Game Loop Patterns represented a different difficulty level and each of these loops contained a Handle Event, Update and Render subloop method. Specifically within the Update method of the game loops, I created a Turn Based Combat System to check player health and stop combat if either the player or the enemy has died.
State Pattern - For my Screens, I use a Screen Baseclass but then each individual Screen State is a Subclass which encapsulates certain behaviour but also extends, like in the Combat Screen there is added logic for the Turn Based Combat System. The main loop switches between these screens dynamically based on the players progress. If they fail a level they are sent to the Death Screen however if they win they then move onto the next level of combat. 

# Game Mechanics and How they are Coded

The main game mechanic I implemented was Type Matchups in my Turn Based Combat System. Each enemy has a type that is hidden from the player and they have to use the Type Matchup Chart (which is toggleable throughout combat):

![20251107-1704-04 4562879](https://github.com/user-attachments/assets/3d225976-51ab-4fd3-8b11-5193bd359524)

The logic for the Matchup System was made using an unordered map table that pulls through the player move type and the enemy type to find the effectiveness:

<img width="376" height="329" alt="image" src="https://github.com/user-attachments/assets/b7f839c7-0f57-4ffe-94d8-5f8597713000" />

The effectiveness is then passed into two functions that return a string and a colour to display the effectiveness to the player:

<img width="383" height="122" alt="image" src="https://github.com/user-attachments/assets/3548acfb-ba23-481e-a874-0587a9bca11f" />

<img width="333" height="183" alt="image" src="https://github.com/user-attachments/assets/19689f69-02cc-4150-a07a-f037b5fe7ba4" />

Using the effectiveness and toggleable chart, players will be able to figure out an enemies type and use super-effective moves to win combat:

![20251107-1723-44 9038057](https://github.com/user-attachments/assets/a78a67c0-fa18-491b-bbd2-9a08ab05616c)

The type is hidden from the player meaning they may have to attempt the game multiple times to complete it and also remember the types of the enemies as they progress which is the Unique Selling Point of my game.

The game is also story based with a plot that revolves around saving your best friend and how helping others can bring joy to you. This is shown in the final story screen where a screen from the start of the game is reused but colourised while the rest of the game is mostly black and white:

<img width="396" height="316" alt="image" src="https://github.com/user-attachments/assets/10c10669-f79f-4abf-b438-9ed239643bc2" />

<img width="395" height="314" alt="image" src="https://github.com/user-attachments/assets/b0fababd-d7ec-4b13-8736-8b326036c4a5" />

The pre and post combat Story Screens are separated to make sure the user can only see the post-combat story once they have completed the hardest level:

<img width="334" height="160" alt="image" src="https://github.com/user-attachments/assets/2d5b09c4-8498-4428-bdaa-74a83efe8a31" />

<img width="315" height="172" alt="image" src="https://github.com/user-attachments/assets/8781ec5d-44a9-4663-b26c-3a687288cb53" />

For my Turn Based Combat System I handled the main logic in the update loop. The game waits for the player to pick their move and checks to see if both the enemy and player are still alive:

<img width="278" height="243" alt="image" src="https://github.com/user-attachments/assets/d772e6cd-a392-46d0-a157-da0b6d7d269d" />

After passing the player move and enemy type through the previously mentioned Effectiveness Logic, the game then displays assets, some of which are dynamic to the effectiveness level such as sound effects and text. The enemy turn then occurs, dealing a fixed amount of damage to the player. The loop then checks to see if their participant is dead before looping back to the start:

<img width="318" height="262" alt="image" src="https://github.com/user-attachments/assets/b6ef8d6f-187b-43db-bc17-7011059c0b1e" />

If the player dies, the variable 'successful' is returned as false to the main loop. Then the Death Screen is created and rendered before the game enters cleanup to destroy all assets and prevent memory leaks:

<img width="341" height="206" alt="image" src="https://github.com/user-attachments/assets/f225bca5-072f-4552-afb4-1abeb8346883" />

<img width="259" height="139" alt="image" src="https://github.com/user-attachments/assets/8aebd87b-e88f-434d-ab68-d3e7a9b2f362" />

# Testing My Code

I thoroughly tested my code continuously during development by only making incremental changes alongside pushing to git between successful tests. These incremental successes helped with morale as well as making it easier to revert back to a working version of my game if I could not successfuly fix errors. As seen in the above screenshot, I also made consistent use of cout statements to check that everything was running as it should and find where any errors or sticking points were. I also used cout statements when creating and finding assets so I could see if an asset was either missing on screen because a path was incorrect or whether I had rendered the asset at the wrong size. 

<img width="386" height="158" alt="image" src="https://github.com/user-attachments/assets/08eddde6-f543-4a46-8282-5bfe7e7a8b5a" />

# Evaluation

Although I had to decrease the scope of my original idea due to time constraints and illness, I have finally reached a point where I am very content with the state of my game. While the concept of a team had to be scrapped, I was able to keep in the turn based aspect and type matchup mechanic. Prior to this assessment I had extremely little knowledge of C++ however I have managed to make a working game with assets and a storyline. In the future I will be less hesitant to use AI as a learning tool for understanding code and libraries.









