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
	cout << "1. ���� �߰�" << endl;
	cout << "2. ��ü ���� �׸���" << endl;
	cout << "3. ���α׷� ����" << endl;
	cout << "�Է�: ";
}

void UI::shape_menu() const
{
	cout << "shape menu" << endl;
	cout << "1. �ﰢ��" << endl;
	cout << "2. �簢��" << endl;
	cout << "3. ��" << endl;
	cout << "4. ����" << endl;
	cout << "�Է�: ";
}

bool UI::input()
{
	int choice;
	try	{
		if (state == 0) {
			start_menu();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			switch (choice) {
			case 1:
				state++;
				break;
			case 2:
				draw();
				break;
			case 3:
				cout << "���α׷��� ����˴ϴ�" << endl;
				return true;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
		}
		else if (state == 1) {
			shape_menu();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
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
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
		}
		else if (state == 2) {
			input_pos();

			// �Է� �� shape �޴��� �̵�
			state = 1;
		}
		else {
			throw state;
		}
	}
	catch (const std::exception& e) {
		cout << "�ٽ� �Է����ּ���" << endl;
	}
	
	std::cout << std::endl;
	return false;

}

void UI::input_pos()
{
	cout << "��ǥ �Է�" << endl;


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
