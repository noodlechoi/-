#include "ShapeManager.h"
#include <iostream>
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
	//delete[] shapes;					// 도형관리자가 관리하는 도형의 소멸자를 호출함
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

