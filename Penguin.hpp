/*******************************
 Penguin class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the header/class
 specification file for a class
 called Penguin, which represents
 Penguins for a zoo tycoon game.
 
 This class inherits from class
 Animal, so it has members for
 age, cost, babies, food, and payoff.
 
 ******************************/

#ifndef Penguin_hpp
#define Penguin_hpp

#include "Animal.hpp"

class Penguin : public Animal
{
private:
    int foodCost; //in dollars (based on base food cost)
public:
    Penguin(); //constructor
    int getFoodCost();
};

#endif
