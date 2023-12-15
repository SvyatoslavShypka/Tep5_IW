#pragma once
#include <iostream>
#include <string>

class CSellData {

private:
	string dataType;

public:
	CSellData() {};
	CSellData(string stringArg) {
		dataType = stringArg;
	};
	~CSellData() {};


};