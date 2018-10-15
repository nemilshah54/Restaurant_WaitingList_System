#include "nshah213Proj6.h"

//------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------

int main(int argc, char** argv)
{
	// set up the variable inFile to read from standard input
	FILE* inFile = stdin;

	// set up the data needed for the airport adjcency list
	TravelNetwork airportData;

	// call the method that reads and parses the input
	airportData.processCommandLoop(inFile);

	printf("Goodbye\n");
	return 1;
}


// PUBLIC FUNCTIONS FOR CLASS TRAVEL NETWORK.

TravelNetwork::TravelNetwork()
	{
		airports = NULL;
	}

void TravelNetwork:: processCommandLoop(FILE* inFile)
{


		char  buffer[300];
		char* input;
		printf(" Press ? command to know the following commands \n");
		input = fgets(buffer, 300, inFile);   // get a line of input

											  // loop until all lines are read from the input
		while (input != NULL)
		{
			// process each line of input using the strtok functions 
			char* command;
			command = strtok(input, " \n\t");

			printf("*%s*\n", command);

			if (command == NULL)
				printf("Blank Line\n");

			else if (strcmp(command, "q") == 0)
				exit(1);

			else if (strcmp(command, "?") == 0)
				showCommands();

			else if (strcmp(command, "t") == 0)
				doTravel(&airports);

			else if (strcmp(command, "r") == 0)
				doResize(&airports);

			else if (strcmp(command, "i") == 0)
				doInsert(&airports);

			else if (strcmp(command, "d") == 0)
				doDelete(&airports);

			else if (strcmp(command, "l") == 0)
				doList(&airports);

			else if (strcmp(command, "f") == 0)
				doFile(inFile);

			else if (strcmp(command, "#") == 0)
				;

			else
				printf("Command is not known: %s\n", command);

			input = fgets(buffer, 300, inFile);   				// get the next line of input

		}
		return;
	}


void TravelNetwork::showCommands()
	{
		printf("The commands for this project are:\n");
		printf("  q \n");
		printf("  ? \n");
		printf("  # \n");
		printf("  t <int1> <int2> \n");
		printf("  r <int> \n");
		printf("  i <int1> <int2> \n");
		printf("  d <int1> <int2> \n");
		printf("  l \n");
		printf("  f <filename> \n");
	}


void TravelNetwork::doTravel(MyList** airports)
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}
		if ((val1> numAirports.getsize()) || (val2>numAirports.getsize()))
		{
			printf(" No airport exist.\n");
			return;
		}


		printf("Performing the Travel Command from %d to %d\n",
			val1, val2);

		int c = 0;
		MyList *ptrAirports = *airports;      
		dfshelper(val1, val2, &ptrAirports);
	}


void TravelNetwork::dfshelper(int x, int y, MyList **list)
	{
		MyList *List;
		List = *list;

		for (int i = 1; i <= numAirports.getsize(); i++)
		{

			airports[i].makeIdentityU();
			//printf("YYOYOYOYOYOYOYOYO\n");
			//list[i].setLul();
		}


		// printf ("You can get from airport “ %d “ to airport “ %d “ in one or more flights\n",x,y);

		if (dfs(x, y, List) == true)
		{
			printf("You can get from airport “ %d “ to airport “ %d “ in one or more flights\n", x, y);

		}

		else
			printf("You can NOT get from airport “ %d “ to airport “ %d “ in one or more flights\n", x, y);

	}


bool TravelNetwork:: dfs(int a, int b, MyList *planelist)
	{
		int c;
		MyList *originalList;
		originalList = planelist;

	for (int i = 1; i <= originalList[a].getNumberOfCurrentValues(); i++)
	{
		c = originalList[a].getNthValue(i);
		//printf(" Value of c is %d: \n", c);   // Debug
		while (c != -1)
		{
			if (c == b)
				return true;

			else
			{
				//printf("jjjj");    DEBUGGING
				if (originalList[a].checkIdentity() == 'U')
				{
					originalList[a].makeIdentityV();
					if (dfs(c, b, originalList) == true)
					{
						return true;
					}
					else
					{
						break;
					}

				}
				else
				{
				// 	printf(" noooooooooo \n");   DEBUGGING
					break;
				}

			}
		}
	}

		// printf(" no flight from here");   DEBUGGING
		 return false;
	}


void TravelNetwork::doResize(MyList** airports)
	{
		int val1 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);     // This value will create the number of objects for linked list.

		numAirports.setnum(val1);

		if (*airports != NULL)
			delete(*airports);

		if (val1 > 10)
		{
			printf(" Maximum limit exceeded for creating the number of airports\n");
			return;
		}
		else
		{
			*airports = new MyList[val1 + 1];       // Creates a N number of objects i.e N airports.
			printf(" The number of aeroports are: %d\n", val1);
			printf(" The number of aeroports are: %d\n", numAirports.getsize());

		}


	}


void TravelNetwork:: doInsert(MyList** airports)
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");


		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		//Main Code after reading the two integer values.

		MyList *ptrAirports = *airports;     // Ptr as temp pointing towards the airports.

		printf("Airport %d has a flight going to %d airport\n", val1, val2);

		if ((val1> numAirports.getsize()) || (val2>numAirports.getsize()))
		{
			printf(" No airport exist.\n");
			return;
		}
		else
		{

			ptrAirports[val1].insert(val2);     // Val 2 is inserted in val1 th number of airport.

		}

	}


void TravelNetwork::doDelete(MyList** airports)
	{
		int val1 = 0;
		int val2 = 0;

		// get an integer value from the input
		char* next = strtok(NULL, " \n\t");
		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val1 = atoi(next);
		if (val1 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		// get another integer value from the input
		next = strtok(NULL, " \n\t");


		if (next == NULL)
		{
			printf("Integer value expected\n");
			return;
		}
		val2 = atoi(next);
		if (val2 == 0 && strcmp(next, "0") != 0)
		{
			printf("Integer value expected\n");
			return;
		}

		printf("Airport %d now doesn't have a flight connection with airport %d \n", val1, val2);
		//Main Code after reading the two integer values.
		MyList *ptrAirports = *airports;     // Ptr as temp pointing towards the airports.

		if (val1> numAirports.getsize())
		{
			printf(" No airport exist.\n");
			return;
		}
		else
		{
			printf(" hello");
			ptrAirports[val1].remove(val2); //Val 2 is inserted in val1 th number of airport.
		}

	}


void TravelNetwork::doList(MyList** airports)
	{
		MyList *ptrAirports = *airports;

		for (int i = 1; i <= numAirports.getsize(); i++)
		{
			printf("Airport %d flies to the following airports: \n", i);
			ptrAirports[i].show();
		}
	}


void TravelNetwork::doFile(FILE *newFile)
	{

		TravelNetwork airportData1;
		// get a filename from the input
		char* fname = strtok(NULL, " \n\t");
		if (fname == NULL)
		{
			printf("Filename expected\n");

			return;
		}
		if ((newFile = fopen(fname, "r")) == NULL)
		{
			printf("Can't open input file: %s", fname);
			return;
		}

		printf("Performing the File command with file: %s\n", fname);
		airportData1.processCommandLoop(newFile);     					 // passing the file as input so it will take input from the file.

																	 // next steps:  (if any step fails: print an error message and return ) 
																	 //  1. verify the file name is not currently in use
																	 //  2. open the file using fopen creating a new instance of FILE*
																	 //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
																	 //  4. close the file when processCommandLoop() returns
	}
