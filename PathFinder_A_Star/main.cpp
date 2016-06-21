#include<iostream>
#include"pathFinder.h"
#include"world.h"
#include "Point.h"
int main() {
	
	world::init("input.txt");
	Point p = world::getElement(Point(0, 5));
	std::cout << "Point is " << p.getX();
	/*pathFinder p;
	p.solve(world::getStartPoint());*/
	int x;
	std::cin >> x;
	return 0;
}