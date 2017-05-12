#include <iostream>
#include "Time.h"

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

//initialising list used to make sure data is allocated incase incorrect parameters are given
Time::Time(int years, short int months, short int days) :_years(0), _months(0), _days(0)
{
	set_years(years);
	set_months(months);
	set_days(days);
	convertDaysToMonths();
	convertMonthsToYears();
}

Time::Time(const Time& other)
{
	set_years(other._years);
	set_months(other._months);
	set_days(other._days);
}

Time& Time::operator=(const Time& other)
{
	if (this != &other)
	{
		set_years(other._years);
		set_months(other._months);
		set_days(other._days);
	}
	return *this;
}

Time::~Time()
{

}

void Time::set_years(int years)
{
	if (years >= 0)
	{
		this->_years = years; 
	}
}

int Time::get_years() const
{
	return _years;
}

void Time::set_months(short int months)
{
	if (months >= 0)
	{
		this->_months = months;
	}
}

short int Time::get_months() const
{
	return _months;
}

void Time::set_days(short int days)
{
	if (days >= 0)
	{
		this->_days = days;
	}
}

short int Time::get_days() const
{
	return _days;
}


//if days are more than 31 converts to months
void Time::convertDaysToMonths()
{
	while (_days >= 31)
	{
		_days -= 31;
		_months += 1;
	}
}


//if months are more than 12 converts to years
void Time::convertMonthsToYears()
{
	while (_months >= 12)
	{
		_months -= 12;
		_years += 1;
	}
}

void Time::printTime() const
{
	std::cout << _years << " years, " << _months << " months, " << _days << " days." << std::endl;
}

