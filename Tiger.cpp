/*******************************
          Tiger class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the class implementation
 file for a class called Tiger,
 which represents Tigers for a
 zoo tycoon game.
 
 This class inherits from a class
 Animal, so it has members for
 age, cost, babies, food, and payoff.
 
 ******************************/

#include "Tiger.hpp"

/*************************************
           Tiger::Tiger
 
 This is the default constructor,
 which sets all the animal inherited
 member variables, and food cost
 
 *************************************/
Tiger::Tiger()
{
    setAge(0);
    setCost(10000);
    setNumberOfBabies(1);
    foodCost = (baseFoodCost * 5);
    setPayoff((0.2 * cost));
}

/*************************************
         Tiger::getFoodCost
 *************************************/
int Tiger::getFoodCost()
{
	return foodCost;
}
