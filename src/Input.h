//------------------------------------------------------------------------------------------------
//
// File: input.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the input class and its function prototpyes
//
//------------------------------------------------------------------------------------------------

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "GPSPos.h"

using namespace std;

class Input {
private:
	char* inputFileName; // Input filename
	ifstream inputFile; // Input filestream
	vector<GpsPosition*> inputPositions; // Input graph 

	void addPosition(double latitude, double longitude, unsigned long timeSeconds); // Adds a new GPS Position to the vector of inputPositions

	bool checkIfDigits(string input); // Checks a string to see if it is digits only
	double convDMS(double DMS); // Converts DMS to decimal degrees
	double convTimeIn(int timeIn); // Converts the input time to the time in seconds
	bool isGPGGA(string lineFirst); // Checks the string to see if it is the correct format

public:
	Input(); // Default constructor
	Input(char* inputFileName); // Creates the input class given a filename

	int getInput(); // Reads the inputs and creates the graph, returns true if successful, false if not

	vector<GpsPosition*>& returnInputPositions(); // Returns a reference to the inputted GPS positions
};

#endif