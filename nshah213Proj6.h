/* This file contains the user interface code for the "Can I get from here" project
 *  Project 6 for CS 211 for Fall 2017
 *
 * Date: 11/20/17
 *
 * Author: Nemil Shah
 *
 */


#include<stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>

// The node class for the linked list  
class MyLNode
{
private:
	int elem;
	char identity;
	MyLNode* next;

public:
	MyLNode(int v1);    // Default constructor. Initialize elem.
	MyLNode(int v1, MyLNode* n);  // Default constructor. Initialize node and elem.

	void setElem(int e);    // Assign the value in node.
	int getElem();       // Access the elem value of node.
	void setNext(MyLNode* n);   // Assign next node to list.
	MyLNode* getNext();   // Access next node of list.
	void setIdentity(char identity);   // Assign the idenity to be visited or unvisited.
	char getIdentity();    // Access the idenity to be visited or unvisited.

};


//  Class for my Linked list.  Maintains the entire list. Push and pop operations over here.
class MyList
{
private:
	MyLNode* head;

public:
	MyList();

	void show();
	void insert(int v1);
	void remove(int v1);
	void makeIdentityU();
	int getNumberOfCurrentValues();
	int getNthValue(int v1);
	void makeIdentityV();
	char checkIdentity();
};


class NumberOfAirports
{
private:
	int num;

public:

	void setnum(int val1);
	int getsize();
	
};

class TravelNetwork
{
private:
	// Create the Data Members for the Travel Network here
	MyList *airports;      // Dynamic memory of aeroports. It is dynamic memory of linked list.
	NumberOfAirports numAirports;

public:

TravelNetwork();
void processCommandLoop(FILE* inFile);
void showCommands();
void doTravel(MyList** airports);
void dfshelper(int x, int y, MyList **list);
bool dfs(int a, int b, MyList *planelist);
void doResize(MyList** airports);
void doInsert(MyList** airports);
void doDelete(MyList** airports);
void doList(MyList** airports);
void doFile(FILE *newFile);
};
