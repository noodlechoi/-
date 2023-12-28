//-----------------------------------------------------------------------------
// �밢���� �ִ� �� 2���� �簢���� ������ �� �ִ�
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"
#include "point.h"

class Rectangle : public Shape {
	Point p1, p2;

public:
	Rectangle();
	Rectangle(const Point& a, const Point& b);
	Rectangle(const Rectangle& other);
	~Rectangle();

	virtual void draw() const override;
};

