#pragma once

#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"

class UI
{
	ShapeManager sm;
public:
	explicit UI(int n);
	~UI();
	UI(const UI&) = default;

	void init();
	void draw() const;
	void menu() const;
};

