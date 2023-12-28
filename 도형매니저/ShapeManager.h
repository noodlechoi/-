//-----------------------------------------------------------------------------
// ���� ���� ������ �����ϴ� Ŭ����
//-----------------------------------------------------------------------------
// Shape* (�θ� Ŭ������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"

class ShapeManager {
	int nShape;							// ���� ���� ���� ������ ����
	int capacity;						// Ȯ���� �޸𸮿� ���� �� �ִ� ������ �ִ� ����
	Shape** shapes;						// ������ �����͵��� ���� �� �ִ� �޸�

public:
	ShapeManager();
	explicit ShapeManager(int n);		// ���� �� �ִ� ������ ������ �����ڿ� ����
										// explict ������ �˾ƺ��� => ����ȯ ����
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void init(const int& n);			// ��������� �ʱ�ȭ�ϴ� �Լ�
	void insert(Shape* a);				// ������ �߰��ϴ� �Լ�
	void remove(int n);
	void remove(eShape shape);
	void draw() const;					// ��ü ������ �׸��� �Լ�

	int get_cpacity() const { return capacity; } ;
	int get_number() const { return nShape; };
};

