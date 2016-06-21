#include "pathFinder.h"
#include "world.h"
#include "Point.h"
#include<algorithm>


std::vector<Point> pathFinder::openList;
std::vector<Point> pathFinder::closedList;

pathFinder::pathFinder()
{
}
/* 

	g: -> cost from start 
	h: -> heuristic cost to end from current
*/


void pathFinder::solve(Point startpoint)
{
	startpoint.cameFrom = NULL;
	startpoint.setCosts(0, 0);
	openList.push_back(startpoint);
	
	while (!openList.empty())
	{
		// find element with minimum fCost
		Point point = *std::min_element(openList.begin(), openList.end(), [](Point p1, Point p2) {
			return p1.get_F_n_cost() < p2.get_F_n_cost() ? true : false;
		});
		
		if (world::getElement(point) == world::getGoalPoint()) {
			break;
		}

		// TODO: call the path construction

		std::vector<Point> neighbouringPoints = point.getNeighbours();
		
		for (Point neighbour: neighbouringPoints)
		{
			
			neighbour.cameFrom = &point;
			// this cost will be added later, first determine which point is nearer 
			int tentativeCost = point.get_G_n_cost() + world::traversalCost(neighbour,point);
			//neighbour.setCosts(h, g);

			if (findElement(neighbour, list_type::open)) {
				// element is found, check for a better cost
				if (tentativeCost < neighbour.get_G_n_cost()) {
					int h = Calulate_H_n_heuristic(neighbour);
					neighbour.setCosts(h, tentativeCost);
				}
			}
			else {
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
		/*auto iter = std::find(openList.begin(), openList.end(), p);
		if (iter == openList.end())
			return false;*/
	}
	else if(t == list_type::closed)
	{
		/*auto iter = std::find(closedList.begin(), closedList.end(), p);
		if (iter == closedList.end())
			return false;*/
	}
	return true;
}

pathFinder::~pathFinder()
{
}
