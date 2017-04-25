//------------------------------------------------------------------------------------------------
//
// File: Execute.cpp
// Author: Coby Allred
// Date: 12/6/16
//
// Description: Defines the functions used the program's execution and output
//
//------------------------------------------------------------------------------------------------

#include "Execute.h"

// Default output class constructor
Execute::Execute() {
	this->outputFileName = NULL;
	this->isPopulated = false;
	return;
}

// Output class constructor given filename, rootuser and outputgraph
Execute::Execute(char* outputFileName, vector<GpsPosition*>* outputPositions) {
	this->outputFileName = outputFileName;
	this->outputPositions = outputPositions;
	this->isPopulated = true;
	return;
}

// Executes the main program functions to discover users and set inner degree of centrality
void Execute::findSpeeds(int isValid) {
	
	if (this->outputPositions->size() == 0 || isValid != 0) { // If no outputs, set invalid
		this->isPopulated = false;
		return;
	}

	for (int i = 0; (unsigned)i < this->outputPositions->size()-1; i++) { // Increment through positions to analyze
		int time = 0;
		double speed = 0.0, distanceKM = 0.0, deltaTime = 0.0;

		distanceKM = this->outputPositions->at(i)->CalcDistanceKmTo(*this->outputPositions->at(i+1)); // Find distance between the points
		time = this->outputPositions->at(i)->GetTime(); // Find the timestamp
		deltaTime = this->outputPositions->at(i+1)->GetTime() - time; // Find the change in time
		speed = (distanceKM / deltaTime) * 3600.0; // Find the speed, *3600 for km/s to km/h

		for (int t = 0; t < deltaTime; t++) { // Add dektaT outputs to pad when no update is present 
			Output* newOutput = new Output(time + t + 1, speed); 
			this->printOutputs.push_back(newOutput); // Add the new output
		}

	}

	return;
}

// Creates the output text file for the program
bool Execute::printOutput() {

	outputFile.open(outputFileName); // Open the output file

	if (outputFile.is_open()) { // If opened correctly

		if (this->isPopulated == false) { // If there is no data, open and close
			outputFile.close();
			return true;
		}
		
		for (int i = 0; (unsigned)i < this->printOutputs.size(); i++) { // Increment through list and print the output timestamp + speed
			outputFile << this->printOutputs.at(i)->returnTime() << " " << this->printOutputs.at(i)->returnSpeed() << endl;
		}

		outputFile.close(); // Close output file

	}
	else { // If outputFile is not good, print error
		return false;
	}

	return true;
	
}


