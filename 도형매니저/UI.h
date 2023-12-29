#pragma once

#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"

enum class State
{
	START,
	SELECT,
	REMOVE,
	REMOVEONE,
	REMOVEALL,
};

class UI
{
	ShapeManager sm;
	State state;
	eShape shape;
public:
	explicit UI(int n);
	~UI();
	UI(const UI&) = default;

	int get_state() { return static_cast<int>(state); };

	void print_start() const;
	void print_shape() const;
	void print_remove() const;
	bool input_menu();	// 종료 시 true 반환
	void input_pos();
	void remove();
	void init();
	void draw() const;
};

