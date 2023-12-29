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
	nShape = 0;							// ó�� ������� ���� �����ϴ� ���� ������ 0��
	capacity = n;						// �ִ� n���� ������ ���� �� ����
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	// ��� ��ü�� ��Ȯ�ϰ� �����Ǵ��� �ݵ�� Ȯ���Ͽ��� �Ѵ�.
	for(int i = 0; i < nShape; ++i)
		delete shapes[i];
	delete[] shapes;					// ���������ڰ� �����ϴ� ������ �Ҹ��ڸ� ȣ����
}

void ShapeManager::init(const int& n)
{
	try	{
		// shapes�� �������͸� �Ҵ�
		if (shapes) throw shapes;

		nShape = 0;							// ó�� ������� ���� �����ϴ� ���� ������ 0��
		capacity = n;						// �ִ� n���� ������ ���� �� ����
		shapes = new Shape * [capacity];
	}
	catch (const std::exception& e)	{
		cout << "�̹� �Ҵ�Ǿ��ִ� �޸��Դϴ�." << endl;
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

	// �ڿ� �ִ� ���� �ε��� ����
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
		// �������� �������� ���� ���� üũ
		else ++i;
	}
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

void ShapeManager::add_capacity()
{
	// temp�� �ּ� ����
	Shape** temp = shapes;

	// �޸� ���� �ϳ� �� �߰�
	shapes = new Shape * [nShape + 1];

	// ���� ���� �ű��
	for (int i = 0; i < nShape; ++i) {
		shapes[i] = temp[i];
	}

	// ���� �޸� ��ȯ
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

		// ������ ���� load �� �ϵ��� -1�� ����
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

