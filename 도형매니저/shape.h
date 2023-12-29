//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// 이 클래스는 추상 클래스(abstract class)이다.
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
