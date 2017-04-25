//------------------------------------------------------------------------------------------------
//
// File: main.cpp
// Author: Coby Allred
// Date: 12/6/16
//
// Description: Executes the velociplotter program
//
//------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "GPSPos.h"
#include "Input.h"
#include "Execute.h"

//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {

	if (argc != 3) { // If incorrect # arguments, print usage and exit
		printf("Usage: velociplotter gpsLogFile gpsPlotDataFile");
		return EXIT_FAILURE;
	}

	Input GPSInput(argv[1]); // Creates the input class
	int inputValid = GPSInput.getInput();

	if(inputValid == 1){ // If inputValid is not equal to 0 (true) then error and exit
		cout << "Error opening " << argv[1] << " for input." << endl;
		return EXIT_FAILURE;
	}
	else if (inputValid == 2) {
		cout << "Error in timestamps of " << argv[1] << " (Not > previous value)." << endl; // Project description says to print error if not > previous
	}

	Execute GNUOutput(argv[2], &GPSInput.returnInputPositions()); // Creates the execute class

	GNUOutput.findSpeeds(inputValid); // Finds the average speed for each second
	if (GNUOutput.printOutput() == true) { // Prints the output
	} 
	else { // If an error in output creation, print error and exit
		cout << "Error creating output file " << argv[3] << "." << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------------------------
