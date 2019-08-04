/*******************************
         Penguin class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the class implementation
 file for a class called Penguin,
 which represents Penguins for a
 zoo tycoon game.
 
 This class inherits from a class
 Animal, so it has members for
 age, cost, babies, food, and payoff.
 
 ******************************/

#include "Penguin.hpp"

/*************************************
           Penguin::Penguin
 
 This is the default constructor,
 which sets all the animal inherited
 member variables, and food cost
 
 *************************************/
Penguin::Penguin()
{
    setAge(0);
    setCost(1000);
    setNumberOfBabies(5);
    foodCost = baseFoodCost;
    setPayoff((0.1 * cost));
}

/*************************************
 Penguin::getFoodCost
 *************************************/
int Penguin::getFoodCost()
{
    return foodCost;
}

