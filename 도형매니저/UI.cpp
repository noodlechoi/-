#include "UI.h"
#include <iostream>
using namespace std;


UI::UI(int n) : state{0}, shape{eShape::NONE}
{
	sm.init(n);
}

UI::~UI()
{
}


void UI::start_menu() const
{
	cout << "start menu" << endl;
	cout << "1. 도형 추가" << endl;
	cout << "2. 전체 도형 그리기" << endl;
	cout << "3. 프로그램 종료" << endl;
	cout << "입력: ";
}

void UI::shape_menu() const
{
	cout << "shape menu" << endl;
	cout << "1. 삼각형" << endl;
	cout << "2. 사각형" << endl;
	cout << "3. 원" << endl;
	cout << "4. 이전" << endl;
	cout << "입력: ";
}

bool UI::input()
{
	int choice;
	try	{
		if (state == 0) {
			start_menu();
			cin >> choice;

			if (isalpha(choice))	// 숫자가 아닌 값이 입력되면 예외처리
				throw choice;

			switch (choice) {
			case 1:
				state++;
				break;
			case 2:
				draw();
				break;
			case 3:
				cout << "프로그램이 종료됩니다" << endl;
				return true;
				break;
			default: // 없는 번호면 예외처리
				throw choice;
				break;
			}
		}
		else if (state == 1) {
			shape_menu();
			cin >> choice;

			if (isalpha(choice))	// 숫자가 아닌 값이 입력되면 예외처리
				throw choice;

			switch (choice) {
			case 1:
				shape = eShape::TRIANGLE;
				break;
			case 2:
				shape = eShape::RECTANGLE;
				break;
			case 3:
				shape = eShape::CIRCLE;
				break;
			case 4:
				state--;
				break;
			default: // 없는 번호면 예외처리
				throw choice;
				break;
			}
		}
		else if (state == 2) {
			input_pos();

			// 입력 후 shape 메뉴로 이동
			state = 1;
		}
		else {
			throw state;
		}
	}
	catch (const std::exception& e) {
		cout << "다시 입력해주세요" << endl;
	}
	
	std::cout << std::endl;
	return false;

}

void UI::input_pos()
{
	cout << "좌표 입력" << endl;


}

void UI::draw() const
{
	sm.draw();
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
