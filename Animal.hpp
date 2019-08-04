/*******************************
          Animal class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the header/class
 specification file for a class
 called Animal, which represents
 animals for a zoo tycoon game.
 
 This class has members for
 age, cost, babies, food, and payoff.
 
 In this case, the only animals are
 Tigers, Penguins, and Turtles.
 
 ******************************/

#ifndef Animal_hpp
#define Animal_hpp

class Animal
{

protected:
    
    //member variables
    int age; //in days (<3 = baby, >=3 = adult)
    int cost; //in dollars
    int numberOfBabies; //# of babies in litter
    const int baseFoodCost = 10; //in dollars (per day)
    int payoff;

public:
    
    //member methods
    Animal(); //constructor
    
    void grow1day();

	//set methods
    void setAge(int a);
    void setCost(int c);
    void setNumberOfBabies(int n);
    void setPayoff(int p);
    
    //get methods
    int getAge();
    int getCost();
    int getNumberOfBabies();
    int getPayoff();

};

#endif
