//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// �� Ŭ������ �߻� Ŭ����(abstract class)�̴�.
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
