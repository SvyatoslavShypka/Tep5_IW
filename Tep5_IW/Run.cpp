#pragma once
#include "CMySmartPointer.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
static void test(CMySmartPointer<T> pointer1) {
	CMySmartPointer<int> copyPointer1(pointer1); //copy constructor
	//do smth
}

int main() {

	int* x;
	x = new int();

	int* y;
	y = new int();
	CMySmartPointer<int> pointer1(x);
	CMySmartPointer<int>* pointerDynamic = new CMySmartPointer<int>(y);

	CMySmartPointer<int> pointer2 = pointer1;

	test(pointer1);

	delete pointerDynamic;

	return 0;
}

