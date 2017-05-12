#include <iostream>
#include "Date.h"

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

//initialising list used to make sure data is allocated in case incorrect parameters are given
Date::Date(short int day, short int month, int year) :_day(1), _month(1), _year(2000)
{
	set_day(day);
	set_month(month);
	set_year(year);
}

Date::Date(const Date& other)
{
	set_day(other._day);
	set_month(other._month);
	set_year(other._year);
}

Date& Date:: operator=(const Date& other)
{
	if (this != &other)
	{
		set_day(other._day);
		set_month(other._month);
		set_year(other._year);
	}
	return *this;
}

Date::~Date()
{

}

void Date::set_day(short int day)
{
	if (day >= 1 && day <= 31)
	{
		this->_day = day;
	}
}

short int Date::get_day() const
{
	return _day;
}

void Date::set_month(short int month)
{
	if (month >= 1 && month <= 12)
	{
		this->_month = month;
	}
}

short int Date::get_month() const
{
	return _month;
}

void Date::set_year(int year)
{
	if (year >= 1)
	{
		this->_year = year;
	}
}

int Date::get_year() const
{
	return _year;
}

void Date::printDay() const
{
	if (_day >= 1 && _day <= 9)
	{
		//adds a 0 when printing  day if between 1 and 9
		std::cout << "0" << _day << ".";
	}
	else
	{
		std::cout << _day << ".";
	}
}

void Date::printMonth() const
{
	if (_month >= 1 && _month <= 9)
	{
		//adds a 0 when printing month if between 1 and 9
		std::cout << "0" << _month << ".";
	}
	else
	{
		std::cout << _month << ".";
	}
}

void Date::printDate() const
{
	printDay();
	printMonth();
	std::cout << get_year() << std::endl;
}

bool Date::operator<(Date& other) const
{
	if (this->get_year() <= other.get_year()) return true;
	else if (this->get_month() <= other.get_month()) return true;
	else if (this->get_day() <= other.get_day()) return true;
	return false;
}