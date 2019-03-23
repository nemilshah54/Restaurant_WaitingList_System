#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// Declaring a struture for the group.
struct nodeStruct
{
	char* nameGroup;         // Name of the group   ..Nemil
	int sizeGroup;           // Size of the group....4
	char statusGroup;        // Visit or Unvisited status of the group.
							 // Visit (V) as group already went to restaurant and waiting there.
							 // Unvisited (U) as group has not been there at restaurant and waiting by calling.

	struct nodeStruct*  next;
};

typedef struct nodeStruct node;

// typedef enum { FALSE = 0, TRUE, NO = 0, YES } boolean;



void doAdd(node** head, char c);

void doCallAhead(node** head, char c);

void doWaiting(node** head, char c);

void doRetrieve(node** head, char c);

void doList(node* head, char c, int debugMODE);

void doDisplay(node* head, char c, int debugMODE);

int getNextNWSChar();

int getPosInt();

char *getName();

void clearToEoln();

void printCommands();

node* addToList( node** curr, node* ptr, char* name, int size, char c);

int doesNameExist(node* temp, char* name, char c);

int updateStatus(node** ptr, char* name, char c);

char* retrieveAndRemove(node* curr, int size, node** head, char c);

int countGroupsAhead(node* head, int count, char* name, char c);

void displayGroupSizeAhead(node* head, int count, char* name, char c, int debugMODE);

void displayListInformation(int count, node* head, char c, int debugMODE);




