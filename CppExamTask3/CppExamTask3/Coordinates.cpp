#include <iostream>
#include <iomanip>
#include "Coordinates.h"

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

//initialising list used to make sure data is allocated in case incorrect parameters are given
Coordinates::Coordinates(float x, float y) :_x(0.00), _y(0.00)
{
	set_x(x);
	set_y(y);
}

Coordinates::Coordinates(const Coordinates& other)
{
	set_x(other._x);
	set_y(other._y);
}

Coordinates& Coordinates:: operator=(const Coordinates& other)
{
	if (this != &other)
	{
		set_x(other._x);
		set_y(other._y);
	}
	return *this;
}

Coordinates::~Coordinates()
{

}

void Coordinates::set_x(float x)
{
	this->_x = x;
}

float Coordinates::get_x() const
{
	return _x;
}

void Coordinates::set_y(float y)
{
	this->_y = y;
}

float Coordinates::get_y() const
{
	return _y;
}

//prints coordinates with 2 integers after decimal point
void Coordinates::printCoordinates() const
{
	std::cout << std::fixed<<std::setprecision(2)<<_x << ".x," << std::setprecision(2)<<_y << ".y" << std:: endl;
}