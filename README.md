# The Paris Opera Incident
### A Text-Based RPG based on The Phantom of the Opera



*A dark night at the Palais Garnier, a legendary opera, and a mystery lurking in the catacombs below. As the new star, Christine Daaé, dissapears from the stage, you are the only one who sees the path she was taken on. Will you be the hero of the hour or another victim of the Opera Ghost?*

This is a single-file, narrative-driven RPG written in C++. It uses classic  mechanics like skill checks and character stats to create a dynamic story where your choices and your character's abilities truly matter.

## Features

**Dynamic Character Creation**: Allocate points to your character's wits, brawn, and charisma. These stats directly influence your attack damage and your ability to succeed in crucial moments.
 **Skill-Based Outcomes:** Your success isn't random. Persuading the Phantom or noticing a hidden clue depends on a dice roll combined with your character's stats. A high charisma character might talk their way out of a fight that a high brawn character would have to win with force.
* **Branching Narrative:** Make key decisions that lead you down different paths, including a choice to risk it all or walk away, resulting in multiple endings.
* **Atmospheric Storytelling:** Immerse yourself in the world of 19th-century Paris with descriptive text that brings the opera house and the Phantom's lair to life.

## Gameplay Example

Your stats can unlock new information and give you an edge. A character with high Wits might notice things others would miss.

> The overture begins. You hear whispers and mumbles about the Vicomte de Chagny, who is reportedly in attendance for Christine.
> Despite the music, you hear a faint creaking from above. Do you look up? (1 for Yes, 2 for No): **1**
>
> You look up at the grand chandelier. In the catwalks above, you spot a shadowy figure. Perhaps wearing a mask. He sees you looking.
> **Your sharp eyes notice more than just a figure; he is tampering with the chandelier's support rope!**

## How to Compile and Play

This project is self-contained in a single C++ file and has no external dependencies.

**Prerequisites:**
* A C++ compiler, such as `g++`.

**Instructions:**

1.  Clone the repository to your local machine:
    ```bash
    git clone [your-repository-url]
    ```
2.  Navigate into the project directory:
    ```bash
    cd [your-repository-name]
    ```
3.  Compile the source code:
    ```bash
    g++ phantom_game_v3.cpp -o phantom_game
    ```
4.  Run the game!
    ```bash
    ./phantom_game
    ```

## Project Roadmap

This is an ongoing project. Future features may include:
* [ ] A functional inventory system with usable items.
* [ ] Additional scenes and choices in the catacombs before the final confrontation.
* [ ] More complex environmental puzzles that require high Wits or Brawn.
* [ ] A save/load game feature.
