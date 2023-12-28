//-----------------------------------------------------------------------------
// 여러 개의 도형을 관리하는 클래스
//-----------------------------------------------------------------------------
// Shape* (부모 클래스의 *)로 전체 도형을 관리하는 것이 핵심
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"

class ShapeManager {
	int nShape;							// 현재 관리 중인 도형의 갯수
	int capacity;						// 확보한 메모리에 담을 수 있는 도형의 최대 개수
	Shape** shapes;						// 도형의 포인터들을 담을 수 있는 메모리

public:
	ShapeManager();
	explicit ShapeManager(int n);		// 담을 수 있는 도형의 갯수를 생성자에 전달
										// explict 사용법을 알아보자 => 형변환 제한
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void init(const int& n);			// 멤버변수를 초기화하는 함수
	void insert(Shape* a);				// 도형을 추가하는 함수
	void remove(int n);
	void remove(eShape shape);
	void draw() const;					// 전체 도형을 그리는 함수

	int get_cpacity() const { return capacity; } ;
	int get_number() const { return nShape; };
};

