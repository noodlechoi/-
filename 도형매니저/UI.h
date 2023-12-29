#pragma once

#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"
#include "line.h"

enum class State
{
	START,
	SELECT,
	REMOVE,
	REMOVEONE,
	REMOVEALL,
	FILE,
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

	// menu print
	void print_start() const;
	void print_shape() const;
	void print_remove() const;
	void print_file() const;

	bool input_menu();	// ���� �� true ��ȯ
	void input_pos(); // ���õ� ������ ���� ��ǥ �� ������ �Է�
	void remove();
	void init();
	void draw() const;
};

