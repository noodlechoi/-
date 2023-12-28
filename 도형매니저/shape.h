//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// 이 클래스는 추상 클래스(abstract class)이다.
//-----------------------------------------------------------------------------
#pragma once

enum class eShape
{
	NONE,
	TRIANGLE,
	RECTANGLE,
	CIRCLE,
};

class Shape {
public:
	Shape() {};
	virtual ~Shape() {};

	virtual void draw() const = 0;			// pure virtual function
};
