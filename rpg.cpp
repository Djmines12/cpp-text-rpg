#include <iostream>
#include <string>
#include <vector> 
#include <cstdlib>
#include <ctime>
#include <algorithm>


class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackDamage;

public:
    Character(const std::string& n, int h, int a) 
        : name(n), health(h), maxHealth(h), attackDamage(a) {}

    virtual ~Character() = default;

   
    virtual void displayStatus() const {
        std::cout << name << " HP: " << health << "/" << maxHealth << std::endl;
    }

    virtual void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    bool isAlive() const {
        return health > 0;
    }

  
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getBaseAttack() const { return attackDamage; }
};


class Player : public Character {
private:
    int wits;
    int brawn;
    int charisma;
    std::vector<std::string> inventory; 

public:
    Player(const std::string& n, int h, int a, int w, int b, int c)
        : Character(n, h, a), wits(w), brawn(b), charisma(c) {}

   
    void displayStatus() const override {
        std::cout << name << " HP: " << health << "/" << maxHealth << std::endl;
        if (!inventory.empty()) {
            std::cout << "Inventory: [ ";
            for (const auto& item : inventory) {
                std::cout << item << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

    void addItem(const std::string& item) {
        inventory.push_back(item);
    }

    bool useItem(const std::string& item) {
        auto it = std::find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
            return true;
        }
        return false;
    }

    void heal(int amount) {
        health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    int getWits() const { return wits; }
    int getCharisma() const { return charisma; }
};


class Enemy : public Character {
public:
    Enemy(const std::string& n, int h, int a) : Character(n, h, a) {}

    void displayStatus() const override {
        std::cout << name << " HP: " << health << std::endl;
    }
};


class GameEngine {
private:
    Player* player;
    Enemy* phantom;

    void printStatus() const {
        std::cout << "\n--- STATUS ---" << std::endl;
        player->displayStatus();
        phantom->displayStatus();
        std::cout << "--------------\n" << std::endl;
    }

public:
    GameEngine() : player(nullptr), phantom(nullptr) {}

    ~GameEngine() {
        delete player;
        delete phantom;
    }

    void start() {
        std::string playerName;
        std::cout << "It's a chilly Autumn night in Paris, France. The year is 1897. You walk into an opera house, hoping to watch a great show. A man in a suit walks up to you and says, " << std::endl;
        std::cout << "'Welcome, traveller! Tonight is the premiere of a new opera at the Palais Garnier. What do we have on the slate today? A marvellous piece, Don Juan Triumphant." << std::endl;
        std::cout << "The lead, Christine Daaé, has turned into one of the best voices I had a privilege of managing.'" << std::endl;
        std::cout << "Let me introduce myself. I am the manager, Monsieur Joseph Pettiegrew, at your serivce. *He bows* And you are?' ";
        std::cin >> playerName;

        createCharacter(playerName);
        runSceneOne();
        runSceneTwo();
    }

    void createCharacter(const std::string& playerName) {
        int points = 5;
        int wits = 5, brawn = 5, charisma = 5;

        std::cout << "\n'A pleasure, " << playerName << ",' he says. 'Before you take your seat, tell me a bit about yourself.'\n";
        std::cout << "You have 5 attribute points to distribute between Wits, Brawn, and Charisma.\n";

        while (points > 0) {
            std::cout << "Points remaining: " << points << "\n";
            std::cout << "Current Stats -> Wits: " << wits << " | Brawn: " << brawn << " | Charisma: " << charisma << "\n";
            std::cout << "Add a point to (1) Wits, (2) Brawn, or (3) Charisma? ";
            int choice;
            std::cin >> choice;
            if (choice == 1) wits++;
            else if (choice == 2) brawn++;
            else if (choice == 3) charisma++;
            else continue; 
            points--;
        }

      
        player = new Player(playerName, 100, 15 + brawn, wits, brawn, charisma);
        player->addItem("Medical_Potion"); 
        std::cout << "\n'Very interesting,' says the manager. 'Let's find our seats shall we? The show is about to begin.'\n" << std::endl;
    }

    void runSceneOne() {
        // SCENE 1
        std::cout << "The overture begins. You hear whispers and mumbles about the Vicomte de Chagny, who is reportedly in attendance for Christine." << std::endl;
        std::cout << "Despite the music, you hear a faint creaking from above. Do you look up? (1 for Yes, 2 for No): ";
        int choice2;
        std::cin >> choice2;
        if (choice2 == 1) {
            std::cout << "\nYou look up at the grand chandelier. In the catwalks above, you spot a shadowy figure. Perhaps wearing a mask. He sees you looking." << std::endl;
            // skill check
            if (player->getWits() > 8) {
                std::cout << "Your sharp eyes notice more than just a figure; he is tampering with the chandelier's support rope!\n";
            }
            std::cout << "A chill runs down your spine. Be careful.\n" << std::endl;
        } else {
            std::cout << "\nYou dismiss the sound, focusing on the stage and the crowd around you. You feel an unnerving sensation of being watched.\n" << std::endl;
        }

        std::cout << "'Ah excuse me Monsieur or Mademoiselle', a stranger whispers to you" << std::endl;
        std::cout << "'I'm sorry it's terribly dark in here. Forgive my intrusion, have you heard what's been happening lately?'(1 to indulge in the conversation with the stranger, 2 to Politely Decline, 3 to Ignore Him) ";
        int choice3;
        std::cin >> choice3;
        if (choice3 == 1) {
            std::cout << "\nThe stranger proceeds tells you about the longwinded history of Paris and Opera before reaching the subject of Christine Daae." << std::endl;
            std::cout << "'So I heard that Miss Daae has found her voice, eh?' he says. 'I vastly remember her a year ago, struggling to recieve a big role against La Prima Dona." << std::endl;
            std::cout << "She was good no doubt. But nowhere near the level today! According to my sources, she has been guided by a mysterious spirit who rests below this very opera house. A hard to believe story, I know, but how else do you explain this development?" << std::endl;
            std::cout << "Nevermind my rambling, I think we're about to begin! the stranger says before returning to his seat\n" << std::endl;
        } else if (choice3 == 2) {
            std::cout << "'\nFair enough my good fellow, lets enjoy the show' the stranger says before reuturning to his seat.\n" << std::endl;
        } else if (choice3 == 3) {
            std::cout << "'\nHmph! The nerve of some people!' the stranger says in spite before returning to his seat.\n" << std::endl;
        }
    }

    void runSceneTwo() {
        // SCENE 2
        std::cout << "The curtain rises. Christine Daaé's voice fills the hall, a sound more beautiful than anyone could imagine. How on earth could she have learned to sing like this?" << std::endl;
        std::cout << "As she sings the final powerful note, a C octaves above the staff, all the lights in the opera house suddenly go out. The room is now thrown into darkness!" << std::endl;
        std::cout << "Panic erupts. When the emergency lights flicker on, Christine is gone!" << std::endl;
        std::cout << "A booming voice echoes from the walls, 'She is mine! Her talent belongs to me!'" << std::endl;
        std::cout << "\nIn the chaos, you see a secret door swing shut behind the stage mirrors. Do you follow into the vast darkness? (1 for Yes, 2 for No): ";

        int followChoice;
        std::cin >> followChoice;

        if (followChoice == 1) {
            runCatacombsAndCombat();
        } else {
            // --- Alt ending  
            std::cout << "\nYou decide the risk is too great and remain in the auditorium. The police are called, but Christine is never seen again." << std::endl;
            std::cout << "The legend of the Phantom of the Opera is born from the tragedy. The End." << std::endl;
        }
    }

    void runCatacombsAndCombat() {
      
        phantom = new Enemy("The Phantom", 130, 15);

        // SCENE 3
        std::cout << "\nYou slip through the secret door into the cold and damp catacombs beneath the opera house." << std::endl;
        std::cout << "Guided by the faint echo of music, you arrive at a pond. A lone boat waits." << std::endl;
        std::cout << "Across the water, you see his lair, lit by fabulous candles. The Phantom is there, with Christine at his organ." << std::endl;
        std::cout << "\n'Fool!' he bellows, turning to face you. 'You cannot take her from her Angel of Music! I gave her this gift!'" << std::endl;
        std::cout << "He draws a blade. You must fight!\n";

        // BATTLE 
        while (player->isAlive() && phantom->isAlive()) {
            printStatus();

            std::cout << "Choose your action:" << std::endl;
            std::cout << "1. Confront the Phantom" << std::endl;
            std::cout << "2. Attempt to reason with him" << std::endl;
            std::cout << "3. Use Medical Potion (+30 HP)" << std::endl;
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                int damageDealt = rand() % player->getBaseAttack() + 10;
                phantom->takeDamage(damageDealt);
                std::cout << "\nYou lunge forward and strike the Phantom, dealing " << damageDealt << " damage!" << std::endl;
            } else if (choice == 2) {
                std::cout << "\nYou attempt to reason with him, talking to the man behind the mask.\n";
                
                int persuasionRoll = (rand() % 20 + 1) + player->getCharisma();
                int difficulty = 22;

                if (persuasionRoll >= difficulty) {
                    std::cout << "Your words strike a chord! He begins to see the horror of his actions. 'You... you are right,' he whispers, lowering his weapon. 'How could I do this to Christine?'" << std::endl;
                    phantom->takeDamage(999); 
                    break;
                } else {
                    std::cout << "'Your pity is wasted on me!' he roars, enraged by your attempt. He presses the attack!\n";
                }
            } else if (choice == 3) {
                if (player->useItem("Medical_Potion")) {
                    player->heal(30);
                    std::cout << "\nYou drink the Medical Potion and restore 30 HP!" << std::endl;
                } else {
                    std::cout << "\nYou reach into your bag, but you have no potions left!" << std::endl;
                }
            } else {
                std::cout << "\nYou hesitate and lose your chance to act." << std::endl;
            }

            if (phantom->isAlive()) {
                int damageDealt = rand() % phantom->getBaseAttack() + 5;
                player->takeDamage(damageDealt);
                std::cout << "The Phantom strikes back from the shadows, dealing " << damageDealt << " damage!" << std::endl;
            }
        }

        // Outcome
        std::cout << "\n--- THE DUEL IS OVER ---" << std::endl;
        if (player->isAlive()) {
            std::cout << "With a final blow, the Phantom stumbles back, defeated. 'Go,' he yells, gesturing to Christine. 'Take the box and swear never to tell! Now Leave me to my darkness.'" << std::endl;
            std::cout << "You have rescued Christine! Congratulations!" << std::endl;
        } else {
            std::cout << "You have been defeated... The Phantom's music is the last thing you ever hear. Game Over." << std::endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    GameEngine game;
    game.start();
    return 0;
}
