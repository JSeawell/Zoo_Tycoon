/*******************************
           Animal class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the class implementation
 file for a class called Animal,
 which represents animals for a
 zoo tycoon game.
 
 This class has members for
 age, cost, babies, food, and payoff.
 
 In this case, the only animals are
 Tigers, Penguins, and Turtles.
 
 ******************************/

#include "Animal.hpp"

/*************************************
           Animal::Animal

 This is the default constructor,
 which sets ...

*************************************/
Animal::Animal()
{
    setAge(0);
    setCost(0);
    setNumberOfBabies(0);
    setPayoff(0);
}

void Animal::grow1day()
{
	age = age + 1;
}



//Set methods:

/*************************************
            Animal::setAge
*************************************/
void Animal::setAge(int a)
{
    age = a;
}

/*************************************
            Animal::setCost
 *************************************/
void Animal::setCost(int c)
{
    cost = c;
}

/*************************************
        Animal::setNumberOfBabies
 *************************************/
void Animal::setNumberOfBabies(int n)
{
    numberOfBabies= n;
}

/*************************************
           Animal::setPayoff
 *************************************/
void Animal::setPayoff(int p)
{
    payoff = p;
}

//get methods

/*************************************
            Animal::getAge
 *************************************/
int Animal::getAge()
{
    return age;
}

/*************************************
          Animal::getCost
 *************************************/
int Animal::getCost()
{
    return cost;
}

/*************************************
       Animal::getNumberOfBabies
 *************************************/
int Animal::getNumberOfBabies()
{
    return numberOfBabies;
}

/*************************************
          Animal::getPayoff
 *************************************/
int Animal::getPayoff()
{
    return payoff;
}

