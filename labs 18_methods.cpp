#include <iostream>
#include <cmath>
#include <sstream>
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
	cout << "\nConstr. copy for the object " << this << " from " << &object << endl;
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
	if (cent < 0)
	{
		--rub;
		cent = 99;
	}
	return *this;
}

Money Money::operator--(int value)
{
	Money temp(*this);
	--cent;
	if (cent < 0)
	{
		--rub;
		cent = 99;
	}
	return temp;
}

bool Money::operator > (const Money& obj)
{
	if (rub > obj.rub) return true;
	else if (rub < obj.rub) return false;
	else if (cent > obj.cent) return true;
	else return false;
}

void Money::operator+(float bal)
{	
	int cent_concatenate = cent + round(stof(to_string(0) + to_string(bal).substr(to_string(bal).find('.'), to_string(bal).find('.') + 2)) * 100);
	cent = cent_concatenate % 100;
	rub += (int)bal + cent_concatenate / 100;	
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

DATE::DATE() :TRIAD()
{
	first = 0;
	second = 0;
	third = 0;
}

DATE::DATE(int first, int second, int third) :TRIAD(first, second, third)
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

void DATE::First()
{
	cout << endl << this << " Object's first field: " << this->first << endl;
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

void Vector::Add()
{
	if (curr < len)
	{
		TRIAD* ptr;
		DATE* ob = new DATE;
		cin >> *ob;
		ptr = ob;
		pntr[curr++] = ptr;
	}
	else cout << "\nVector is already filled\n";
}

void Vector::Del()
{
	if (curr == 0) cout << "\nVector is empty! Nothing to be deleted!\n";
	else
	{
		--curr;
		cout << "\nThe last object was deleted!\n";
	}
}

void Vector::Year()
{
	if (curr == 0) cout << "\nVector is empty!\n";
	else
	{
		TRIAD** p = pntr;
		for (int i = 0; i < curr; ++i)
		{
			(*p)->First();
			++p;
		}
	}
}

void Vector::Show()
{
	if (curr == 0) cout << "\nVector is empty\n";
	TRIAD** p = pntr;
	for (int i = 0; i < curr; ++i)
	{
		(*p)->Show();
		++p;
	}
}

//// lab 18.8

Dialog::Dialog(void) :Vector()
{
	EndState = 0;
}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-@yq";
	cout << "\nm(with size of a group) - create a group\n+ - add an object\n- - delete an object\n@ - show all\ny - show all first fields\nq - finish a session\n\n";
	string s;
	string param;

	char code; cout << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code) != string::npos)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case '@': event.command = cmShow; break;
		case 'y': event.command = cmYear; break;
		case'q': event.command = cmQuit; break;
			//default: cout << "\nNo such command!\n";
		}

		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);

			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else
	{
		event.what = evNothing;
		cout << "\nNo such command!\n";
	}
}

int Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

void Dialog::EndExec()
{
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			if (pntr != nullptr)
			{
				delete[] pntr;
				pntr = nullptr;
			}
			len = event.a;
			cout << len << " " << pntr << endl;
			pntr = new TRIAD * [len];
			curr = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmYear:
			Year();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		};

	};
}
// 


