#pragma once
#include "CMySmartPointer.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	int* x;
	x = new int[3];
	CMySmartPointer<int> pointer1(x);
	CMySmartPointer<int> copyPointer1(pointer1); //copy constructor
	//do smth
	delete &copyPointer1;
	delete &pointer1;

	return 0;
}
