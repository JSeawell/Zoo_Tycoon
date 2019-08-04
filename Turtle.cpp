/*******************************
 Turtle class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the class implementation
 file for a class called Turtle,
 which represents Turtles for a
 zoo tycoon game.
 
 This class inherits from a class
 Animal, so it has members for
 age, cost, babies, food, and payoff.
 
 ******************************/

#include "Turtle.hpp"

/*************************************
 Turtle::Turtle
 
 This is the default constructor,
 which sets all the animal inherited
 member variables, and food cost
 
 *************************************/
Turtle::Turtle()
{
    setAge(0);
    setCost(100);
    setNumberOfBabies(10);
    foodCost = (baseFoodCost * 0.5);
    setPayoff((0.05 * cost));
}

/*************************************
 turtle::getFoodCost
 *************************************/
int Turtle::getFoodCost()
{
    return foodCost;
}
