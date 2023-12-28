#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle()
	: p1(), p2()
{
	std::cout << "생정자" << std::endl;
}

Rectangle::Rectangle(const Point& a, const Point& b)
	: p1(a), p2(b)
{
	std::cout << "생정자 (const Point& a, const Point& b)" << std::endl;
}

Rectangle::Rectangle(const Rectangle& other)
	: p1(other.p1), p2(other.p2)
{
	std::cout << "복사 생정자" << std::endl;
}

Rectangle::~Rectangle()
{
	std::cout << "소멸자" << std::endl;
}

void Rectangle::draw() const
{
	std::cout << "사각형 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << '\n';
}
