#pragma once
#include<vector>
#include<unordered_map>
#include"Point.h"
class world
{
private:
	static std::vector<Point> _world;
	static int rows;
	static int columns;
	static Point goalPoint;
	static Point startPoint;
	static std::unordered_map<char, int>terrainTypes;

public:
	world();
	static void init(char* inputFile);
	static void display();
	static Point getElement(Point p);
	static int traversalCost(Point p1, Point p2);
	static std::vector<Point> neighbours(Point p);
	static void putElement(Point p);
	static int getRows() { return rows; }
	static int getColumns() { return columns; }
	static Point getGoalPoint() { return goalPoint; }
	static Point getStartPoint() { return startPoint; }
	~world();
};

