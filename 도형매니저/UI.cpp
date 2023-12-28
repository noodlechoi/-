#include "UI.h"
using namespace std;


UI::UI(int n) : shape{eShape::NONE}, state{State::START}
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
	cout << "3. ���� ����" << endl;
	cout << "4. ���α׷� ����" << endl;
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

void UI::remove_menu() const
{
	cout << "remove menu" << endl;
	cout << "1. n��° ���� ����" << endl;
	cout << "2. �� ������ ���� ����" << endl;
	cout << "3. ����" << endl;
	cout << "�Է�: ";
}

bool UI::input()
{
	int choice;
	try	{
		if (state == State::START) {
			start_menu();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			switch (choice) {
			case 1:
				state = State::ADD;
				break;
			case 2:
				draw();
				break;
			case 3:
				state = State::REMOVEMENU;
				break;
			case 4:
				cout << "���α׷��� ����˴ϴ�" << endl;
				return true;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
		}
		else if (state == State::ADD) {
			shape_menu();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			switch (choice) {
			case 1:
				shape = eShape::TRIANGLE;
				state = State::INPUTPOS;
				break;
			case 2:
				shape = eShape::RECTANGLE;
				state = State::INPUTPOS;
				break;
			case 3:
				shape = eShape::CIRCLE;
				state = State::INPUTPOS;
				break;
			case 4:
				state = State::START;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
		}
		else if (state == State::INPUTPOS) {
			input_pos();

			state = State::ADD;
		}
		else if (state == State::REMOVEMENU) {
			remove_menu();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			switch (choice) {
			case 1:
				state = State::REMOVEONE;
				break;
			case 2:
				state = State::REMOVEALL;
				break;
			case 3:
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
			remove();

			state = State::START;
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
	cout << "��ǥ �Է�(2���� ��ǥ)" << endl;

	//int p_capacity;
	if (shape == eShape::TRIANGLE) {
		// input point
		Point p[3];
		for (int i = 0; i < 3; ++i) {
			cin >> p[i].x >> p[i].y;
		}

		sm.insert(new Triangle(p[0], p[1], p[2]));
	}
	else if (shape == eShape::RECTANGLE) {
		Point p[2];
		for (int i = 0; i < 2; ++i) {
			cin >> p[i].x >> p[i].y;
		}

		sm.insert(new Rectangle(p[0], p[1]));
	}
	else if (shape == eShape::CIRCLE) {
		Point p;
		double center;
		cout << "�߽� ������" << endl;
		cin >> p.x >> p.y >> center;

		sm.insert(new Circle(p, center));
	}

	/*Point* p = new Point[p_capacity];
	for (int i = 0; i < p_capacity; ++i) {
		cin >> p[i].x >> p[i].y;
	}*/
}

void UI::remove()
{
	if (state == State::REMOVEONE) {
		int n;
		cout << "���� ����: " << sm.get_number() << endl;
		cout << "�� ��° ������ �����ұ��? ";
		cin >> n;

		if (isalpha(n))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
			throw n;

		try {
			if (n > sm.get_cpacity()) throw n;

			sm.remove(n);
		}
		catch (const std::exception& e) {
			cout << "������ ������ϴ�." << endl;
		}
	}
	else if (state == State::REMOVEALL) {

	}
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
