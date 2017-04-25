//------------------------------------------------------------------------------------------------
//
// File: GPSPos.h
// Author: Coby Allred
// Date: 12/6/16
//
// Description: Defines the GPS position class and its funtion prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef GPSPOS_H
#define GPSPOS_H

class GpsPosition{ 
private:
	double latitude; // Latitude of location
	double longitude; // Longitude of location
	unsigned long timeSeconds; // The timestamp in seconds

public:
	GpsPosition(); // Default constructor
	GpsPosition(double latitude, double longitude, unsigned long timeSeconds); // Constructor given lat, long, and seconds
	
	double GetLatitude(); // Returns latitude
	double GetLongitude(); // Returns longitude
	unsigned long GetTime(); // Returns time
	
	void SetLatitude(double latitude);  // Sets latitude
	void SetLongitude(double longitude);  // Sets longitude
	void SetTime(unsigned long timeSeconds);  // Sets the timeSeconds
	
	double CalcDistanceKmTo(GpsPosition toPosition);  // Calculates the distance between two points

};

#endif