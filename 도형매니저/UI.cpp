#include "UI.h"
#include <iostream>
using namespace std;


UI::UI(int n)
{
	sm.init(n);
}

UI::~UI()
{
}

void UI::draw() const
{
	sm.draw();
}

void UI::menu() const
{
	cout << "menu" << endl;
	cout << "1. chose shape" << endl;
}

void UI::init()
{
	sm.insert(new Triangle());
	sm.insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
	sm.insert(new Circle(Point(1.23, 4.56), 7.89));

	for (int i = 0; i < 10; ++i)
		sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));

	sm.insert(new Rectangle(Point(3, 3), Point(5, 5)));
}
