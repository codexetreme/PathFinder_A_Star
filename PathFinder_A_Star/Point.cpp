#include "Point.h"
#include "world.h"


Point::Point() {


}

Point::Point(int i, int j)
{
	this->x = i;
	this->y = j;

}

Point::Point(int i, int j, int _traverseCost)
{
	this->x = i;
	this->y = j;
	this->traverseCost = _traverseCost;
}

Point::
Point(const Point & p)
{
	displayChar = p.displayChar;
	x = p.x;
	y = p.y;
	G_n_cost = p.G_n_cost;
	H_n_cost = p.H_n_cost;
	traverseCost = p.traverseCost;
	f_Cost = p.f_Cost;
	positionInWorld = p.positionInWorld;
	cameFrom = p.cameFrom;
}



bool Point ::isInBounds(int rows, int columns)
{
	if (x<0 || x>=rows || y<0 || y>=columns)
		return false;
	return true;
}


void Point::setCosts(int H_n, int G_n)
{
	H_n_cost = H_n;
	
	G_n_cost =  G_n ;

	f_Cost = H_n_cost + G_n_cost;
}

void Point::setDisplayCharacter(char c)
{
	displayChar = c;
}

void Point::set_positionInWorld(int pos)
{
	positionInWorld = pos;
}


bool Point::operator==(const Point & p)
{
	if (x == p.x && y == p.y) {
		return true;
	}
	return false;
}


bool Point::operator<(const Point & p) const
{
	if(this->positionInWorld<p.positionInWorld)
		return true;
	return false;
}

Point::~Point()
{
}
