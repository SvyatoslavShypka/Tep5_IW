#pragma once
#include <CSellData.h>

class CMySmartPointer
{
public:
	string x;
	CMySmartPointer(CSellData* pcPointer) { pc_pointer = pcPointer; }
	~CMySmartPointer() { delete pc_pointer; }
	CSellData& operator*() { return(*pc_pointer); }
	CSellData* operator->() { return(pc_pointer); }
private:
	CSellData* pc_pointer;
};//class CMySmartPointer