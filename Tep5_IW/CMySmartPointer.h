using namespace std;

class CRefCounter
{
public:
	CRefCounter() {
		iAdd();
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
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	T& operator*() { return(*pc_pointer) };
	T* operator->() { return(pc_pointer) };
	CMySmartPointer& operator=(const CMySmartPointer& pcOther);
private:
	CRefCounter* pc_counter;
	T* pc_pointer;
};//class CMySmartPointer

template <typename T> CMySmartPointer<T>::CMySmartPointer(T* pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	//pc_counter->iAdd();
}//CMySmartPointer(T* pcPointer)

template <typename T> CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}//CMySmartPointer(const CMySmartPointer& pcOther)

template <typename T> CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
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