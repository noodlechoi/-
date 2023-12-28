#include "ShapeManager.h"
#include <iostream>
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;							// ó�� ������� ���� �����ϴ� ���� ������ 0��
	capacity = n;						// �ִ� n���� ������ ���� �� ����
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	// ��� ��ü�� ��Ȯ�ϰ� �����Ǵ��� �ݵ�� Ȯ���Ͽ��� �Ѵ�.
	delete[] shapes;					// ���������ڰ� �����ϴ� ������ �Ҹ��ڸ� ȣ����
}

void ShapeManager::insert(Shape* a)
{
	shapes[nShape] = a;
	nShape++;
}

void ShapeManager::draw() const
{
	cout << "-------------------------------------------" << '\n';
	cout << "�����ϴ� ��� ������ �׸��ϴ�" << '\n';
	cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << '\n';
	cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();				// �������� �����ȴ�.
	}
	cout << '\n';

	cout << "-------------------------------------------" << '\n';
	cout << "�׸��⸦ ��Ĩ�ϴ�" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';
}
