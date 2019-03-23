#include"pheader.h"

void doAdd(node** head, char c)
{
	/* get group size from input */
	int size = getPosInt();
	if (size < 1)
	{
		printf("Error: Add command requires an integer value of at least 1\n");
		printf("Add command is of form: a <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Add command requires a name to be given\n");
		printf("Add command is of form: a <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	// Code for error message.   
	node* temp = *head;

	int a = 0;
	
	a = doesNameExist(temp, name, c);

	if (a ==1)
	{
		return;
	}
	
	printf("Adding group \"%s\" of size %d\n", name, size);


  // Reference code to be transfer.
	node* curr = *head;
	node* prev = NULL;

	/* find the end of the list */
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
	}

	node* ptr = (node*)malloc(sizeof(node));
	ptr = addToList(&curr, ptr, name, size, c);

	if (prev == NULL)
	{
		*head = ptr;
	}
	else
	{
		prev->next = ptr;
	}   

	 
}


void doCallAhead(node** head, char c)
{
	/* get group size from input */
	int size = getPosInt();
	if (size < 1)
	{
		printf("Error: Call-ahead command requires an integer value of at least 1\n");
		printf("Call-ahead command is of form: c <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Call-ahead command requires a name to be given\n");
		printf("Call-ahead command is of form: c <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	// Code for error checking.

	int cc = 0;
	node*temp = *head;

	cc = doesNameExist(temp, name, c);

	if (cc == 1)
	{
		return;
	}

	printf("Call-ahead group \"%s\" of size %d\n", name, size);

	// Code For pushing the list from end.

	node* curr = *head;
	node* prev = NULL;

	/* find the end of the list */
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
	}

	/* create the new node to be inserted into the list */

	node* ptr = (node*)malloc(sizeof(node));

	ptr = addToList(&curr, ptr, name, size, c);

	if (prev == NULL)
	{
		*head = ptr;
	}
	else
	{
		prev->next = ptr;
	}
}



// Function called from  dowaiting to change the status of callhead group from 'U' to 'V'.
void doWaiting(node** head, char c)
{
	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Waiting command requires a name to be given\n");
		printf("Waiting command is of form: w <name>\n");
		printf("  where: <name> is the name of the group that is now waiting\n");
		return;
	}

	node* temp = *head;

	int d = 0;
	
	d = doesNameExist(temp,name, c);

	if (d == 1)
	{
		return ;
	}

	node*ptr = *head;

	int x = 0;

	 x = updateStatus( &ptr, name, c);
}


void doRetrieve(node** head, char c)
{
	/* get table size from input */
	int size = getPosInt();
	if (size < 1)
	{
		printf("Error: Retrieve command requires an integer value of at least 1\n");
		printf("Retrieve command is of form: r <size>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		return;
	}
	clearToEoln();
	printf("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);


	//  Code to pop from the middle.
	node* curr = *head;
	
	char* ready;

	ready = retrieveAndRemove(curr, size, head, c);

	/*if (ready == " remove")            // Fix this.
	{
		printf(" Nothing can be removed.");
	}   */
	if (ready != 0)
	{
		printf(" Name of the group which is ready is: %s", ready);
	}
}
 


void doList(node* head, char c, int debugMODE)
{
	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: List command requires a name to be given\n");
		printf("List command is of form: l <name>\n");
		printf("  where: <name> is the name of the group to inquire about\n");
		return;
	}

	int l = 0;
	node*temp = head;

	l = doesNameExist(temp, name, c);   

	if (l == 1)
	{
		return;
	}

	printf("Group \"%s\" is behind the following groups\n", name);

	// Code to  count the number of groups ahead of this name.
	// Also display the size of each group.

	int count = 0;

	int total = 0;

	count = countGroupsAhead(head, count, name, c);
	
	if( debugMODE== TRUE)
	printf(" The total number of groups waiting ahead are %d groups \n", count);

	displayGroupSizeAhead (head,total, name, c,debugMODE );

}


void doDisplay(node* head, char c, int debugMODE)
{
	clearToEoln();
	
	if( debugMODE== TRUE)
	printf("Display information about all groups\n");


	int count = 0;

	displayListInformation(count, head, c, debugMODE);
}