#include "world.h"
#include<fstream>
#include<iostream>
#include<unordered_map>


int world::columns;
int world::rows;
std::vector<Point> world::_world;
Point world::goalPoint;
Point world::startPoint;
std::unordered_map<char, int> world::terrainTypes;

world::world()
{
}

void world::init(char* inputFile)
{
	int n;
	char ele;
	int cost;
	std::ifstream inputStream(inputFile, std::ios::in);
	if (inputStream.is_open()) {
		// gets the total terrains in the map
		inputStream >> n;
		for (int i=0; i< n; i++)
		{
			inputStream >> ele >> cost;
			terrainTypes.insert(std::make_pair(ele,cost));
		}
		//------------------------------------//
		
		// reads the world
		inputStream >> rows>>columns;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				inputStream >> ele;
				if (ele == 's') {
					startPoint = Point(i, j, 1);
					startPoint.setDisplayCharacter(ele);
					startPoint.set_positionInWorld(_world.size());
					_world.push_back(startPoint);
				}
				else if (ele == 'g') {
					goalPoint = Point(i, j, 1);
					goalPoint.setDisplayCharacter(ele);
					goalPoint.set_positionInWorld(_world.size());
					_world.push_back(goalPoint);
				}
				else
				{
					Point tempPoint(i, j, terrainTypes.at(ele));
					tempPoint.setDisplayCharacter(ele);
					tempPoint.set_positionInWorld(_world.size());
					_world.push_back(tempPoint);

				}
			}
		}
		inputStream.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
}

void world::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Point p(i, j);
			std::cout << getElement(p).getDisplayCharacter();
		}
		std::cout << "\n";
	}
}


Point world::getElement(Point p)
{
	return _world.at(p.getX()*rows + p.getY());
}

void world::putElement(Point p)
{
	auto iter = std::find(_world.begin(), _world.end(), p);
	if (iter != _world.end()) {
		_world.at(p.getX()*rows + p.getY()) = p;
	}
}



int world::traversalCost(Point p1, Point p2)
{
	return 1 * p2.get_traverse_cost();
}

std::vector<Point> world::neighbours(Point p)
{
	std::vector<Point> tempNeighbours;
	if (Point(p.getX(), p.getY()-1).isInBounds(world::rows, world::columns)) {
		tempNeighbours.push_back(getElement(Point(p.getX(), p.getY()-1)));
	}
	if (Point(p.getX() - 1, p.getY()).isInBounds(world::rows, world::columns)) {
		tempNeighbours.push_back(getElement(Point(p.getX()-1,p.getY())));
	}
	if (Point(p.getX() + 1, p.getY()).isInBounds(world::rows, world::columns)) {
		tempNeighbours.push_back(getElement(Point(p.getX() + 1, p.getY())));
	}
	if (Point(p.getX(), p.getY()+1).isInBounds(world::rows, world::columns)) {
		tempNeighbours.push_back(getElement(Point(p.getX(), p.getY()+1)));
	}
	return tempNeighbours;
}



world::~world()
{
}
