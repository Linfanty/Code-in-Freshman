#include "Circle.h"

Circle::Circle()
{
	radius = 1;
}
//Construct a circle object
Circle::Circle(double newRadius)
{
	radius = newRadius;
}

//return
double Circle::getArea()
{
	return radius * radius *3.14159;
}
