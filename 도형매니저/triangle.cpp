#include "triangle.h"
#include <iostream>

Triangle::Triangle()
	: p1(), p2(), p3()
{
	shape = eShape::TRIANGLE;

	std::cout << "������" << std::endl;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: p1(a), p2(b), p3(c)
{
	shape = eShape::TRIANGLE;

	std::cout << "������ (const Point& a, const Point& b, const Point& c)" << std::endl;
}

Triangle::Triangle(const Triangle& other)
	: p1(other.p1), p2(other.p2), p3(other.p3)
{
	std::cout << "���� ������" << std::endl;
}

Triangle::~Triangle()
{
	std::cout << "�Ҹ���" << std::endl;
}

void Triangle::draw() const
{
	std::cout << "�ﰢ�� - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << "), ("
		<< p3.x << "," << p3.y << ")" << '\n';
}
