#include"pheader.h"

node* addToList( node** curr, node* ptr, char* name, int size, char c)
{
	if (c == 'a')
	{
		// node* ptr = (node*)malloc(sizeof(node));
		ptr->nameGroup = name;
		ptr->sizeGroup = size;
		ptr->statusGroup = 'V';
		ptr->next = *curr;   /* curr is always NULL at this line of code */
		return ptr;
	}

	if (c == 'c')
	{
		ptr->nameGroup = name;
		ptr->sizeGroup = size;
		ptr->statusGroup = 'U';
		ptr->next = *curr;   /* curr is always NULL at this line of code */
		return ptr;
	}
 }

// Return an integer value to check for wether the name exist or not.
int doesNameExist(node* temp, char* name, char c)
{
	int r = 0;    // Variable to return different values for different commands and inputs.

	if (c == 'a' || c == 'c')
	{
		while (temp != NULL)
		{
			if (strcmp(temp->nameGroup, name) == 0)
			{
				printf(" Group of this name already exist");
				return 1;
			}
			temp = temp->next;
		}
	}

	if (c == 'w'|| c=='l')
	{

		while ((temp != NULL) && (strcmp(temp->nameGroup, name) != 0))
		{
			temp = temp->next;
		}

		if (temp == NULL)
		{
			printf(" Name of this group does not exist in the list.");
			return 1;
		}
	}
}

// Function to return integer value which will check if the group is already in restuarant.
int updateStatus(node** ptr, char* name, char c)

{
	if (c == 'w')
	{
		node*temp = *ptr;
		while (temp != NULL)

		{
			// If condition to check the status and name of string.
			if ((temp->statusGroup == 'U') && (strcmp(temp->nameGroup, name) == 0))
			{

				temp->statusGroup = 'V';

				break;
			}
			else if ((temp->statusGroup == 'V') && (strcmp(temp->nameGroup, name) == 0))
			{
				printf("This group is already in the restuarant. ");
				return 1;
			}

			temp = temp->next;
		}
		printf("Waiting group \"%s\" is now in the restaurant\n", name);

	}

}

char* retrieveAndRemove(node* curr, int size, node** head, char c)
{
	// char* null;

	if ((curr->next != NULL) && (curr->statusGroup == 'V') && (curr->sizeGroup <= size))
	{
		*head = curr->next;

		return curr->nameGroup;      // To return the value to be popped.

		free(curr);
	}

	else
	{
		node* prev = NULL;


	start:
		while ((curr->next != NULL) && ((curr->statusGroup != 'V') || ((curr->statusGroup == 'V') && (curr->sizeGroup > size))))
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr->sizeGroup > size)
		{
			goto start;
		}

		if (curr->next == NULL)
		{
			 printf(" Nothing can be removed.");
			
			return 0;
		}


		prev->next = curr->next;

		return curr->nameGroup;   // Value to be popped.

		free(curr);
	}

}


// Function returning integer value that will count the number of groups waiting ahead.
int countGroupsAhead(node* head, int count, char* name, char c)
{
	while ((head != NULL) && (strcmp(head->nameGroup, name) != 0))
	{
		count++;

		head = head->next;
	}

	return count;
}

// Funnction display the name and size of the group waiting ahead.
void displayGroupSizeAhead(node* head, int count, char* name, char c, int debugMODE)
{
	while ((head != NULL) && (strcmp(head->nameGroup, name) != 0))
	{
		count++;
		
		if( debugMODE== TRUE)
		printf("%d. Group of name %s and size %d is waiting ahead.\n", count, head->nameGroup, head->sizeGroup);

		head = head->next;
	}

}

// Function that will display the list the information of all groups including status.
void displayListInformation(int count, node* head, char c, int debugMODE)
{

	while (head != NULL)
	{
		count++;

		if( debugMODE== TRUE)
		 printf("%d. Name and size of the group = %s, %d ", count, head->nameGroup, head->sizeGroup);

		if (head->statusGroup == 'U')
		{
			if( debugMODE== TRUE)
			printf(" Status---Group is not at restuarant.\n ");
		}

		if (head->statusGroup == 'V')
		{
			 if( debugMODE== TRUE)
			printf(" Status---Group is at restuarant.\n");
		}

		head = head->next;
	}
}
