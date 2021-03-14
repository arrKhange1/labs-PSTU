#include <iostream>
#include <string>
#include "classes.h"
using namespace std;

bool Triangle::Init(float first, float second)
{
	if (first <= 0 || second <= 0) return false;
	else
	{
		this->first = first;
		this->second = second;
	}

}

void Triangle::Read()
{
	cout << "Enter first: "; cin >> first;
	cout << "Enter second: "; cin >> second;
	while (first <= 0 || second <= 0)
	{
		cout << "U've entered incorrect data:\n\n";
		cout << "Enter first again: "; cin >> first;
		cout << "Enter second again: "; cin >> second;
	}
	cout << endl;
}

void Triangle::ShowSides()
{
	cout << "First = " << first << " Second = " << second << endl;
}

void Triangle::ShowHipotenuse()
{
	cout << "Hipotenuse = " << Hipotenuse() << endl;
}

float Triangle::Hipotenuse()
{
	return sqrt(pow(first, 2) + pow(second, 2));
}

//////////////////////////////////////

Exam::Exam()
{
	cout << "\nConstr. w/o params for the object " << this << endl;
	FIO = "";
	subj = "";
	mark = 0;
}


Exam::Exam(string FIO, string subj, int mark)
{
	cout << "\nConstr. with params for the object " << this << endl;
	this->FIO = FIO;
	this->subj = subj;
	this->mark = mark;
}

Exam::Exam(const Exam& object)
{
	cout << "\nCopy constr. for the object " << this << " from " << &object << endl;
	FIO = object.FIO;
	subj = object.subj;
	mark = object.mark;
}

void Exam::Show()
{
	cout << "\nFIO: " << FIO << "\nSubject: " << subj << "\nMark: " << mark << endl;
}

void Exam::SetFIO(string FIO)
{
	this->FIO = FIO;
}

void Exam::SetSubject(string subj)
{
	this->subj = subj;
}

void Exam::SetMark(int mark)
{
	this->mark = mark;
}

string Exam::GetFIO()
{
	return FIO;
}

string Exam::GetSubject()
{
	return subj;
}

int Exam::GetMark()
{
	return mark;
}

////////////////////////

Money::Money()
{
	cout << "\nConstr. w/o params for the object " << this << endl;
	rub = 0;
	cent = 0;
}

Money::Money(long rub, int cent)
{
	cout << "\nConstr. with params for the object " << this << endl;
	this->rub = rub;
	this->cent = cent;
}

Money::Money(const Money& object)
{
	cout << "\nConstr. copy for the object " << this <<" from " << &object << endl;
	rub = object.rub;
	cent = object.cent;
}

void Money::SetRub(long rub)
{
	this->rub = rub;
}

void Money::SetCent(int cent)
{
	this->cent = cent;
}

long Money::GetRub()
{
	return rub;
}

int Money::GetCent()
{
	return cent;
}

Money& Money::operator=(const Money& object)
{
	if (&object == this) return *this;
	rub = object.rub;
	cent = object.cent;
	return *this;
}

bool Money::operator==(const Money& object)
{
	if (rub == object.rub && cent == object.cent) return true;
	return false;
}

bool Money::operator!=(const Money& object)
{
	if (rub != object.rub || cent != object.cent) return true;
	return false;
}

Money& Money::operator--()
{
	--cent;
	return *this;
}

Money Money::operator--(int value)
{
	Money temp(*this);
	--cent;
	return temp;
}

////
Triad::Triad()
{
	first = 0;
	second = 0;
	third = 0;
}

Triad::Triad(int first, int second, int third)
{
	this->first = first;
	this->second = second;
	this->third = third;
}

Triad::Triad(const Triad& obj)
{
	first = obj.first;
	second = obj.second;
	third = obj.third;
}

void Triad::SetFirst(int first)
{
	this->first = first;
}

void Triad::SetSecond(int second)
{
	this->second = second;
}

void Triad::SetThird(int third)
{
	this->third = third;
}

int Triad::GetFirst()
{
	return first;
}

int Triad::GetSecond()
{
	return second;
}

int Triad::GetThird()
{
	return third;
}

Triad& Triad::operator=(const Triad& obj)
{
	if (&obj == this) return *this;
	first = obj.first;
	second = obj.second;
	third = obj.third;
	return *this;
}

Triad& Triad::operator++()
{
	++first;
	++second;
	++third;
	return *this;
}

Date::Date() :Triad()
{
	first = 0;
	second = 0;
	third = 0;
}

Date::Date(int first, int second, int third) :Triad(first, second, third)
{
	this->first = first;
	this->second = second;
	this->third = third;
}

Date::Date(const Date& obj)
{
	first = obj.first;
	second = obj.second;
	third = obj.third;
}

void Date::IncN(int N)
{
	first += N;
	second += N;
	third += N;
}

////

TRIAD::TRIAD()
{
	first = 0;
	second = 0;
	third = 0;
}

TRIAD::TRIAD(int first, int second, int third)
{
	this->first = first;
	this->second = second;
	this->third = third;
}

DATE::DATE():TRIAD()
{
	first = 0;
	second = 0;
	third = 0;
}

DATE::DATE(int first, int second, int third):TRIAD(first,second,third)
{
	this->first = first;
	this->second = second;
	this->third = third;
}

DATE::DATE(const DATE& obj)
{
	first = obj.first;
	second = obj.second;
	third = obj.third;
}

void DATE::Inc()
{
	++first;
	++second;
	++third;
}

void DATE::Show()
{
	cout << *this << endl;
}

Vector::Vector()
{
	pntr = nullptr;
	curr = 0;
	len = 0;
}

Vector::~Vector()
{
	if (len != 0) delete[]pntr;
	pntr = nullptr;
}

Vector::Vector(int n)
{
	pntr = new TRIAD * [n];
	len = n;
	curr = 0;
}

void Vector::Add(TRIAD* ptr)
{
	if (curr < len)
	{
		pntr[curr++] = ptr;
	}
}