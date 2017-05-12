#ifndef COORDINATES_H
#define COORDINATES_H

/*Name: Dragomir Lyubomirov Proychev
SoftUni Account: DragomirProychev */

#include <iostream>

class Coordinates
{
public:
	//cannonical class form
	Coordinates(float x=0.00,float y=0.00);
	Coordinates(const Coordinates& other);
	Coordinates& operator=(const Coordinates& other);
	~Coordinates();

	//getters and setters
	void set_x(float x);
	float get_x() const;

	void set_y(float y);
	float get_y() const;

	//function to print coordinates
	void printCoordinates() const;

private:
	float _x;
	float _y;
};

#endif