//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// �� Ŭ������ �߻� Ŭ����(abstract class)�̴�.
//-----------------------------------------------------------------------------
#pragma once


class Shape {
public:
	Shape() {};
	~Shape() {};

	virtual void draw() const = 0;			// pure virtual function
};
