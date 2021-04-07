#pragma once
#include <iostream>
#include <string>

using namespace std;

class Triangle
{
public:
	bool Init(float, float);
	void Read();
	void ShowSides();
	void ShowHipotenuse();
	float Hipotenuse();

private:
	float first;
	float second;
};

class Exam
{
public:
	Exam();
	Exam(string, string, int);
	Exam(const Exam&);
	void Show();
	void SetFIO(string);
	void SetSubject(string);
	void SetMark(int);
	string GetFIO();
	string GetSubject();
	int GetMark();
private:
	string FIO;
	string subj;
	int mark;
};

class Money
{
public:
	Money();
	Money(long, int);
	Money(const Money&);
	void SetRub(long);
	void SetCent(int);
	long GetRub();
	int GetCent();
	Money& operator = (const Money&);
	bool operator == (const Money&);
	bool operator != (const Money&);
	bool operator > (const Money&);
	void operator + (float);
	Money& operator -- ();
	Money operator -- (int);

	friend istream& operator >> (istream& in, Money& obj);
	friend ostream& operator << (ostream& out, Money& obj);
private:
	long rub;
	int cent;
};

/////
class Triad
{
public:
	Triad();
	Triad(int, int, int);
	Triad(const Triad&);
	void SetFirst(int);
	void SetSecond(int);
	void SetThird(int);
	int GetFirst();
	int GetSecond();
	int GetThird();
	Triad& operator = (const Triad&);
	Triad& operator++();
	friend istream& operator >> (istream& in, Triad& obj);
	friend ostream& operator << (ostream& out, Triad& obj);
protected:
	int first;
	int second;
	int third;
};

class Date : public Triad
{
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	void IncN(int);
	friend istream& operator >> (istream& in, Date& obj);
	friend ostream& operator << (ostream& out, Date& obj);
};
////

////
class TRIAD
{
public:
	TRIAD();
	TRIAD(int, int, int);
	virtual void Inc() = 0;
	virtual void Show() = 0;
	virtual void First() = 0;
protected:
	int first;
	int second;
	int third;
};

class DATE : public TRIAD
{
public:
	DATE();
	DATE(int, int, int);
	DATE(const DATE&);
	void Inc() override;
	void Show() override;
	void First() override;
	friend istream& operator >> (istream& in, DATE& obj);
	friend ostream& operator << (ostream& out, DATE& obj);
};

class Vector
{
public:
	Vector();
	~Vector();
	Vector(int);
	void Add();
	void Del();
	void Show();
	void Year();
	friend ostream& operator << (ostream& out, Vector& obj);
protected:
	TRIAD** pntr;
	int curr;
	int len;
};

////

// also for 18.7 (templates) and 18.9 (exceptions)

class Error // for 18.9 (2 variant of realization)
{
public:
	Error(string exc) { this->exc = exc; }
	void PrintError() { cout << endl << exc << endl; }
private:
	string exc;

};

template<typename T>
class Set
{
public:
	friend ostream& operator << <T>(ostream& out, const Set<T>&);
	Set();
	~Set();
	Set(int);
	Set(const Set<T>&);
	T& operator [](int);
	void Del();
	Set<T>& operator = (const Set<T>&);
	int operator ()();
	Set<T> operator - (const Set<T>&);
private:
	int size;
	T* arr;
};

// определение методов ШАБЛОННЫХ классов должно быть в одном хедере с объявлением класса
#define MAX_SIZE 10
#define FIRST_VARIANT 0
#define SECOND_VARIANT 1

template<typename T>
Set<T>::Set()
{
	size = 0;
	arr = nullptr;
}
template<typename T>
Set<T>::Set(int size)
{
	if (size > MAX_SIZE and FIRST_VARIANT) throw 1;
	else if (size > MAX_SIZE and SECOND_VARIANT) throw Error("\nSize > MAX_SIZE\n");
	this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = sizeof(arr[i]);
	}
}
template<typename T>
Set<T>::Set(const Set<T>& obj)
{
	this->size = obj.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = obj.arr[i];
	}
}
template<typename T>
Set<T>::~Set()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}
template<typename T>
T& Set<T>::operator[](int index)
{
	if (index >= size and FIRST_VARIANT) throw 2;
	else if (index < 0 and FIRST_VARIANT) throw 3;
	if (index >= size and SECOND_VARIANT) throw Error("\nIndex >= Size\n");
	else if (index < 0 and SECOND_VARIANT) throw Error("\nIndex < 0\n");
	if (index < size) return arr[index];
}
template<typename T>
int Set<T>::operator()()
{
	return size;
}
template<typename T>
void Set<T>::Del()
{
	if (size == 0 and FIRST_VARIANT) throw 4;
	else if (size == 0 and SECOND_VARIANT) throw Error("\nNothing to be deleted!\n");
	--size;
}

template<class T>
Set<T>& Set<T>::operator=(const Set<T>& obj)
{
	size = obj.size;
	if (arr != nullptr) delete[] arr;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}
template<typename T>
Set<T> Set<T>::operator -(const Set<T>& obj)
{
	if (this->arr == nullptr and FIRST_VARIANT) throw 6;
	else if (obj.arr == nullptr and FIRST_VARIANT) throw 7;

	if (this->arr == nullptr and SECOND_VARIANT) throw Error("\nSets can't be differed > Set1 is empty\n");
	else if (obj.arr == nullptr and SECOND_VARIANT) throw Error("\nSets can't be differed > Set2 is empty\n");

	int res;
	size > obj.size ? res = size : res = obj.size;
	Set<T> temp(res);
	if (obj.arr == nullptr) temp = *this;
	if (size < obj.size)
	{
		for (int i = 0; i < obj.size; ++i)
		{
			if (i < size) temp.arr[i] = arr[i] - obj.arr[i];
			else temp.arr[i] = obj.arr[i];
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			if (i < obj.size || size == obj.size) temp.arr[i] = arr[i] - obj.arr[i];
			else temp.arr[i] = arr[i];
		}
	}
	return temp;
}

template <typename T>
ostream& operator << (ostream& out, const Set<T>& obj)
{

	if (obj.arr != nullptr)
	{
		for (int i = 0; i < obj.size; ++i)
		{
			out << obj.arr[i] << " ";
		}
		cout << endl;
	}
	else if (FIRST_VARIANT) throw 8;
	else if (SECOND_VARIANT) throw Error("\nNothing to be printed!\n");
	return out;
}


// lab 18.8 

const int evNothing = 0;//пустое событие 
const int evMessage = 100;//непустое событие 
const int cmAdd = 1;//добавить объект в группу 
const int cmDel = 2;//удалить объект из группы
const int cmYear = 3;//вывести первое поле объектов группы
const int cmShow = 4;//вывести всю группу
const int cmMake = 6;//создать группу 
const int cmQuit = 101;//выход

struct TEvent
{
	int what;
	union
	{
		int command;

		struct

		{
			int message;
			int a;
		};
	};
};

class Dialog : public Vector
{
public:
	Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

// lab 18.9



//
