#include "LandLocation.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

//initialising list used to make sure data is allocated in case incorrect parameters are given
LandLocation::LandLocation(std::string locationName, locationType landingLocationType,std::vector<std::shared_ptr<Mission>> attemptedLandings):
   _locationName(" "), _landingLocationType((locationType)0), _numberOfSuccessfulLandings(0), _attemptedLandings(std::vector<std::shared_ptr<Mission>>())
{
	set_locationName(locationName);
	set_landingLocationType(landingLocationType);
	set_attemptedLandings(attemptedLandings);
	for (int i=0; i < _attemptedLandings.size();i++)
	{
		//searches through all attempted landings and adds those which are succesful to succesfullandings vector
		if (_attemptedLandings[i]->get_landingSuccess() == true)
		{
			_successfulLandings.push_back(_attemptedLandings[i]);
			_numberOfSuccessfulLandings++;
		}
	}
}

LandLocation::LandLocation(const LandLocation& other)
{
	set_locationName(other._locationName);
	set_landingLocationType(other._landingLocationType);
	set_attemptedLandings(other._attemptedLandings);
	for (int i = 0; i < other._attemptedLandings.size(); i++)
	{
		if (other._attemptedLandings[i]->get_landingSuccess() == true)
		{
			_successfulLandings.push_back(other._attemptedLandings[i]);
			_numberOfSuccessfulLandings++;
		}
	}
}

LandLocation& LandLocation::operator=(const LandLocation& other)
{
	if (this != &other)
	{
		set_locationName(other._locationName);
		set_landingLocationType(other._landingLocationType);
		set_attemptedLandings(other._attemptedLandings);
		for (int i = 0; i < other._attemptedLandings.size(); i++)
		{
			if (other._attemptedLandings[i]->get_landingSuccess() == true)
			{
				_successfulLandings.push_back(other._attemptedLandings[i]);
				_numberOfSuccessfulLandings++;
			}
		}
	}
	return* this;
}

LandLocation::~LandLocation()
{

}

void LandLocation::set_locationName(std::string locationName)
{
	this->_locationName = locationName;
}

std::string LandLocation::get_locationName() const
{
	return _locationName;
}

void LandLocation::set_landingLocationType(locationType landingLocationType)
{
	this->_landingLocationType = landingLocationType;
}

locationType LandLocation::get_landingLocationType() const
{
	return _landingLocationType;
}

void LandLocation::set_attemptedLandings(std::vector<std::shared_ptr<Mission>> attemptedLandings)
{
	this->_attemptedLandings = attemptedLandings;
}

const std::vector<std::shared_ptr<Mission>>& LandLocation::get_attemptedLandings() const
{
	return _attemptedLandings;
}

const std::vector<std::shared_ptr<Mission>>& LandLocation::get_successfulLandings() const
{
	return _successfulLandings;
}

int LandLocation::get_numberOfsuccessfulLandings() const
{
	return _numberOfSuccessfulLandings;
}

void LandLocation::printLandLocationType() const
{
	std::cout << "Landing location name: " << get_locationName() << std::endl;
	std::cout << "Landing location type: ";
	switch (get_landingLocationType())
	{
	case(0) : std::cout << "ground" << std::endl; break;
	case(1) : std::cout << "floating" << std::endl; break;
	default: break;
	}
}

void LandLocation::searchFlight(std::string name)
{
	containerLock.lock();
	std::for_each(get_attemptedLandings().begin(), get_attemptedLandings().end(), [&](std::shared_ptr<Mission> aMission)
	{
		if (aMission->get_missionName() == name)
		{
			this->printLandLocationType();
			aMission->printMissionInfo();
		}
	}
	);
	containerLock.unlock();
}

void LandLocation::addFlight(std::shared_ptr<Mission> newMission)
{
	containerLock.lock();
	_attemptedLandings.push_back(newMission);
	if (newMission->get_landingSuccess() == true)
	{
		_successfulLandings.push_back(newMission);
		_numberOfSuccessfulLandings++;
	}
	std::sort(_attemptedLandings.begin(), _attemptedLandings.begin() + _attemptedLandings.size());
	std::sort(_successfulLandings.begin(), _successfulLandings.begin() + _successfulLandings.size());
	containerLock.unlock();
}