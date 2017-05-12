#include "Mission.h"
#include <string>

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */


//initialising list used to make sure data is allocated incase incorrect parameters are given
Mission::Mission(std::string missionName, std::string rocketName, Date takeOffDate, Date landingDate, double payloadKg,
	Time flightTime, bool landingSuccess, Coordinates landingCoordinates) :_missionName(" "), _rocketName(" "), _takeOffDate(Date(1, 1, 2000)),
	_landingDate(Date(1, 1, 2000)), _payloadKg(0), _flightTime(Time(0, 0, 0)), _landingSuccess(false), _landingCoordinates(Coordinates(0, 0))
{
	set_missionName(missionName);
	set_rocketName(rocketName);
	set_takeOffDate(takeOffDate);
	set_landingDate(landingDate);
	set_payloadKg(payloadKg);
	set_flightTime(flightTime);
	set_landingSuccess(landingSuccess);
	set_landingCoordinates(landingCoordinates);
}

Mission::Mission(const Mission& other)
{
	set_missionName(other._missionName);
	set_rocketName(other._rocketName);
	set_takeOffDate(other._takeOffDate);
	set_landingDate(other._landingDate);
	set_payloadKg(other._payloadKg);
	set_flightTime(other._flightTime);
	set_landingSuccess(other._landingSuccess);
	set_landingCoordinates(other._landingCoordinates);
}

Mission& Mission::operator=(const Mission& other)
{
	if (this != &other)
	{
		set_missionName(other._missionName);
		set_rocketName(other._rocketName);
		set_takeOffDate(other._takeOffDate);
		set_landingDate(other._landingDate);
		set_payloadKg(other._payloadKg);
		set_flightTime(other._flightTime);
		set_landingSuccess(other._landingSuccess);
		set_landingCoordinates(other._landingCoordinates);
	}
	return *this;
}

Mission::~Mission()
{

}

void Mission::set_missionName(std::string missionName)
{
	this->_missionName = missionName;
}

std::string Mission::get_missionName() const
{
	return _missionName;
}

void Mission::set_rocketName(std::string rocketName)
{
	this->_rocketName = rocketName;
}

std::string Mission::get_rocketName() const
{
	return _rocketName;
}

void Mission::set_takeOffDate(Date takeOffDate)
{
	this->_takeOffDate = takeOffDate;
}

Date Mission::get_takeOffDate() const
{
	return _takeOffDate;
}

void Mission::set_landingDate(Date landingDate)
{
	this->_landingDate = landingDate;
}

Date Mission::get_landingDate() const
{
	return _landingDate;
}

void Mission::set_payloadKg(double payloadKg)
{
	if (payloadKg >= 0)
	{
		this->_payloadKg = payloadKg;
	}
}

double Mission::get_payloadKg() const
{
	return _payloadKg;
}

void Mission::set_flightTime(Time flightTime)
{
	this->_flightTime = flightTime;
}

Time Mission::get_flightTime() const
{
	return _flightTime;
}

void Mission::set_landingSuccess(bool landingSuccess)
{
	this->_landingSuccess = landingSuccess;
}

bool Mission::get_landingSuccess() const
{
	return _landingSuccess;
}

void Mission::set_landingCoordinates(Coordinates landingCoordinates)
{
	this->_landingCoordinates = landingCoordinates;
}

Coordinates Mission::get_landingCoordinates() const
{
	return _landingCoordinates;
}

void Mission::convertPayloadToPounds() const
{
	std::cout << _payloadKg*2.204622 << " pounds" << std::endl;
}

void Mission::printMissionInfo() const
{
	std::cout << "Mission name: " << get_missionName() << std::endl;
	std::cout << "Rocket name: " << get_rocketName() << std::endl;
	std::cout << "Take off date: "; get_takeOffDate().printDate();
	std::cout << "Landing date: "; get_landingDate().printDate();
	std::cout << "Payload in kg: " << get_payloadKg() << std::endl;
	std::cout << "Flight time: "; get_flightTime().printTime();
	if (get_landingSuccess() == true)
	{
		std::cout << "Landing successful!" << std::endl;
	}
	else
	{
		std::cout << "Landing failed!" << std::endl;
	}
	std::cout << "Landing coordinates: "; get_landingCoordinates().printCoordinates();
	std::cout << std::endl;
}

bool Mission:: operator<(Mission& other) const
{
	if (this->get_takeOffDate() < other.get_takeOffDate()) return true;
	return false;
}