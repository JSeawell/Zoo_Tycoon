/*******************************
            Zoo class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the header/class
 specification file for a class
 called Zoo, which represents
 a zoo  that holds animals
 in a zoo tycoon game.
 
 This class has pointer members for
 different animals in the zoo
 
 ******************************/

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

#ifndef Zoo_hpp
#define Zoo_hpp

class Zoo
{

private:
	//double pointers to dynamic arrays for each type of animal
    Tiger** tigerPtr;
	Penguin** penguinPtr;
	Turtle** turtlePtr;
    
	//holds sizes of animal arrays
    int tigerSize;
	int penguinSize;
	int turtleSize;    	

    //holds numbers of animals
	int numTig;
    int numPen;
    int numTur;

    //holds user budget
	int budget;

public:
	Zoo(); //constructor
    
    //add animals to arrays
    void addTiger(int age);
    void addPenguin(int age);
    void addTurtle(int age);
    
	void run(); //runs game
};

#endif
