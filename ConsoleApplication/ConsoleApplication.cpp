#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand((unsigned)std::time(nullptr));

    int playerHP = 20;
    int enemyHP = 12;
    int potions = 2;

    std::cout << "=== Mini Console RPG ===\n";
    std::cout << "You encounter an enemy!\n\n";

    while (playerHP > 0 && enemyHP > 0) {
        std::cout << "Your HP: " << playerHP
            << " | Enemy HP: " << enemyHP
            << " | Potions: " << potions << "\n";
        std::cout << "1) Attack\n";
        std::cout << "2) Heal\n";
        std::cout << "3) Run\n";
        std::cout << "Choose: ";

        int choice;
        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {
            int dmg = 2 + (std::rand() % 5); // 2..6
            enemyHP -= dmg;
            std::cout << "You hit the enemy for " << dmg << " damage!\n";
        }
        else if (choice == 2) {
            if (potions > 0) {
                potions--;
                int heal = 5 + (std::rand() % 6); // 5..10
                playerHP += heal;
                std::cout << "You drink a potion and heal " << heal << " HP!\n";
            }
            else {
                std::cout << "No potions left!\n";
            }
        }
        else if (choice == 3) {
            int escape = std::rand() % 100; // 0..99
            if (escape < 50) {
                std::cout << "You escaped successfully!\n";
                return 0;
            }
            else {
                std::cout << "Escape failed!\n";
            }
        }
        else {
            std::cout << "Invalid choice. Try 1, 2, or 3.\n";
        }

        // Enemy turn (only if still alive)
        if (enemyHP > 0) {
            int enemyDmg = 1 + (std::rand() % 5); // 1..5
            playerHP -= enemyDmg;
            std::cout << "Enemy hits you for " << enemyDmg << " damage!\n";
        }

        std::cout << "-------------------------\n";
    }

    if (playerHP <= 0) {
        std::cout << "You were defeated...\n";
    }
    else {
        std::cout << "You defeated the enemy! Victory!\n";
    }

    return 0;
}