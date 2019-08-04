/*******************************
          Tiger class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the header/class
 specification file for a class
 called Tiger, which represents
 Tigers for a zoo tycoon game.
 
 This class inherits from class
 Animal, so it has members for
 age, cost, babies, food, and payoff.
 
 ******************************/

#ifndef Tiger_hpp
#define Tiger_hpp

#include "Animal.hpp"

class Tiger : public Animal
{
private:
    int foodCost; //in dollars (based on base food cost)
public:
    Tiger(); //constructor
    int getFoodCost();
};

#endif
