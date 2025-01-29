#pragma once
class Position
{
private:
	int x;
	int y;
public:
	Position(int x, int y) : x(x), y(y)
	{}

	int Distance(Position& other) const;
	void MoveTowards(Position& target);
	bool operator==(const Position& other) const;
	bool operator!=(const Position& other) const;
	void print() const;
};

