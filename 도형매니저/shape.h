//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// �� Ŭ������ �߻� Ŭ����(abstract class)�̴�.
//-----------------------------------------------------------------------------
#pragma once

enum class eShape : int
{
	NONE,
	TRIANGLE,
	RECTANGLE,
	CIRCLE,
};

class Shape {
protected:
	eShape shape;
public:
	Shape() : shape{ eShape::NONE } {};
	virtual ~Shape() {};

	virtual void draw() const = 0;			// pure virtual function
	eShape get() { return shape; };
};
