//------------------------------------------------------------------------------------------------
//
// File: Output.h
// Author: Coby Allred
// Date: 12/6/16
//
// Description: Defines the output class and its function prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "GPSPos.h"

using namespace std;

class Output {
private:
	int time; // Time to be printed
	double speed; // Speed to be printed

public:
	Output(); // Default constructor
	Output(int setTime, double setSpeed); // Constructor given time and speed

	void setTime(int setTime); // Sets time to specified value
	void setSpeed(double setSpeed); // Sets speed to specified value

	int returnTime(); // Returns the time
	double returnSpeed(); // Returns the speed
};

#endif