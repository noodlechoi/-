#pragma once

#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"


class UI
{
	ShapeManager sm;
	int state;
	eShape shape;
public:
	explicit UI(int n);
	~UI();
	UI(const UI&) = default;

	int get_state() { return state; };

	void start_menu() const;
	void shape_menu() const;
	bool input();	// 종료 시 true 반환
	void input_pos();
	void init();
	void draw() const;
};

