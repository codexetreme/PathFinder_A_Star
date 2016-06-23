#include "pathFinder.h"
#include "world.h"
#include "Point.h"
#include<algorithm>
#include<iostream>
#include<map>

std::vector<Point> pathFinder::openList;
std::vector<Point> pathFinder::closedList;

pathFinder::pathFinder()
{
}

/*
	g: -> cost from start 
	h: -> heuristic cost to end from current
*/

std::map<Point, Point> CameFrom;

void pathFinder::solve(Point startpoint)
{
	CameFrom.insert(std::pair<Point, Point>(startpoint, Point(-1,-1)));
	startpoint.setCosts( Calulate_H_n_heuristic(startpoint),0);
	openList.push_back(startpoint);
	
	while (!openList.empty())
	{
		// find element with minimum fCost
		auto point_iter = std::min_element(openList.begin(), openList.end(), [](Point p1, Point p2) {
			return p1.get_F_n_cost() < p2.get_F_n_cost() ? true : false;
		});
		Point point = *point_iter;
		if (world::getElement(point) == world::getGoalPoint()) {
			constructPath(point);
			std::cout << "End is reached";
			break;
		}
//		world::putElement(point);
		openList.erase(point_iter);
		closedList.push_back(point);
		// TODO: call the path construction
		
		std::vector<Point> neighbouringPoints = world::neighbours(point);
		
		for (Point neighbour: neighbouringPoints)
		{
			if (findElement(neighbour, list_type::closed)) {
				continue;
			}

			// this cost will be added later, first determine which point is nearer 
			int tentativeCost = point.get_G_n_cost() + neighbour.get_traverse_cost();

			if (findElement(neighbour, list_type::open)) {
				// element is found, check for a better cost
				if (tentativeCost < neighbour.get_G_n_cost()) {
					int h = Calulate_H_n_heuristic(neighbour);
					neighbour.setCosts(h, tentativeCost);
					//closedList.push_back(neighbour);
				}
			}
			else {
				CameFrom.insert(std::pair<Point,Point>(neighbour,point));
				neighbour.setCosts(Calulate_H_n_heuristic(neighbour), tentativeCost);
				openList.push_back(neighbour);
			}
		}
	}
}


int pathFinder::Calulate_H_n_heuristic(Point currentPoint)
{
	int dx = abs(currentPoint.getX() - world::getGoalPoint().getX());
	int dy = abs(currentPoint.getY() - world::getGoalPoint().getY());
	return 1 * (dx + dy);
}

bool pathFinder::findElement(Point p, list_type t)
{
	if (t == list_type::open) {
		auto iter = std::find(openList.begin(), openList.end(), p);
		if (iter == openList.end())
			return false;
	}
	else if(t == list_type::closed)
	{
		auto iter = std::find(closedList.begin(), closedList.end(), p);
		if (iter == closedList.end())
			return false;
	}
	return true;
}

std::pair<bool,std::map<Point,Point>::iterator> searchKeys(Point currentPoint) {
	for (auto iter = CameFrom.begin(); iter != CameFrom.end(); iter++) {
		if (currentPoint == iter->first) {
			return std::pair<bool, std::map<Point, Point>::iterator >(true, iter);
		}
	}
	return std::pair<bool, std::map<Point,Point>::iterator>(false,CameFrom.end());
}

void pathFinder::constructPath(Point& currentPoint)
{
	std::vector<Point> path;
	
	while (searchKeys(currentPoint).first==true) {
		currentPoint = searchKeys(currentPoint).second->second;
		path.push_back(currentPoint);

	}
	for (Point p : path) {
		p.setDisplayCharacter('*');
		world::putElement(p);
		std::cout << p.getX() << " " << p.getY() << "\n";
	}
}

pathFinder::~pathFinder()
{
}
