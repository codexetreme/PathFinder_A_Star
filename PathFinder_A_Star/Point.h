#pragma once
#include<vector>
class Point
{
private:
	//map x to y axis anj y to x axis
	int x;
	int y;
	int positionInWorld;
	int G_n_cost;
	int H_n_cost;
	int traverseCost;
	int f_Cost;
	char displayChar;
public:
	Point *cameFrom;
	Point();
	Point(int i, int j);
	Point(int i, int j,int traverseCost);
	Point(const Point&);
	bool isInBounds(int rows, int columns);
	void setCosts(int H_n, int G_n);
	void setDisplayCharacter(char c);
	void set_positionInWorld(int pos);
	int get_positionInWorld() { return positionInWorld; }
	char getDisplayCharacter() { return displayChar; }
	int get_traverse_cost() { return traverseCost; }
	int get_G_n_cost() { return G_n_cost; }
	int get_F_n_cost() { return f_Cost; }
	int getX() { return x; }
	int getY() { return y; }
	bool operator==( const Point& p);
	bool operator<(const Point&p) const;
	~Point();
};

