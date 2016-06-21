#pragma once
#include<vector>
#include<list>
#include"Point.h"
class pathFinder
{

private:
	static std::vector<Point> openList;
	static std::vector<Point> closedList;
	static int Calulate_H_n_heuristic(Point currentPoint);
	enum list_type
	{
		open,
		closed
	};
	static bool findElement(Point p,list_type l_type);
	
	// manhattan seems good for now
public:
	pathFinder();
	static void solve(Point startPoint);
	~pathFinder();
};