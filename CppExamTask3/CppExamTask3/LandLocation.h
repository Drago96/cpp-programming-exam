#ifndef LANDLOCATION_H
#define LANDLOCATION_H

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include "Mission.h"

enum locationType
{
	ground,
	floating
};

class LandLocation
{
public:

	//canonical class form
	//an empty vector for attempted landings will be given in case there is none as a parameter
	LandLocation(std::string locationName = " ", locationType landingLocationType = (locationType)0,       
		std::vector<std::shared_ptr<Mission>> attemptedLandings=std::vector<std::shared_ptr<Mission>>());  
	LandLocation(const LandLocation& other);
	LandLocation& operator=(const LandLocation& other);
	~LandLocation();

	//getters and setters
	void set_locationName(std::string locationName);
	std::string get_locationName() const;

	void set_landingLocationType(locationType landingLocationType);
	locationType get_landingLocationType() const;

	void set_attemptedLandings(std::vector<std::shared_ptr<Mission>> attemptedLandings);
	const std::vector<std::shared_ptr<Mission>>& get_attemptedLandings() const;

	const std::vector<std::shared_ptr<Mission>>& get_successfulLandings() const;

	int get_numberOfsuccessfulLandings() const;

	//functions

	//used to print info about a flight by given name
	void searchFlight(std::string name);
	//prints info about land location
	void printLandLocationType() const;
	//adds a new mission to container and sorts all missions
	void addFlight(std::shared_ptr<Mission> newMission);

private:
	std::string _locationName;
	locationType _landingLocationType;
	std::vector<std::shared_ptr<Mission>> _attemptedLandings;
	std::vector<std::shared_ptr<Mission>> _successfulLandings;
	int _numberOfSuccessfulLandings;

	//mutex for class functions
	std::mutex containerLock;
};

#endif