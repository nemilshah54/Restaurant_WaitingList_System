#include "nshah213Proj6.h"

//------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------

// PUBLIC FUNCTIONS FOR CLASS MYLNODE.

MyLNode::MyLNode(int v1)    // Default constructor.
{
	elem = v1;       //  Initialize elem.
	next = NULL;
	identity = '0';
}

MyLNode::MyLNode(int v1, MyLNode* n)    // Default constructor.
{
	elem = v1;   // Initialize elem.
	next = n;    //  Initialize node.
	identity = '0';

}

void MyLNode::setIdentity(char status)    // Set the identity of Visited or Unvisited
{
	identity = status;
}

char MyLNode::getIdentity()
{
	return identity;
}

void MyLNode::setElem(int e)
{
	elem = e;
}

int MyLNode::getElem()
{
	return elem;
}

void MyLNode::setNext(MyLNode* n)
{
	next = n;
}

MyLNode* MyLNode::getNext()
{
	return next;
}

//-------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

// PUBLIC FUNCTIONS FOR CLASS Mylist

MyList::MyList()   // Default constructor. 
{
	head = NULL;   // Initialize head to NULL
}


/*void MyList::insert(int v1)
{
MyLNode* tmp = new MyLNode(v1);

// this code just inserts the node at the beginning of the list
tmp->setNext(head);
head = tmp;
}   */

void MyList::insert(int v1)
{
	// Code inserts value v1 in node from the back side.
	MyLNode* ptr = new MyLNode(v1);  // Value v1 is inserted in Ptr node.
	ptr->setNext(head);
	head = ptr;
}



void MyList::remove(int v1)
{
	MyLNode *prev = NULL;
	MyLNode *curr = head;

	// Condition in which element to be remove is at the first element of the node.
	if (curr != NULL && curr->getElem() == v1)
	{
		head = curr->getNext();
		delete curr;
		return;
	}
	//  Condition in which element to be remove is at the middle of the node.
	while ((curr != NULL) && (curr->getElem() != v1))
	{
		prev = curr;
		curr = curr->getNext();
	}

	if (curr == NULL)
		return;

	prev->setNext(curr->getNext());
	delete curr;

}


void MyList::show()
{
	/*while (hd != NULL)   -----C
	{
	printf("%d, ", hd->elem);
	hd = hd->next;
	}
	printf("\n");   */


	MyLNode* ptr;
	ptr = head;

	if (ptr == NULL)
	{
		printf("This airport doesn't have any flight to other airport\n\n");
		return;
	}

	while (ptr != NULL)
	{
		printf("\n Airport: %d", ptr->getElem());
		ptr = ptr->getNext();
	}

	printf("\n\n");
}

void MyList::makeIdentityU()        // Setting the identity U for all nodes in linked list.
{
	//printf("YYOYOYOYOYOYOYOYO\n");
	MyLNode* ptr;
	ptr = head;
	//printf("ggwp\n");        // Fix me.

	if (head == NULL)
	{
		printf("ggwp\n");
	}

	while (ptr != NULL)
	{

		ptr->setIdentity('U');
		ptr = ptr->getNext();
	}


}

void MyList::makeIdentityV()
{

	MyLNode* ptr;
	ptr = head;

	if (ptr == NULL)
	{
		return;
	}

	while (ptr != NULL && ptr->getIdentity() != 'U')
	{
		//printf(" VVVVV \n");   DEBUGGING
		//ptr->setIdentity('V');   DEBUGGING
		ptr = ptr->getNext();
	}

	//printf(" value is %d\n", ptr->getElem());    DEBUGGING
	//printf(" VVVVV \n");   DEBUGGING
	ptr->setIdentity('V');
	//printf(" making identity V is %c\n", ptr->getIdentity());   DEBUGGING
}

char MyList::checkIdentity()
{
// printf(" got it \n");        DEBUGGING
	MyLNode* ptr; 
	ptr = head;

	if (ptr == NULL)
	{
		//printf(" got it \n");      DEBUGGING
		return -1;
	}
	if (ptr != NULL && getNumberOfCurrentValues() == 1)
	{
		//printf(" value is %d\n", ptr->getElem());   DEBUGGING
	//	printf(" identitttty is %c\n", ptr->getIdentity());  DEBUGGING
		return ptr->getIdentity();
	}
	else
	{
		while (ptr != NULL && ptr->getIdentity() != 'U')
		{

			//printf(" identity is %c\n", ptr->getIdentity());    DEBUGGING
			ptr = ptr->getNext();
		}

		if (ptr == NULL)
		{
			return 'a';
		}
		// printf(" value is %d\n", ptr->getElem());     DEBUGGING
		return ptr->getIdentity();
	}
}

int MyList::getNumberOfCurrentValues()
{
	MyLNode* ptr;
	ptr = head;
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->getNext();
	}

	return count;
}

int MyList::getNthValue(int v1)
{
	MyLNode* ptr;
	ptr = head;
	int count = 0;

	if (ptr == NULL)
	{
		// printf(" Node is NULL");   DEBUGGGING
		return -1; 
	}
	while (ptr != NULL)
	{
		count++;
		if (count == v1)
		{
			return ptr->getElem();
		}
		ptr = ptr->getNext();
	}
}

//-------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

// PUBLIC FUNCTIONS FOR CLASS NumberOfAirports


void NumberOfAirports::setnum(int val1)
	{
		num = val1;
	}

int NumberOfAirports::getsize()
	{
		return num;
	}



