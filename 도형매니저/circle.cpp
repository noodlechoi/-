#include "circle.h"
#include <iostream>

Circle::Circle() 
	: center(), rad(0.0)
{
	shape = eShape::CIRCLE;
	std::cout << "생정자" << std::endl;
}

// 복사생성자를 프로그램할 이유가 있다면 멤버변수의 값을 복사해야 한다.
// 복사생성자를 프로그램하면서 아무것도 하지 않으면 멤버변수는 복사되지 않는다.

Circle::Circle(const Point& c, double r)
	: center(c), rad(r)
{
	shape = eShape::CIRCLE;
	std::cout << "생정자 (const Point& c, double r)" << std::endl;
}

Circle::Circle(const Circle& other)
	: center(other.center), rad(other.rad)
{
	std::cout << "복사 생정자" << std::endl;
}

Circle::~Circle()
{
	std::cout << "소멸자" << std::endl;
}

void Circle::draw() const
{
	// 그림을 그리는 대신 문자로 정보를 출력한다
	std::cout << "원 - 중심점(" << center.x << "," << center.y
		<< ") 반지름 " << rad << '\n';
}
