#ifndef MISSION_H
#define MISSION_H

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

#include<iostream>
#include "Date.h"
#include "Time.h"
#include "Coordinates.h"

class Mission
{
	//cannonical class form
public:
	Mission(std::string missionName=" ", std::string rocketName=" ", Date takeOffDate=Date(1,1,2000), Date landingDate=Date(1,1,2000), double payloadKg=0,
		Time flightTime=Time(0,0,0), bool landingSuccess=false, Coordinates landingCoordinates=Coordinates(0,0));
	Mission(const Mission& other);
	Mission& operator=(const Mission& other);
	~Mission();

	//getters and setters
	void set_missionName(std::string missionName);
	std::string get_missionName() const;

	void set_rocketName(std::string rocketName);
	std::string get_rocketName() const;

	void set_takeOffDate(Date takeOffDate);
	Date get_takeOffDate() const;

	void set_landingDate(Date landingDate);
	Date get_landingDate() const;

	void set_payloadKg(double payloadKg);
	double get_payloadKg() const;

	void set_flightTime(Time flightTime);
	Time get_flightTime() const;

	void set_landingSuccess(bool landingSuccess);
	bool get_landingSuccess() const;

	void set_landingCoordinates(Coordinates landingCoordinates);
	Coordinates get_landingCoordinates() const;

	//functions
	void printMissionInfo() const;
	void convertPayloadToPounds() const;
	//compares two missions by take off time
	bool operator<(Mission& other) const;
private:
	std::string _missionName;
	std::string _rocketName;
	Date _takeOffDate;
	Date _landingDate;
	double _payloadKg;
	Time _flightTime;
	bool _landingSuccess;
	Coordinates _landingCoordinates;
};


#endif