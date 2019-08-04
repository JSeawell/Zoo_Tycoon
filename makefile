# Makefile for Project#2

# Name: Jake Seawell
# Date: 10/15/18
# Description: This Makefile shows all the files
# necessary to compile and run the executable
# file "ZooTycoon", for CS162 Project#2.

CXX = g++
CXXFLAGS = -std=c++0x
//CXXFLAGS += -g

OBJS = Zoo.o Animal.o Tiger.o Penguin.o Turtle.o Menu.o choiceFunction.o intVal.o
SRCS = Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Menu .cpp choiceFunction.cpp intVal.cpp TycoonMain.cpp
HDRS = Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Menu.hpp choiceFunction.hpp intVal.hpp


ZooTycoon: Zoo.o Animal.o Tiger.o Penguin.o Turtle.o Menu.o choiceFunction.o intVal.o TycoonMain.cpp
	${CXX} ${CXXFLAGS} ${OBJS} TycoonMain.cpp -o ZooTycoon

Zoo.o: Zoo.cpp Zoo.hpp
	${CXX} ${CXXFLAGS} -c Zoo.cpp

Animal.o: Animal.cpp Animal.hpp
	${CXX} ${CXXFLAGS} -c Animal.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	${CXX} ${CXXFLAGS} -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	${CXX} ${CXXFLAGS} -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	${CXX} ${CXXFLAGS} -c Turtle.cpp

Menu.o: Menu.cpp Menu.hpp
	${CXX} ${CXXFLAGS} -c Menu.cpp

choiceFunction.o: choiceFunction.cpp choiceFunction.hpp
	${CXX} ${CXXFLAGS} -c choiceFunction.cpp

intVal.o: intVal.cpp intVal.hpp
	${CXX} ${CXXFLAGS} -c intVal.cpp

clean:
	rm *.o ZooTycoon

#target(what to create): dependencies(what is used to make)
#(tab)action(rule to build)
