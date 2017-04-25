//------------------------------------------------------------------------------------------------
//
// File: Execute.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the execute class and its function prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef EXECUTE_H
#define EXECUTE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "GPSPos.h"
#include "Output.h"

using namespace std;

class Execute {
private:
	vector<GpsPosition*>* outputPositions; // the positions to be analyzed
	vector<Output*> printOutputs; // The outputs to be printed
	char* outputFileName; // Name of the output file
	ofstream outputFile; // Output file stream
	bool isPopulated; // Whether or not the input has anything

public:
	Execute(); // Default constructor
	Execute(char* outputFileName, vector<GpsPosition*>* outputPos); // Constructor given the output filename and the vector of positions

	void findSpeeds(int isValid); // Executes the main program functions
	bool printOutput(); // Prints the output 

};

#endif

//------------------------------------------------------------------------------------------------