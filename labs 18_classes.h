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
