#ifndef DATE_H
#define DATE_H

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

#include <iostream>

class Date
{
public:

	//cannonical class form
	Date(short int day = 1, short int month = 1, int year = 2000);
	Date(const Date& other);
	Date& operator=(const Date& other);
	~Date();

	//setters and getters
	void set_day(short int day);
	short int get_day() const;

	void set_month(short int month);
	short int get_month() const;

	void set_year(int year);
	int get_year() const;

	//a function to print date
	void printDate() const;

	//used for sort in containers
	bool operator<(Date& other) const;

private:
	short int _day;
	short int _month;
	int _year;

	//helper functions for printDate
	void printDay() const;
	void printMonth() const;

};

#endif