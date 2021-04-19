#include <iostream>
#include <string>

using namespace std;

struct Location
{
	string description;
	Location * north, *south, *east, *west;
};

void setupLocation(Location * locatPtr, string descript, 
	Location * N, Location * S, Location * E, Location * W);

void outputLocation(Location * currLoc);

int main()
{
	// Location object creation
	Location forest1;
	Location forest2;
	Location forest3;
	Location hill;
	Location mountain;
	Location riverBank1;
	Location riverBank2;
	Location quickSand;
	Location openPlain;
	Location meadow;
	Location abandonedHut;
	Location lake;
	Location * currentLocationPtr;

	// Initialising Location object values
	//				lPtr, desc,		North,	South,		East,	West
	setupLocation(&forest1, "Forest One", NULL, &hill, &forest2, NULL);
	setupLocation(&forest2, "Forest Two", NULL, &forest3, &quickSand, &forest1);
	setupLocation(&quickSand, "Quick Sand", NULL, NULL, NULL, NULL);
	setupLocation(&meadow, "Meadow", NULL, &abandonedHut, NULL, &quickSand);
	setupLocation(&abandonedHut, "Abandoned Hut", &meadow, &lake, NULL, NULL);
	setupLocation(&openPlain, "Open Plain", &quickSand, &riverBank2, &abandonedHut, &forest3);
	setupLocation(&forest3, "Forest Three", &forest2, NULL, NULL, NULL);
	setupLocation(&hill, "Hill", &forest1, &mountain, &forest3, NULL);
	setupLocation(&mountain, "Mountain", &hill, NULL, NULL, NULL);
	setupLocation(&riverBank1, "River Bank One", &forest3, NULL, &riverBank2, NULL);
	setupLocation(&riverBank2, "River Bank Two", NULL, NULL, &lake, &riverBank1);
	setupLocation(&lake, "Lake", NULL, NULL, NULL, &riverBank2);

	// Setting up current location
	currentLocationPtr = &abandonedHut;
	
	// ****The main game loop****
	while (currentLocationPtr != &quickSand && currentLocationPtr != &mountain)
	{
		// Output location
		outputLocation(currentLocationPtr);

		cout << endl;

		cout << "Which direction would you like to travel?" << endl;
		cout << "Please enter 'n', 's', 'e' or 'w'" << endl;

		// User input for direction
		char charVar;
		cin >> charVar;

		switch (charVar)
		{
		case 'N':
		case 'n':
			// statement
			if (currentLocationPtr->north != NULL)
				currentLocationPtr = currentLocationPtr->north;
			cout << "You travelled north!" << endl;
			break;

		case 'S':
		case 's':
			// statements
			if (currentLocationPtr->south != NULL)
				currentLocationPtr = currentLocationPtr->south;
			cout << "You travelled south!" << endl;
			break;

		case 'E':
		case 'e':
			// statements
			if (currentLocationPtr->east != NULL)
				currentLocationPtr = currentLocationPtr->east;
			cout << "You travelled east!" << endl;
			break;

		case 'W':
		case 'w':
			// Statements
			if (currentLocationPtr->west != NULL)
				currentLocationPtr = currentLocationPtr->west;
			cout << "You travelled west!" << endl;
			break;
		default:
			cout << "That key is not recognised. Try again!" << endl;
		}
		cout << endl;
	}

	if (currentLocationPtr == &quickSand)
		cout << "Oh no, we fell into the quick sand! Game over!" << endl;
	else
		cout << "You made it to the mountain! Congrats!" << endl;

	cout << endl;
	
	system("pause");

	return 0;
}

void setupLocation(Location * locatPtr, string descript,
	Location * N, Location * S, Location * E, Location * W)
{
	locatPtr->description = descript;
	locatPtr->north = N;
	locatPtr->south = S;
	locatPtr->east = E;
	locatPtr->west = W;
}

void outputLocation(Location * currLoc)
{
	cout << "You have reached the " << currLoc->description << "." << endl;
	cout << "From the " << currLoc->description << " you can travel to: ";

	if (currLoc->north != NULL)
		cout << currLoc->north->description << "(north), ";

	if (currLoc->south != NULL)
		cout << currLoc->south->description << "(south), ";

	if (currLoc->east != NULL)
		cout << currLoc->east->description << "(east), ";

	if (currLoc->west != NULL)
		cout << currLoc->west->description << "(west), ";

	cout << endl;
}