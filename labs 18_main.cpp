// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <ctime>
#include "classes.h"
using namespace std;

// for lab 18.1
Triangle Make_Triangle(float first, float second)
{
    Triangle temp;
    temp.Init(first, second);
    return temp;
}
//

// for lab 18.2
Exam Make_Exam()
{
    string str1;
    string str2;
    int m;
    cout << "\nFIO: ";
    cin.get();
    getline(cin, str1);
    cout << "\nSubject: ";
    cin >> str2;
    cout << "\nMark: ";
    cin >> m;
    cout << endl;
    Exam exam(str1, str2, m);
    exam.Show();
    return exam;

}

void Print_Exam(Exam object)
{
    object.Show();
}
//

// for lab 18.3
istream& operator >> (istream& in, Money& obj)
{
    cout << "\nEnter values of rubbles and cents:\n\n";
    cout << "Rubbles: "; in >> obj.rub;
    cout << "\nCents: "; in >> obj.cent;
    while (obj.rub < 0 || (obj.cent < 0 || obj.cent > 99))
    {
        cout << "\nIncorrect values! Try again:\n";
        cout << "Rubbles: "; in >> obj.rub;
        cout << "\nCents: "; in >> obj.cent;
    }
    return in;
}

ostream& operator << (ostream& out, Money& obj)
{
    out << "\nBalance: " << obj.rub << "." << obj.cent << endl;
    return out;
}
//

// for lab 18.4
istream& operator >> (istream& in, Triad& obj)
{
    cout << "\nEnter values of first, second, third:\n\n";
    cout << "First: "; in >> obj.first;
    cout << "\nSecond: "; in >> obj.second;
    cout << "\nThird: "; in >> obj.third;
    return in;
}
ostream& operator << (ostream& out, Triad& obj)
{
    out << "\nFirst,Second,Third: " << obj.first << ", " << obj.second <<", " << obj.third << endl;
    return out;
}

istream& operator >> (istream& in, Date& obj)
{
    cout << "\nEnter values of Year, Month, Number:\n\n";
    cout << "Year: "; in >> obj.first;
    cout << "\nMonth: "; in >> obj.second;
    cout << "\nNumber: "; in >> obj.third;
    return in;
}
ostream& operator << (ostream& out, Date& obj)
{
    out << "\nYear,Month,Number: " << obj.first << ", " << obj.second << ", " << obj.third << endl;
    return out;
}

void subs1(Triad& obj)
{
    ++obj;
    cout << "\n1st subs of Triad with (Date) bday " << obj;
}

Triad subs2()
{
    Date date(2005, 7, 19);
    ++date;
    cout << "\n2nd subs of (Triad) nums with (Date) date(2005,7,19)\n";
    return date;
}
//

//for 18.5
istream& operator >> (istream& in, DATE& obj)
{
    cout << "\nEnter values of first, second, third:\n\n";
    cout << "First: "; in >> obj.first;
    cout << "\nSecond: "; in >> obj.second;
    cout << "\nThird: "; in >> obj.third;
    return in;
}
ostream& operator << (ostream& out, DATE& obj)
{
    out << "\nYear,Month,Day: " << obj.first << ", " << obj.second << ", " << obj.third << endl;
    return out;
}

ostream& operator << (ostream& out, Vector& obj)
{
    TRIAD** p = obj.pntr;
    if (p != nullptr)
    {
        for (int i = 0; i < obj.curr; ++i)
        {
            (*p)->Inc();
            cout << "override obj: " <<*p << endl;
            (*p)->Show();
            p++;
        }
    }
    else cout << "\nVector is empty\n";
    return out;
}
//

int main()
{
    srand(time(NULL));

    int choice;
    bool go = true;
    while (go)
    {
        cout << "It is the menu! Choose one of the labs below:\n\n";
        cout << "1. Lab 18.1\n2. Lab 18.2\n3. Lab 18.3\n4. Lab 18.4\n5. Lab 18.5\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            // creating an object with an external func
            Triangle triangle = Make_Triangle(1.2, 5.5);
            cout << "creating an object with an external func:\n";
            triangle.ShowSides();
            triangle.Hipotenuse();
            triangle.ShowHipotenuse();
            //

            // init object with Init()
            cout << "\ninit object with Init():\n";
            if (triangle.Init(1.5, 1.8))
            {
                triangle.ShowSides();
                triangle.Hipotenuse();
                triangle.ShowHipotenuse();
            }
            //

            // init object with Read()
            cout << "\ninit object with Read():\n";
            triangle.Read();
            triangle.ShowSides();
            triangle.Hipotenuse();
            triangle.ShowHipotenuse();
            //

            // massive with objects
            cout << "\nmassive with objects:\nEnter a size of an array:\n";
            int size;
            cin >> size;
            cout << endl;
            Triangle* obj_arr = new Triangle[size];

            for (int i = 0; i < size; ++i)
            {
                if (obj_arr[i].Init(0.153 * pow((i + 1), i + 2), 0.151 * pow((i + 2), i + 1)))
                {
                    obj_arr[i].ShowSides();
                    obj_arr[i].Hipotenuse();
                    obj_arr[i].ShowHipotenuse();
                    cout << endl;
                }
            }
            delete[] obj_arr;
            break;
        }

        case 2:
        {
            // 1 case of copy constr
            Exam woParams;
            Exam rus_lang("Arkipov Alex Alexeevich", "Russian", 5);
            Exam belorus_lang(rus_lang);
            cout << "\n1 case of copy constr:\n";
            cout << "rus_lang:\n";
            rus_lang.Show();
            cout << "\nbelorus_lang:\n";
            belorus_lang.Show();
            //

            // 2 case of copy constr
            cout << "\n2 case of copy constr:\n\nMake_Exam():\n";
            Exam deutch = Make_Exam();
            cout << "\ndeutch:\n";
            deutch.Show();
            //

            // 3 case of copy constr
            cout << "\n3 case of copy constr:\n\nPrint_Exam():\n";
            Print_Exam(rus_lang);
            cout << endl;
            //

            break;
        }
        case 3:
        {
            Money woParams;
            Money alotta(9100000, 56);
            cout << alotta;
            cin >> alotta;
            cout << alotta;

            Money much(105120,99);
            cout << much;
            alotta = much--;
            cout << "\nalotta = much--: " << alotta << endl;
            alotta = --much;
            cout << "\nalotta = --much: " << alotta << endl;
            
            cout << "\nalotta == much: " << (alotta == much) << endl;
            cout << "\nalotta != much: " << (alotta != much) << "\n\n";

            break;
        }
        case 4:
        {
            Triad nums;
            cin >> nums;
            cout << "\nnums: " << nums;
            Triad nums1(2001, 5, 18);
            cout <<"\nnums1: " << nums1;
            nums = nums1;
            cout << "\nnums = nums1: " << nums;

            Date bday;
            cin >> bday;
            cout << "\nbday: " << bday;

            // subs
            subs1(bday);
            nums = subs2();
            cout <<"\nnums: " << nums << endl;

            break;
        }
        case 5:
        {
            Vector vect(2);
            DATE bday(2001, 9, 5);
            cout << bday << "\nbday: " << &bday << endl;
            TRIAD* pntr = &bday;
            vect.Add(pntr);
            cout << vect;

            break;
        }
        
        default:
        {
            cout << "Such lab doesnt exist! Try again:\n\n";
        }
      
        }
        
        cout << "Continue? Enter 1 or 0: ";
        cin >> go;
        cout << endl;
    }
    
    


    return 0;
}
