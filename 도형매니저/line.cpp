#include "line.h"

Line::Line() : p1(), p2()
{
	shape = eShape::LINE;
	std::cout << "생정자" << std::endl;
}

Line::Line(const Point& a, const Point& b) : p1(a), p2(b)
{
	shape = eShape::LINE;
	std::cout << "생정자 (const Point& a, const Point& b)" << std::endl;
}

Line::Line(const Line& other) : p1(other.p1), p2(other.p2)
{
	std::cout << "복사 생정자" << std::endl;
}

Line::~Line()
{
	std::cout << "소멸자" << std::endl;
}

void Line::draw() const
{
	std::cout << "선분 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << '\n';
}

void Line::save(std::ofstream& f)
{
	f << static_cast<int>(shape) << " ";
	f << p1.x << " " << p1.y << " ";
	f << p2.x << " " << p2.y << "\n";
}
