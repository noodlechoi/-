#pragma once
#include "point.h"
#include "shape.h"

class Line : public Shape
{
	Point p1, p2;
public:
	Line();
	Line(const Point& a, const Point& b);
	Line(const Line& other);
	~Line();

	virtual void draw() const override;			// virtual function¿ª overriding
	virtual void save(std::ofstream& f) override;
};

