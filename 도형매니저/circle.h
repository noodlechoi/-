//-----------------------------------------------------------------------------
// �߽����� ��ǥ�� ���������� ���� ������ �� �ִ�.
// (�ٸ� ������� ���� ������ ���� �ִ�)
//-----------------------------------------------------------------------------
#pragma once

#include "point.h"
#include "shape.h"

// ��������� ���� �� include ��ſ� ������ ���� ���漱��(forward declaration)�� �� ���� �ִ�
// struct Point;
// class Shape;

class Circle : public Shape {
	Point center;							// �߽����� ��ǥ
	double rad;								// ������

public:
	Circle();
	Circle(const Point& c, double r);
	Circle(const Circle& other);			// ���� ���縦 �� �ʿ䰡 ���ٸ� ���α׷��Ӱ� ��������ڸ�
											// ���α׷��� �ʿ�� ����.
											// ���� � ������ ���α׷��ؾ� �Ѵٸ� �޸𸮸� �����ϰ�
											// �ڵ��ؾ� �Ѵ�

	// �� ������ ���� �ٰ� ���� �����Ͽ� ��ü�� �� �ִ�
	// Circle(const Circle&) = default;
	~Circle();								// �Ҹ��ڸ� ���α׷��� �ʿ䰡 ���ٴ� ���� ������ ����

	virtual void draw() const override;
};

