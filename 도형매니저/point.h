//-----------------------------------------------------------------------------
// Point class declaration - ��� ������ ������ �����Ǿ�� �Ѵ�
// 2���� ��ǥ (x,y)�� ��Ÿ����
//-----------------------------------------------------------------------------
#pragma once


struct Point {									// struct - default public
	double x, y;

	Point();									// default constructor - ����� �Լ�
	Point(double a, double b);
	Point(const Point& other) = default;		// ��������� - ����ڰ� ���� �ʿ� ���ٴ� �ǹ�
};
