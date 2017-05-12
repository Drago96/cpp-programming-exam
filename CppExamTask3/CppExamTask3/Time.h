#ifndef TIME_H
#define TIME_H

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

#include <iostream>

class Time
{
public:

	//cannonical class form
	Time(int years = 0, short int months = 0, short int days = 0);
	Time(const Time& other);
	Time& operator=(const Time& other);
	~Time();

	//getters and setters
	void set_years(int years);
	int get_years() const;

	void set_months(short int months);
	short int get_months() const;

	void set_days(short int days);
	short int get_days() const;

	//print function
	void printTime() const;

	

private:
	int _years;
	short int _months;
	short int _days;

	// converts months and days appropriately during object construction
	void convertMonthsToYears();
	void convertDaysToMonths();
};

#endif