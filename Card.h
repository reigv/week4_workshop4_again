// Card.h -- class Cadrd definition

// card  (card/ abstract class) -- base class for all card types
// members:
//  - name (string) -- the name of the card
//  - health (int) -- the health of the card
// functions:
// Constructor: Card(string name, int health) -- initializes the card with a name and health

// a vitual destructor because we will be using pointers to base class
// virtual ~Card() -- virtual destructor for proper cleanup of derived classes
// delete objects through Card* pointers
// print <name> is destroyed

// getters:
// not vitual because they will be the same for all derived classes
// string getName() -- returns the name of the card
// int getHealth() -- returns the health of the card

// isAlive() 
// not virtual because it will be the same for all derived classes
// bool isAlive() -- returns true if health > 0, false otherwise
// should not be able to modify health directly, so no setter for health

// attack() -- pure virtual function to be implemented by derived classes
// must be overridden by WarriorCard and MageCard
// take a reference to another Card that is a target of the attack
// void attack(Card &target) -- pure virtual function for attacking another card
// return void

// takeDamage() -- virtual function to be overridden by derived classes
// take int damage as parameter and reduce health by that amount
// void takeDamage(int damage) -- virtual function to reduce health by damage amount
// subtract damage from health, but ensure health does not go below 0
// print <name> takes <damage> damage, health is now <health>

// Note attach() mus accept a reference to another Card, not a pointer, to avoid issues with slicing and to allow for polymorphic behavior when attacking other cards.

#ifndef CARD_H
#define CARD_H

class Card {

    protected:
        std::string name;
        int health;

    public:
        Card(std::string name, int health): name(name), health(health) {}
        
}


#endif // CARD_H