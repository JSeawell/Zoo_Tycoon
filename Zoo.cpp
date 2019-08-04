/*******************************
            Zoo class
 
 Name: Jake Seawell
 Date: 10/11/18
 Description:
 
 This is the class implementation
 file for a class called Zoo,
 which represents a zoo  that holds
 animals in a zoo tycoon game.
 
 This class has pointer members for
 different animals in the zoo
 
 ******************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
using std::cout;
using std::endl;

#include "Zoo.hpp"
#include "intVal.hpp"
#include "choiceFunction.hpp"
#include "Menu.hpp"

/*************************************
 Zoo::Zoo
 
 This is the default constructor,
 which creates all the animal arrays
 and sets the player's budget
 
 *************************************/
Zoo::Zoo()
{
    //initialize array sizes to 10
    tigerSize = 10;
	penguinSize = 10;
	turtleSize = 10;
    
    //create new animal arrays of pointers
    tigerPtr = new Tiger* [tigerSize];
	penguinPtr = new Penguin* [penguinSize];
	turtlePtr = new Turtle* [turtleSize];

    //initialize animal counts
    numTig = 0;
    numPen = 0;
    numTur = 0;
    
	//initialize user budget
    budget = 100000;
}

/*************************************
 Zoo::addTiger
 
 This function adds a Tiger object to
 the tiger array.
 
 *************************************/
void Zoo::addTiger(int age)
{
        //if array needs to be bigger
        if (numTig == tigerSize)
        { 
		Tiger** newPtr; //new array
	
		newPtr = new Tiger* [(tigerSize * 2)];
		for (int i = 0; i < tigerSize; i++)
		{
			newPtr[i] = tigerPtr[i]; //fill new
		}
		delete [] tigerPtr; //delete old array
		tigerPtr = newPtr; //point to new array
		tigerSize = (tigerSize * 2);
        }
	
	tigerPtr[numTig] = new Tiger; //add tiger object to array
	tigerPtr[numTig]->setAge(age); //set age of tiger
	numTig = numTig + 1; //increase tiger count
}

/*************************************
 Zoo::addPenguin
 
 This function adds a Penguin object to
 the penguin array.
 
 *************************************/
void Zoo::addPenguin(int age)
{
        //if array needs to be bigger
        if (numTig == penguinSize)
        { 
		Penguin** tempPtr; //new array
	
		tempPtr = new Penguin* [(penguinSize * 2)];
		for (int i = 0; i < penguinSize; i++)
		{
			tempPtr[i] = penguinPtr[i]; //fill new
		}
		delete [] penguinPtr; //delete old array
		penguinPtr = tempPtr; //point to new array
		penguinSize = (penguinSize * 2);
        }

	penguinPtr[numPen] = new Penguin; //add penguin object to array
    penguinPtr[numPen]->setAge(age); //set age of penguin
	numPen = numPen + 1; //increase penguin count
}

/*************************************
 Zoo::addTurtle
 
 This function adds a Turtle object to
 the turtle array.
 
 *************************************/
void Zoo::addTurtle(int age)
{
        //if array needs to be bigger
        if (numTig == turtleSize)
        { 
		Turtle** tempPtr; //new array
	
		tempPtr = new Turtle* [(turtleSize * 2)];
		for (int i = 0; i < turtleSize; i++)
		{
			tempPtr[i] = turtlePtr[i]; //fill new
		}
		delete [] turtlePtr; //delete old array
		turtlePtr = tempPtr; //point to new array
		turtleSize = (turtleSize * 2);
        }

    	turtlePtr[numTur] = new Turtle; //add turtle object to array
	turtlePtr[numTur]->setAge(age); //set age of turtle
	numTur = numTur + 1; //increase turtle count
}

/*************************************
 Zoo::run
 
 This function runs the Zoo Tycoon game
 
 *************************************/
void Zoo::run()
{
	
    int playOrNaw;
    playOrNaw = choiceFunction("Would you like to play Zoo Tycoon?", "Yes, play", "No, quit");
    if (playOrNaw == 1)
    {
    
        cout << "::Zoo Tycoon::" << endl << endl;

	cout << "To start the game, you need to buy some animals." << endl;
	cout << "There are 3 types of animals you can buy:" << endl;
	cout << "Tigers, Penguins, and Turtles." << endl << endl;
	
	cout << "You have a budget of $" << budget << endl << endl;
	//purchase tigers (1 or 2)
        int numTigers;
        numTigers = choiceFunction("How many Tigers would you like to purchase? They cost $10,000 each","One Tiger", "Two Tigers");
        if (numTigers == 1)
            addTiger(1);//add tiger age 1
        else if (numTigers ==2)
        {
            addTiger(1);
            addTiger(1);
        }
	budget = (budget - (numTig * 10000));
	cout << "You have $" << budget << " remaining." << endl << endl;

        //purchase penguins (1 or 2)
        int numPenguins;
        numPenguins = choiceFunction("How many Penguins would you like to purchase? They cost $1,000 each","One Penguin", "Two Penguins");
        if (numPenguins == 1)
            addPenguin(1);//add penguin age 1
        else if (numPenguins ==2)
        {
            addPenguin(1);
            addPenguin(1);
        }
	budget = (budget - (numPen * 1000));
	cout << "You have $" << budget << " remaining." << endl << endl;

        //purchase turtles (1 or 2)
        int numTurtles;
        numTurtles = choiceFunction("How many Turtles would you like to purchase? They cost $100 each","One Turtle", "Two Turtles");
        if (numTurtles == 1)
            addTurtle(1);//add turtle age 1
        else if (numTurtles ==2)
        {
            addTurtle(1);
            addTurtle(1);
        }
        budget = (budget - (numTurtles * 100));

        srand(time(0));
        int dayNum = 1;
	int keepPlay = 1;

        while ((budget > 0) && (keepPlay == 1)) //if there is money, allow user to continue
        {
	    cout << "Day: " << dayNum << endl;
            cout << "You have $" << budget << " in your budget." << endl << endl;
        
            //increase age of all animals by 1 day
            for (int i = 0; i < numTig; i++)
            {
                tigerPtr[i]->grow1day();
            }
            for (int i = 0; i < numPen; i++)
            {
                penguinPtr[i]->grow1day();
            }
            for (int i = 0; i < numTur; i++)
            {
                turtlePtr[i]->grow1day();
            }
		
            cout << "You need to feed your animals." << endl;
            
            Menu menu2(3,"What type of food would you like to buy?");
            menu2.setOption(1, "Regular food - regular price, no health benefit");
            menu2.setOption(2, "Cheap food - half price, sickness twice as likely to occur");
            menu2.setOption(3, "Premium food - double price, sickness half as likely to occur");
            int foodType;
            foodType = minMaxValidation(menu2.displayMenu(),1,3);
            
            //feed tigers
            int tigerFood = 0;
            if (foodType == 1)
                tigerFood = (numTig * 50);
            else if (foodType == 2)
                tigerFood = (numTig * 50 / 2);
            else if (foodType == 3)
                tigerFood = (numTig * 50 * 2);
            
            //feed penguins
            int penguinFood = 0;
            if (foodType == 1)
                penguinFood = (numPen * 10);
            else if (foodType == 2)
                penguinFood = (numPen * 10 / 2);
            else if (foodType == 3)
                penguinFood = (numPen * 10 * 2);
            
            //feed turtles
            int turtleFood = 0;
            if (foodType == 1)
                turtleFood = (numTur * 5);
            else if (foodType == 2)
                turtleFood = (numTur * 5 / 2);
            else if (foodType == 3)
                turtleFood = (numTur * 5 * 2);
            
            cout << "You spent $" << tigerFood + penguinFood + turtleFood << " on food." << endl;
        
            //subtract food costs from budget
            budget = (budget - tigerFood - penguinFood - turtleFood);
            cout << endl << "You have $" << budget << " remaining." << endl;
            
            //random event
            int randEvent;
            cout << endl << "Random event occuring..." << endl;

            if (foodType == 1) //regular
                randEvent = minMaxRand(1, 4); //1 in 4 chance
            else if (foodType == 2) //cheap
                randEvent = minMaxRand(1,6); //3 in 6 chance
            else if (foodType == 3) //premium
                randEvent = minMaxRand(1,24); //3 in 24 chance 
                //sickness occurs
                if ((randEvent == 1 || randEvent == 5 || randEvent == 6) && (numTig > 0 || numPen > 0 || numTur > 0))
                {
                    cout << "A sickness occured today.." << endl << endl;
                    int sick;
                    sick = minMaxRand(1,3);
		    if (sick == 3 && numTig > 0)
                    {
                        cout << "A tiger got sick and died." << endl << endl;
                        //IDK what to do here
                        numTig = numTig - 1;
                    }
                    else if (sick == 2 && numPen > 0)
                    {
                        cout << "A penguin got sick and died." << endl << endl;
                        numPen = numPen - 1;
                    }
                    else if (sick == 1 && numTur > 0)
                    {
                        cout << "A turtle got sick and died." << endl << endl;
                        numTur = numTur - 1;
                    }
                    else
                    {
                        cout << "Luckily, it was treated by your vet, but she charged you $100 for her services." << endl;
			budget = (budget - (1000 * sick));
			cout << "You have $" << budget << "." << endl << endl;
                    }
                }
                else if (randEvent == 2 || randEvent == 7 || randEvent == 8 || randEvent == 9 || randEvent == 10 || randEvent == 11 || randEvent == 12)//boom in zoo attendance
                {
                    cout << "The zoo experienced an attendance boom today!"  << endl;
                    int bonus = minMaxRand(250, 500);
                    cout << "You get a bonus of $" << bonus << " per tiger in the zoo." << endl;
                    cout << "A total of $" << (bonus * numTig) << " was added to your budget." << endl << endl;
                    budget += (bonus * numTig);
                }
                else if (randEvent == 3 || randEvent == 13 || randEvent == 14 || randEvent == 15 || randEvent == 16 || randEvent == 17 || randEvent == 18)//baby is born
                {
                    int baby = minMaxRand(1,3);
		    if (baby == 1)
                    {
                        bool parent = false;
                        for (int i = 0; i < numTig; i++)
                        {
                            if (tigerPtr[i]->getAge() >= 3)
                            {
                                parent = true;
                            }
                        }
                        if (parent == true)
                        {
                            cout << "A baby tiger was born today!" << endl;
                            addTiger(0);
                        }
                        else
                            baby = minMaxRand(2,3);
                    }
                    
                    if (baby == 2)
                    {
                        bool parent = false;
                        for (int i = 0; i < numPen; i++)
                        {
                            if (penguinPtr[i]->getAge() >= 3)
                            {
                                parent = true;
                            }
                        }
                        if (parent == true)
                        {
                            cout << "A baby penguin was born today!" << endl;
                            addPenguin(0);
                        }
                        else
                            baby = 3;
                    }
                    
                    
                    if (baby == 3)
                    {
                        bool parent = false;
                        for (int i = 0; i < numTur; i++)
                        {
                            if (turtlePtr[i]->getAge() >= 3)
                            {
                                parent = true;
                            }
                        }
                        if (parent == true)
                        {
                            cout << "A baby turtle was born today!" << endl;
                            addTurtle(0);
                        }
                        else
                        {
                            bool parent = false;
                        	for (int i = 0; i < numTig; i++)
                        	{
                            		if (tigerPtr[i]->getAge() >= 3)
                            		{
                                		parent = true;
                            		}
                        	}
                        	if (parent == true)
                        	{
                            		cout << "A baby tiger was born today!" << endl;
                            		addTiger(0);
                        	}
                        	else
                            {
                                bool parent = false;
                                for (int i = 0; i < numPen; i++)
                                {
                                    if (penguinPtr[i]->getAge() >= 3)
                                    {
                                        parent = true;
                                    }
                                }
                                if (parent == true)
                                {
                                    cout << "A baby penguin was born today!" << endl;
                                    addPenguin(0);
                                }
                                else
                                {
				    	cout << "An animal tried to give birth today, but was too young." << endl;
                            	}
			    }
                    	}
                    }
                }
                else if (randEvent == 4 || randEvent == 19 || randEvent == 20 || randEvent == 21 || randEvent == 22 || randEvent == 23 || randEvent == 24) //no random event
                {
                    cout << "Nothing new to report today." << endl;
                }
                cout << endl;
		
            //calculate daily profit/loss (incl. bonus)
            int tigerPayoff;
            tigerPayoff = numTig * 2000;
                            
            int penguinPayoff;
            penguinPayoff = numPen * 100;
                            
            int turtlePayoff;
            turtlePayoff = numTur * 5;
	
            cout << "You earned $" << tigerPayoff + penguinPayoff + turtlePayoff << " for your animals." << endl;
                    
            budget = (budget + tigerPayoff + penguinPayoff + turtlePayoff);
        
            cout << "It's the end of the day!" << endl;
	    cout << endl << "After day: " << dayNum << endl;
            cout << "You have $" << budget << " remaining." << endl;
            dayNum = dayNum + 1;
                    
            int newAnimal;
	    newAnimal = choiceFunction("Would you like to buy a new adult animal for tomorrow?", "Yes", "No, thanks");
            if (newAnimal == 1)
            {
                Menu menu1(3, "Which type of animal would you like to buy?");
                menu1.setOption(1, "Tiger: $10,000");
                menu1.setOption(2, "Penguin: $1000");
                menu1.setOption(3, "Turtle: $100");
			
                int animalChoice;
                animalChoice = minMaxValidation(menu1.displayMenu(),1,3);
			
                if (animalChoice == 1)
                {
				
                    cout << "You bought a Tiger!" << endl;
                    addTiger(3);//add tiger age 3
                    budget = budget - 10000;
                }
                if (animalChoice == 2)
                {
                    cout << "You bought a Penguin!" << endl;
                    addPenguin(3);//add tiger age 3
                    budget = budget - 1000;
                }
                if (animalChoice == 3)
                {
                    cout << "You bought a Turtle!" << endl;
                    addTurtle(3);//add tiger age 3
                    budget = budget - 100;
                }
            }

            
	    //display number of animals and their ages
            cout << endl << "You have " << numTig << " Tigers." << endl;
            for (int i = 0; i < numTig; i++)
            {
                cout << "Tiger " << (i + 1) << " is " << tigerPtr[i]->getAge() << " days old." << endl;
            }
            cout << endl << "You have " << numPen << " Penguins." << endl;
            for (int i = 0; i < numPen; i++)
            {
                cout << "Penguin " << (i + 1) << " is " << penguinPtr[i]->getAge() << " days old." << endl;
            }
            cout << endl << "You have " << numTur << " Turtles." << endl;
            for (int i = 0; i < numTur; i++)
            {
                cout << "Turtle " << (i + 1) << " is " << turtlePtr[i]->getAge() << " days old." << endl;
            }


	    cout << "You have $" << budget << " remaining." << endl;
            keepPlay = choiceFunction("Ready to play another day?", "Yes, keep playing.", "No, I'd like to quit.");

        }
	
        if (keepPlay == 1)
        {
            cout << endl << "Sorry, but you're all out of money." << endl;
	    cout << "You lost: " << (100000 - budget) << " dollars." << endl;
        }
        if (keepPlay == 2)
	{
		cout << "Game quit." << endl;
		cout << "You made a profit of: " << (budget - 100000) << " dollars." << endl; 
		cout << "Game over." << endl;
	}
    }
    else if (playOrNaw == 2)
    {
        cout << "Game quit." << endl;
    }
    
    //Delete dynamic arrays and pointers
    delete [] tigerPtr;
    delete [] penguinPtr;
    delete [] turtlePtr;
    tigerPtr = NULL;
    penguinPtr = NULL;
    turtlePtr = NULL;
    cout << "Program ended." << endl << endl;
}
