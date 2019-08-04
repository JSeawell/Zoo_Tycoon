/*******************************
 Turtle class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the header/class
 specification file for a class
 called Turtle, which represents
 Turtles for a zoo tycoon game.
 
 This class inherits from class
 Animal, so it has members for
 age, cost, babies, food, and payoff.
 
 ******************************/

#ifndef Turtle_hpp
#define Turtle_hpp

#include "Animal.hpp"

class Turtle : public Animal
{
private:
    int foodCost; //in dollars (based on base food cost)
public:
    Turtle(); //constructor
    int getFoodCost();
};

#endif
