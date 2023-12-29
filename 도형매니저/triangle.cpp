#include "triangle.h"
#include <iostream>

Triangle::Triangle()
	: p1(), p2(), p3()
{
	shape = eShape::TRIANGLE;

	std::cout << "생정자" << std::endl;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: p1(a), p2(b), p3(c)
{
	shape = eShape::TRIANGLE;

	std::cout << "생정자 (const Point& a, const Point& b, const Point& c)" << std::endl;
}

Triangle::Triangle(const Triangle& other)
	: p1(other.p1), p2(other.p2), p3(other.p3)
{
	std::cout << "복사 생정자" << std::endl;
}

Triangle::~Triangle()
{
	std::cout << "소멸자" << std::endl;
}

void Triangle::draw() const
{
	std::cout << "삼각형 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << "), ("
		<< p3.x << "," << p3.y << ")" << '\n';
}
