#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


class Player {
public:

    std::string name;
    int health;
    int attackDamage;
    int maxHealth;


    Player(std::string n, int h, int a) {
        name = n;
        health = h;
        maxHealth = h;
        attackDamage = a;
    }


    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }


    bool isAlive() {
        return health > 0;
    }
};


class Enemy {
public:

    std::string name;
    int health;
    int attackDamage;


    Enemy(std::string n, int h, int a) {
        name = n;
        health = h;
        attackDamage = a;
    }


    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }


    bool isAlive() {
        return health > 0;
    }
};


void printStatus(Player player, Enemy enemy) {
    std::cout << "\n--- STATUS ---" << std::endl;
    std::cout << player.name << " HP: " << player.health << "/" << player.maxHealth << std::endl;
    std::cout << enemy.name << " HP: " << enemy.health << std::endl;
    std::cout << "--------------\n" << std::endl;
}



int main() {

    srand(time(0));


    std::string playerName;
    std::cout << "Welcome, adventurer! What is your name? ";
    std::cin >> playerName;


    Player player(playerName, 100, 20);


    Enemy enemy("Goblin", 50, 10);

    std::cout << "\nA wild " << enemy.name << " appears!\n" << std::endl;


    while (player.isAlive() && enemy.isAlive()) {
        printStatus(player, enemy);


        std::cout << "It's your turn. Choose an action:" << std::endl;
        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Flee" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 1) {

            int damageDealt = rand() % player.attackDamage + 5;
            enemy.takeDamage(damageDealt);
            std::cout << "\nYou attack the " << enemy.name << " and deal " << damageDealt << " damage!" << std::endl;
        } else if (choice == 2) {
            std::cout << "\nYou successfully flee from the battle!" << std::endl;
            break;
        } else {
            std::cout << "\nInvalid choice. You hesitate and do nothing." << std::endl;
        }


        if (enemy.isAlive()) {

            int damageDealt = rand() % enemy.attackDamage + 1;
            player.takeDamage(damageDealt);
            std::cout << "The " << enemy.name << " attacks you and deals " << damageDealt << " damage!" << std::endl;
        }
    }


    std::cout << "\n--- BATTLE OVER ---" << std::endl;
    if (player.isAlive()) {
        std::cout << "You defeated the " << enemy.name << "! Congratulations!" << std::endl;
    } else {
        std::cout << "You have been defeated... Game Over." << std::endl;
    }

    return 0;
}

