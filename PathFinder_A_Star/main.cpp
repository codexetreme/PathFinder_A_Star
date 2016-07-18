#include<iostream>
#include"pathFinder.h"
#include"world.h"
#include "Point.h"
int main() {
	
	world::init("input.txt");
	pathFinder::solve(world::getStartPoint());
	std::cout << "\n\n";
	world::display();
	int x;
	std::cin >> x;
	return 0;
}
