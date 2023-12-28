//-----------------------------------------------------------------------------
// �� ������ �ﰢ���� ������ �� �ִ�
//-----------------------------------------------------------------------------
#pragma once

#include "point.h"								// Point�� Triangle���� ���
#include "shape.h"								// Shape�� ��� ����

class Triangle : public Shape {
	Point p1, p2, p3;

public:
	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& other);
	~Triangle();

	virtual void draw() const override;			// virtual function�� overriding
};

