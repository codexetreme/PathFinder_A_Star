#include "Point.h"
#include "world.h"


Point::Point() {


}

Point::Point(int i, int j)
{
	this->x = i;
	this->y = j;

}

Point::Point(int i, int j, int traverseCost)
{
	this->x = i;
	this->y = j;
	this->traverseCost = traverseCost;
}



bool Point ::isInBounds(int rows, int columns)
{
	if (x<0 || x>rows || y<0 || y>columns)
		return false;
	else return true;
}

std::vector<Point> Point::getNeighbours()
{
	std::vector<Point> neighbours;
	if (Point(x - 1, y).isInBounds(world::getRows(), world::getColumns()))
		neighbours.push_back(Point(x - 1, y));
	if (Point(x, y - 1).isInBounds(world::getRows(), world::getColumns()))
		neighbours.push_back(Point(x, y - 1));
	if (Point(x, y + 1).isInBounds(world::getRows(), world::getColumns()))
		neighbours.push_back(Point(x, y + 1));
	if (Point(x + 1, y).isInBounds(world::getRows(), world::getColumns()))
		neighbours.push_back(Point(x + 1, y));

	return neighbours;
}

void Point::setCosts(int H_n, int G_n)
{
	H_n_cost = H_n;
	
	G_n_cost = cameFrom != NULL ? G_n : 0;

	f_Cost = H_n_cost + G_n_cost;
}

void Point::setDisplayCharacter(char c)
{
	displayChar = c;
}


bool Point::operator==(const Point & p)
{
	if (x == p.x && y == p.y) {
		return true;
	}
	return false;
}

Point::~Point()
{
}
