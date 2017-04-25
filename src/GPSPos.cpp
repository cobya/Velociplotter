//------------------------------------------------------------------------------------------------
//
// File: GPSPos.cpp
// Author: Coby Allred
// Date: 12/6/16
//
// Description: Defines the functions used in the GpsPosition class
//
//------------------------------------------------------------------------------------------------

#include"GPSPos.h"
#include<cmath>

// Default class constructor
GpsPosition::GpsPosition() {
	this->latitude = 0;
	this->longitude = 0;
	this->timeSeconds = 0;
	return;
}

// Class constructor using specified lat, long, and time
GpsPosition::GpsPosition(double setLatitude, double setLongitude, unsigned long timeSeconds) {
	this->latitude = setLatitude;
	this->longitude = setLongitude;
	this->timeSeconds = timeSeconds;
	return;
}

// Returns the latitude
double GpsPosition::GetLatitude() {
	return this->latitude;
}

// Returns the longitude
double GpsPosition::GetLongitude() {
	return this->longitude;
}

// Returns the time
unsigned long GpsPosition::GetTime() {
	return this->timeSeconds;
}

// Sets the latitude to a new value
void GpsPosition::SetLatitude(double setLatitude) {
	this->latitude = setLatitude;
	return;
}

// Sets the longitude to a new value
void GpsPosition::SetLongitude(double setLongitude) {
	this->longitude = setLongitude;
	return;
}

// Sets the time to a new value
void GpsPosition::SetTime(unsigned long setTimeSeconds) {
	this->timeSeconds = setTimeSeconds;
	return;
}

// Calculates a distance to KM from the latitude and longitude coordinates
double GpsPosition::CalcDistanceKmTo(GpsPosition toPosition) {
	const double EarthRadiusKm = 6371.0; 
	const double PI = 3.14159265358979323846; 
	
	double fromLatitudeRad, fromLongitudeRad, toLatitudeRad, toLongitudeRad, deltaLatitude, deltaLongitude; 
	double a, c;

	// Convert to radians
	fromLatitudeRad = PI * this->GetLatitude() / 180.0; 
	fromLongitudeRad = PI * this->GetLongitude() / 180.0; 
	toLatitudeRad = PI * toPosition.GetLatitude() / 180.0; 
	toLongitudeRad = PI * toPosition.GetLongitude() / 180.0;
	
	// Calculate delta for latituce and longitude
	deltaLatitude = toLatitudeRad - fromLatitudeRad;
	deltaLongitude = toLongitudeRad - fromLongitudeRad;
	
	// Calculate great-circle distance using haversine formula
	a = ( sin(deltaLatitude / 2) * sin(deltaLatitude / 2) ) +( sin(deltaLongitude / 2) * sin(deltaLongitude / 2) *cos(fromLatitudeRad) * cos(toLatitudeRad) );
	c = 2 * atan2(sqrt(a), sqrt(1-a));
	
	return EarthRadiusKm * c;
}