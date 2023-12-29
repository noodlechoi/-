#include "ShapeManager.h"
#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include <iostream>
#include <fstream>
using namespace std;

ShapeManager::ShapeManager() : nShape{0}, capacity{0}, shapes{nullptr}
{
}

ShapeManager::ShapeManager(int n)
{
	nShape = 0;							// 처음 만들어질 때는 관리하는 도형 갯수가 0임
	capacity = n;						// 최대 n개의 도형을 담을 수 있음
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	// 모든 객체가 정확하게 삭제되는지 반드시 확인하여야 한다.
	for(int i = 0; i < nShape; ++i)
		delete shapes[i];
	delete[] shapes;					// 도형관리자가 관리하는 도형의 소멸자를 호출함
}

void ShapeManager::init(const int& n)
{
	try	{
		// shapes가 널포인터면 할당
		if (shapes) throw shapes;

		nShape = 0;							// 처음 만들어질 때는 관리하는 도형 갯수가 0임
		capacity = n;						// 최대 n개의 도형을 담을 수 있음
		shapes = new Shape * [capacity];
	}
	catch (const std::exception& e)	{
		cout << "이미 할당되어있는 메모리입니다." << endl;
	}
}

void ShapeManager::insert(Shape* a)
{
	if (nShape + 1 > capacity) add_capacity();

	shapes[nShape] = a;
	nShape++;
}

void ShapeManager::remove(int n)
{
	// remove
	delete shapes[n];
	nShape--;

	// 뒤에 있는 도형 인덱스 당기기
	for (int i = n; i < nShape; ++i) {
		shapes[i] = shapes[i + 1];
	}
}

void ShapeManager::remove(eShape shape)
{
	for (int i = 0; i < nShape;) {
		if (shapes[i]->get() == shape) {
			remove(i);
		}
		// 삭제하지 않을때만 다음 도형 체크
		else ++i;
	}
}

void ShapeManager::draw() const
{
	cout << "-------------------------------------------" << '\n';
	cout << "관리하는 모든 도형을 그립니다" << '\n';
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << '\n';
	cout << "모두 " << nShape << "개의 도형이 있습니다" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();				// 다형성이 구현된다.
	}
	cout << '\n';

	cout << "-------------------------------------------" << '\n';
	cout << "그리기를 마칩니다" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';
}

void ShapeManager::add_capacity()
{
	// temp로 주소 저장
	Shape** temp = shapes;

	// 메모리 공간 하나 더 추가
	shapes = new Shape * [nShape + 1];

	// 이전 정보 옮기기
	for (int i = 0; i < nShape; ++i) {
		shapes[i] = temp[i];
	}

	// 이전 메모리 반환
	delete[] temp;
}

void ShapeManager::reset()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];
	delete[] shapes;

	nShape = 0;
	shapes = new Shape * [capacity];
}

void ShapeManager::save()
{
	ofstream f("shape.txt");

	try {
		if (!f) {
			throw 0;
		}

		f << capacity << "\n";

		for (int i = 0; i < nShape; ++i) {
			shapes[i]->save(f);
		}

		// 마지막 줄을 load 안 하도록 -1을 넣음
		f << -1;

		f.close();
	}
	catch (const std::exception& e) {
		cout << "file open fail" << endl;
	}
}

void ShapeManager::load()
{
	ifstream f("shape.txt");

	try {
		if (!f) {
			throw 0;
		}

		f >> capacity;

		reset();

		while (f) {
			int s; // shape
			f >> s;

			switch (static_cast<eShape>(s)) {
			case eShape::TRIANGLE:
			{
				Point p[3];
				for (int i = 0; i < 3; ++i) {
					f >> p[i].x >> p[i].y;
				}

				insert(new Triangle(p[0], p[1], p[2]));
			}
				break;
			case eShape::RECTANGLE:
			{
				Point p[2];
				for (int i = 0; i < 2; ++i) {
					f >> p[i].x >> p[i].y;
				}

				insert(new Rectangle(p[0], p[1]));
			}
				break;
			case eShape::CIRCLE:
			{
				Point p;
				double r;
				f >> p.x >> p.y >> r;

				insert(new Circle(p, r));
			}
				break;
			default:
				f.close();
				return;
			}
		}
		
		f.close();
	}
	catch (const std::exception& e) {
		cout << "file open fail" << endl;
	}
}

