#include<iostream>
#include"pathFinder.h"
#include"world.h"
#include "Point.h"
int main() {
	
	world::init("input.txt");
	auto p = world::getElement(Point(3,4));
	p.setDisplayCharacter('&');
	world::putElement(p);
	world::display();
	pathFinder::solve(world::getStartPoint());
	std::cout << "\n\n";
	world::display();
	int x;
	std::cin >> x;
	return 0;
}