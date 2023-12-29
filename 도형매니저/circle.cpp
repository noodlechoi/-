#include "circle.h"
#include <iostream>

Circle::Circle() 
	: center(), rad(0.0)
{
	shape = eShape::CIRCLE;
	std::cout << "������" << std::endl;
}

// ��������ڸ� ���α׷��� ������ �ִٸ� ��������� ���� �����ؾ� �Ѵ�.
// ��������ڸ� ���α׷��ϸ鼭 �ƹ��͵� ���� ������ ��������� ������� �ʴ´�.

Circle::Circle(const Point& c, double r)
	: center(c), rad(r)
{
	shape = eShape::CIRCLE;
	std::cout << "������ (const Point& c, double r)" << std::endl;
}

Circle::Circle(const Circle& other)
	: center(other.center), rad(other.rad)
{
	std::cout << "���� ������" << std::endl;
}

Circle::~Circle()
{
	std::cout << "�Ҹ���" << std::endl;
}

void Circle::draw() const
{
	// �׸��� �׸��� ��� ���ڷ� ������ ����Ѵ�
	std::cout << "�� - �߽���(" << center.x << "," << center.y
		<< ") ������ " << rad << '\n';
}
