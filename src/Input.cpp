//------------------------------------------------------------------------------------------------
//
// File: input.cpp
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the functions used in program input
//
//------------------------------------------------------------------------------------------------

#include "Input.h"

// Default input constructor
Input::Input() {
	this->inputFileName = NULL;
	return;
}

// Constructs Input given a specified filename
Input::Input(char* setInputFileName) {
	this->inputFileName = setInputFileName;
	return;
}

// Adds the input line to the graph
void Input::addPosition(double latitude, double longitude, unsigned long timeSeconds) {
	GpsPosition* newPos = new GpsPosition(latitude, longitude, timeSeconds);
	this->inputPositions.push_back(newPos);
	return;
}

// gets the input from the file and adds it to the graph
int Input::getInput() {
	string inputLine;

	inputFile.open(inputFileName); // Opens the file

	if (inputFile.is_open()) { // If open, get lines
		double currTime = 0.0; // current timestamp used to check if input is valid or not

		while (getline(inputFile, inputLine)) {
			string type, extra; // Temp input strings
			double timeIn = 0, latitude = 0, longitude = 0; // Temp values

			istringstream inputParse(inputLine); // Setup the file stream for input parsing
			getline(inputParse, type, ',');

			if (isGPGGA(type) == true) { // If correct type of data input
				cout.precision(15);
				string timeInString, latString, longString;
				int validLine = 1;

				getline(inputParse, timeInString, ','); // Parse time
				getline(inputParse, latString, ','); // Parse latitude
				getline(inputParse, extra, ','); // Parse direction, not used
				getline(inputParse, longString, ','); // Parse longitude

				if (checkIfDigits(timeInString) == false || checkIfDigits(latString) == false || checkIfDigits(longString) == false) { // If there is anything wrong with the input, disregard
					validLine = 0;
				}
				else {
					timeIn = stoi(timeInString); // Convert time string to int
					latitude = convDMS(stod(latString)); // Convert DMS latitude to DD
					longitude = convDMS(stod(longString)); // Convert DMS to DD
					timeIn = convTimeIn((int)timeIn); // Convert HHMMSS to seconds
				}
				
				if (timeIn == -1 || latitude > 180 || latitude < -180 || longitude > 180 || longitude < -180) { // If any weird values, discard
					validLine = 0;
				}

				if (timeIn <= currTime && validLine == 1) { // If new time <= old time, exit input
					return 2;
				}
				else if(validLine == 1) { // Else if valid, add input
					currTime = timeIn;
					addPosition(latitude, longitude, (unsigned long)timeIn); // Adds the position to the vector
				}

			}
			

		}
	}
	else {
		return 1; // Return error in filestream to exit program
	}

	return 0;
}

// Checks to see if the type is $GPGGA
bool Input::isGPGGA(string lineFirst) {
	string GPGGA = "$GPGGA";
	bool isGPGGA = true;

	if (lineFirst.compare(GPGGA) != 0) {
		isGPGGA = false;
	}

	return isGPGGA;
}

// Checks a string to see if it is digits only
bool Input::checkIfDigits(string input) {
	for (int i = 0; (unsigned)i < input.length(); i++) {
		if (!isdigit(input.at(i)) && input.at(i) != '.') {
			return false;
		}
	}
	return true;
}

// Converts DMS to the decimal degrees equivalent
double Input::convDMS(double DMS) {
	double returnDegrees = 0;
	double seperated, tempDMS;

	seperated = (int)DMS / 100; // Gets degrees
	returnDegrees = seperated;

	seperated = (int)DMS % 100; // Gets minutes
	returnDegrees = returnDegrees + (seperated / 60.0);

	seperated = 60.0 * modf(DMS, &tempDMS); // Conv decimal to seconds

	returnDegrees = returnDegrees + (seperated / 3600.0);

	return returnDegrees;
}

// Converts the input time to a time in seconds
double Input::convTimeIn(int timeIn) {

	double returnTime = 0;
	int twoDig, tempTime;

	twoDig = timeIn / 10000; // Extract hours
	if (twoDig < 0 || twoDig > 23) {
		return -1.0;
	}
	returnTime = returnTime + twoDig * 3600;

	tempTime = timeIn % 10000; // Extract min
	twoDig = tempTime / 100;
	if (twoDig < 0 || twoDig > 59) {
		return -1.0;
	}
	returnTime = returnTime + twoDig * 60;

	tempTime = tempTime % 100; // Extract seconds
	twoDig = tempTime; 
	if (twoDig < 0 || twoDig > 59) {
		return -1.0;
	}
	returnTime = returnTime + twoDig;

	return returnTime;
}

// Returns the vector of inputted positions
vector<GpsPosition*>& Input::returnInputPositions() {
	return this->inputPositions;
}

