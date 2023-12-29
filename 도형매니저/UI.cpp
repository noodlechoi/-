#include "UI.h"
using namespace std;


UI::UI(int n) : shape{eShape::NONE}, state{State::START}
{
	sm.init(n);
}

UI::~UI()
{
}


void UI::print_start() const
{
	cout << "start menu" << endl;
	cout << "1. ���� �߰�" << endl;
	cout << "2. ��ü ���� �׸���" << endl;
	cout << "3. ���� ����" << endl;
	cout << "4. ���� ���� �� �б�" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "�Է�: ";
}

void UI::print_shape() const
{
	cout << "shape menu" << endl;
	cout << "1. �ﰢ��" << endl;
	cout << "2. �簢��" << endl;
	cout << "3. ��" << endl;
	cout << "4. ����" << endl;
	cout << "5. ����" << endl;
	cout << "�Է�: ";
}

void UI::print_remove() const
{
	cout << "remove menu" << endl;
	cout << "1. n��° ���� ����" << endl;
	cout << "2. �� ������ ���� ����" << endl;
	cout << "3. ����" << endl;
	cout << "�Է�: ";
}

void UI::print_file() const
{
	cout << "file menu" << endl;
	cout << "1. ���Ͽ� ����" << endl;
	cout << "2. ���� �о����" << endl;
	cout << "3. ����" << endl;
	cout << "�Է�: ";
}


bool UI::input_menu()
{
	int choice;
	try	{
		if (state == State::START) {
			print_start();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			switch (choice) {
			case 1:
				state = State::SELECT;
				break;
			case 2:
				draw();
				break;
			case 3:
				state = State::REMOVE;
				break;
			case 4:
				state = State::FILE;
				break;
			case 5:
				cout << "���α׷��� ����˴ϴ�" << endl;
				return true;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
		}
		else if (state == State::SELECT) {
			print_shape();
			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			// choose
			switch (choice) {
			case 1:
			case 2:
			case 3:
			case 4:
				shape = static_cast<eShape>(choice);
				break;
			case 5:
				state = State::START;
				// �����̸� �ٷ� ��������
				return false;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}

			input_pos();
			state = State::SELECT;
		}
		else if (state == State::REMOVE) {
			print_remove();
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
				state = State::START;
				return false;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
			remove();

			state = State::START;
		}
		else if (state == State::FILE) {
			print_file();

			cin >> choice;

			if (isalpha(choice))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
				throw choice;

			switch (choice) {
			case 1:
				sm.save();
				break;
			case 2:
				sm.load();
				break;
			case 3:
				state = State::START;
				return false;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw choice;
				break;
			}
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
		double r;
		cout << "�߽� ������" << endl;
		cin >> p.x >> p.y >> r;

		sm.insert(new Circle(p, r));
	}
	else if (shape == eShape::LINE) {
		Point p[2];
		for (int i = 0; i < 2; ++i) {
			cin >> p[i].x >> p[i].y;
		}

		sm.insert(new Line(p[0], p[1]));
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
			if (n >= sm.get_number()) throw n;

			// remove
			sm.remove(n);
		}
		catch (const std::exception& e) {
			cout << "������ ������ϴ�." << endl;
		}
	}
	else if (state == State::REMOVEALL) {
		int n;
		print_shape();
		cout << "� ������ �����ұ��? ";
		cin >> n;

		if (isalpha(n))	// ���ڰ� �ƴ� ���� �ԷµǸ� ����ó��
			throw n;

		try {
			switch (n) {
			case 1:
			case 2:
			case 3:
			case 4:
				sm.remove(static_cast<eShape>(n));
				break;
			case 5:
				state = State::START;
				// �����̸� �ٷ� ��������
				return;
				break;
			default: // ���� ��ȣ�� ����ó��
				throw n;
				break;
			}
		}
		catch (const std::exception& e) {
			cout << "������ ������ϴ�." << endl;
		}
		
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
