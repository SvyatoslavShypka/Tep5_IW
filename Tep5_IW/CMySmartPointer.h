#include <iostream>

using namespace std;

class CRefCounter
{
public:
	CRefCounter() {
		//iAdd();
	}
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
private:
	int i_count = 0;
};//class CRefCounter

template <typename T> class CMySmartPointer
{
public:
	//CMySmartPointer() {};
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	T& operator*() { return(*pc_pointer); };
	T* operator->() { return(pc_pointer); };
	CMySmartPointer& operator=(const CMySmartPointer& pcOther);
private:
	CRefCounter* pc_counter;
	T* pc_pointer;
};//class CMySmartPointer

//CMySmartPointer<int>::CMySmartPointer(int* pcPointer) {
//	cout << "int constructor" << endl;
//};

template <typename T> CMySmartPointer<T>::CMySmartPointer(T* pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
	cout << "New object " << this << " was created" << endl;

}//CMySmartPointer(T* pcPointer)

template <typename T> CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
	cout << "New copy pointer on " << this << " was created" << endl;
}//CMySmartPointer(const CMySmartPointer& pcOther)

template <typename T> CMySmartPointer<T>::~CMySmartPointer()
{
	cout << "Delete constructor performed" << endl;
	if (pc_counter->iDec() == 0)
	{
		cout << "Delete pointer: " << pc_pointer << " performed" << endl;
		delete pc_pointer;
		delete pc_counter;
	}//if (pc_counter->iDec())

}//~CMySmartPointer()

template <typename T> CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer& pcOther)
{
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
	return(*this);
}