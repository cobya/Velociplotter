//------------------------------------------------------------------------------------------------
//
// File: Output.cpp
// Author: Coby Allred
// Date: 12/6/16
//
// Description: Defines the functions used in the output class
//
//------------------------------------------------------------------------------------------------

#include "Output.h"

// Default Output class constructor
Output::Output() {
	this->time = -1;
	this->speed = -1;
	return;
}

// Output class constructor given a time and speed to set
Output::Output(int setTime, double setSpeed) {
	this->time = setTime;
	this->speed = setSpeed;
	return;
}

// Sets the time to a specified value
void Output::setTime(int setTime) {
	this->time = setTime;
	return;
}

// Sets the speed to a specified value
void Output::setSpeed(double setSpeed) {
	this->speed = setSpeed;
	return;
}

// Returns the time
int Output::returnTime() {
	return this->time;
}

// Returns the speed
double Output::returnSpeed() {
	return this->speed;
}