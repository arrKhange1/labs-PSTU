#pragma once
#include <iostream>
#include <string>
using namespace std;

class Triangle
{
public:
	bool Init(float,float);
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
protected:
	int first;
	int second;
	int third;
};
 
class DATE: public TRIAD
{
public:
	DATE();
	DATE(int, int, int);
	DATE(const DATE&);
	void Inc() override;
	void Show() override;
	friend istream& operator >> (istream& in, DATE& obj);
	friend ostream& operator << (ostream& out, DATE& obj);
};

class Vector
{
public:
	Vector();
	~Vector();
	Vector(int);
	void Add(TRIAD*);
	friend ostream& operator << (ostream& out, Vector& obj);
private:
	TRIAD** pntr;
	int curr;
	int len;
};

////

// also for 18.7 (templates)

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
	Set<T>& operator = (const Set<T>&);
	int operator ()();
	Set<T> operator - (const Set<T>&);
private:
	int size;
	T* arr;
};

// определение методов ШАБЛОННЫХ классов должно быть в одном хедере с объявлением класса
template<typename T>
Set<T>::Set()
{
	size = 0;
	arr = nullptr;
}
template<typename T>
Set<T>::Set(int size)
{
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
	if (index < size) return arr[index];
	else cout << "\nIndex is out of range\n";
}
template<typename T>
int Set<T>::operator()()
{
	return size;
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
	return out;
}


//
