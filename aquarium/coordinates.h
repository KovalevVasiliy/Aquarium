#ifndef COORDINATES_H
#define COORDINATES_H
struct coordinates
{	coordinates(float first,float second,float third):first(first),second(second),third(third){}
	coordinates(){}
	float first;
	float second;
	float third;
	bool operator>=(const coordinates& rhs)
	{
		if (first >= rhs.first && second >= rhs.second
			&& third >= rhs.third)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const coordinates& rhs)
	{
		if (first <= rhs.first && second <= rhs.second
			&& third <= rhs.third)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	coordinates operator+(const float& rhs)
	{
		return coordinates(first + rhs, second + rhs, third + rhs);
	}
	coordinates operator-(const float& rhs)
	{
		return coordinates(first - rhs, second - rhs, third - rhs);
	}
	coordinates operator+(const coordinates& rhs)
	{
		return coordinates(first + rhs.first, second + rhs.second, third + rhs.third);
	}
	coordinates operator-(const coordinates& rhs)
	{
		return coordinates(first - rhs.first, second - rhs.second, third - rhs.third);
	}
};
#endif COORDINATES