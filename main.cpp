#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

#include "Card.h"
#include "WarriorCard.h"
#include "MageCard.h"

int rollDie() {
    return rand() % 6 + 1;
}

void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {

    srand(time(nullptr)); // randomizes seed for rand()

    Card* cards[2];
    cards[0] = new WarriorCard("Ragnar");
    cards[1] = new MageCard("Merlina");

    int attacker = 0;
    int defender = 1;

    std::cout << "\n--- Battle Start ---\n";

    // Take turns attacking until someone loses
    while (cards[0]->isAlive() && cards[1]->isAlive()) {

        std::cout << "\nTurn: " << cards[attacker]->getName()
             << " attacks " << cards[defender]->getName() << std::endl;

        cards[attacker]->attack(*cards[defender]);

        swap(attacker, defender);
    }

    std::cout << "\n--- Battle Over ---\n";

    std::string winner;
    if (cards[0]->isAlive()) {
        winner = cards[0]->getName();
    } else {
        winner = cards[1]->getName();
    }
    std::cout << winner << " has won the fight!" << std::endl << std::endl;

    delete cards[0];
    delete cards[1];

    return 0;
}
