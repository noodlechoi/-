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
	cout << "1. 도형 추가" << endl;
	cout << "2. 전체 도형 그리기" << endl;
	cout << "3. 도형 제거" << endl;
	cout << "4. 파일 저장 및 읽기" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "입력: ";
}

void UI::print_shape() const
{
	cout << "shape menu" << endl;
	cout << "1. 삼각형" << endl;
	cout << "2. 사각형" << endl;
	cout << "3. 원" << endl;
	cout << "4. 선분" << endl;
	cout << "5. 이전" << endl;
	cout << "입력: ";
}

void UI::print_remove() const
{
	cout << "remove menu" << endl;
	cout << "1. n번째 도형 삭제" << endl;
	cout << "2. 한 종류의 도형 삭제" << endl;
	cout << "3. 이전" << endl;
	cout << "입력: ";
}

void UI::print_file() const
{
	cout << "file menu" << endl;
	cout << "1. 파일에 저장" << endl;
	cout << "2. 파일 읽어오기" << endl;
	cout << "3. 이전" << endl;
	cout << "입력: ";
}


bool UI::input_menu()
{
	int choice;
	try	{
		if (state == State::START) {
			print_start();
			cin >> choice;

			if (isalpha(choice))	// 숫자가 아닌 값이 입력되면 예외처리
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
				cout << "프로그램이 종료됩니다" << endl;
				return true;
				break;
			default: // 없는 번호면 예외처리
				throw choice;
				break;
			}
		}
		else if (state == State::SELECT) {
			print_shape();
			cin >> choice;

			if (isalpha(choice))	// 숫자가 아닌 값이 입력되면 예외처리
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
				// 이전이면 바로 다음으로
				return false;
				break;
			default: // 없는 번호면 예외처리
				throw choice;
				break;
			}

			input_pos();
			state = State::SELECT;
		}
		else if (state == State::REMOVE) {
			print_remove();
			cin >> choice;

			if (isalpha(choice))	// 숫자가 아닌 값이 입력되면 예외처리
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
			default: // 없는 번호면 예외처리
				throw choice;
				break;
			}
			remove();

			state = State::START;
		}
		else if (state == State::FILE) {
			print_file();

			cin >> choice;

			if (isalpha(choice))	// 숫자가 아닌 값이 입력되면 예외처리
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
			default: // 없는 번호면 예외처리
				throw choice;
				break;
			}
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
	cout << "좌표 입력(2차원 좌표)" << endl;

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
		cout << "중심 반지름" << endl;
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
		cout << "도형 개수: " << sm.get_number() << endl;
		cout << "몇 번째 도형을 제거할까요? ";
		cin >> n;

		if (isalpha(n))	// 숫자가 아닌 값이 입력되면 예외처리
			throw n;

		try {
			if (n >= sm.get_number()) throw n;

			// remove
			sm.remove(n);
		}
		catch (const std::exception& e) {
			cout << "범위를 벗어났습니다." << endl;
		}
	}
	else if (state == State::REMOVEALL) {
		int n;
		print_shape();
		cout << "어떤 도형을 제거할까요? ";
		cin >> n;

		if (isalpha(n))	// 숫자가 아닌 값이 입력되면 예외처리
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
				// 이전이면 바로 다음으로
				return;
				break;
			default: // 없는 번호면 예외처리
				throw n;
				break;
			}
		}
		catch (const std::exception& e) {
			cout << "범위를 벗어났습니다." << endl;
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
