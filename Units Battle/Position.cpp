#include "Position.h"
#include <cmath>
#include <iostream>

int Position::Distance(Position& other) const
{
	return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

void Position::MoveTowards(Position& target)
{
	if (x < target.x) {
		x++;
	}
	else if (x > target.x) {
		x--;
	}

	if (y < target.y) {
		y++;
	}
	else if (y > target.y) {
		y--;
	}
}

bool Position::operator==(const Position& other) const
{
	return x == other.x && y == other.y;
}

bool Position::operator!=(const Position& other) const
{
	return x != other.x || y != other.y;
}

void Position::print() const
{
	std::cout << "x, y (" << x << ", " << y << ")\n";
}

