#pragma once
class MazeVector
{
	MazeVector() = default;
	MazeVector(int y, int x) : y(y), x(x) {}

	MazeVector operator+(const MazeVector& other) const
	{
		Vector result;

		result.x = this->x + other.x;
		result.y = this->y + other.y;

		return result;
	}
	MazeVector operator-(const MazeVector& other) const
	{
		Vector result;

		result.x = this->x - other.x;
		result.y = this->y - other.y;

		return result;
	}
	MazeVector operator*(const float& value) const
	{
		return Vector(x * value, y * value);
	}

	int y; //row
	int x; //colmn
};

