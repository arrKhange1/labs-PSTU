// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <iterator>
#include <functional>
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
    out << "Balance: " << obj.rub << "." << obj.cent << endl;
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
    out << "\nFirst,Second,Third: " << obj.first << ", " << obj.second << ", " << obj.third << endl;
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
            cout << "override obj: " << *p << endl;
            (*p)->Show();
            p++;
        }
    }
    else cout << "\nVector is empty\n";
    return out;
}
//

 //for lab 18.10


void infile(ofstream& f)
{
    Money obj;
    cin >> obj;
    f.write(reinterpret_cast<char*>(&obj), sizeof(Money));
}

void PrintSequence(ifstream& infile)
{
    Money temp;
    while (infile.read(reinterpret_cast<char*>(&temp), sizeof(Money)))
    {
        cout << temp << endl;
    }
}

void Insert(ifstream& infile, int K, int pos, int len)
{
    ofstream outfile("help_test.txt");

    Money obj_pos;
    Money temp;
    int i = 1;
    while (infile.read(reinterpret_cast<char*>(&temp), sizeof(Money)))
    {
        if (i <= pos)
        {
            outfile.write(reinterpret_cast<char*>(&temp), sizeof(Money));
        }

        else
        {
            if (i == pos + 1)
            {
                for (int i = 0; i < K; ++i)
                {
                    cout << "\nEnter " << i + 1 << " object: "; cin >> obj_pos;
                    outfile.write(reinterpret_cast<char*>(&obj_pos), sizeof(Money));
                }
            }
            outfile.write(reinterpret_cast<char*>(&temp), sizeof(Money));
        }

        // pos = len(file)
        if (pos == len && i == pos)
            for (int i = 0; i < K; ++i)
            {
                cout << "\nEnter " << i + 1 << " object: "; cin >> obj_pos;
                outfile.write(reinterpret_cast<char*>(&obj_pos), sizeof(Money));
            }
        ++i;
    }
    i = 1;
    outfile.close();
}

void Delete(ifstream& infile, Money& somuch)
{
    ofstream outfile("woDeleted.txt");
    Money temp;
    while (infile.read(reinterpret_cast<char*>(&temp), sizeof(Money)))
    {
        if (!(temp > somuch)) outfile.write(reinterpret_cast<char*>(&temp), sizeof(Money));
    }
    outfile.close();
}

void Increase(ifstream& infile, Money& somuch)
{
    ofstream outfile("increased_values.txt");
    Money temp;
    while (infile.read(reinterpret_cast<char*>(&temp), sizeof(Money)))
    {
        if (temp == somuch)
        {
            temp + 101.04;
        }
        outfile.write(reinterpret_cast<char*>(&temp), sizeof(Money));
    }
    outfile.close();
}

//

// for 18.11

template <class T>
void PrintVect(vector<T>& vect)
{
    for (int i = 0; i < vect.size(); ++i) cout << vect[i] << " ";
}

void MakeVec(vector<float>& vectFl, int len)
{
    for (int i = 0; i < len; ++i)
    {
        vectFl.push_back(7.6 + (50 - rand() % 101) + i / 4.2);
    }
}

float SredArifm(vector<float>& v)
{
    float sred_arifm = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        sred_arifm += (v[i] / (float)v.size());
    }
    cout << "\nSred_Arifm = " << sred_arifm << "\n\n";
    return sred_arifm;
}

float SredArifm(vector<Money>& v)
{
    float sred_arifm_m = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        sred_arifm_m += stof(to_string(v[i].GetRub()) + "." + to_string(v[i].GetCent())) / (float)v.size();
    }
    cout << "\nSred_Arifm = " << sred_arifm_m << "\n\n";
    return sred_arifm_m;
}

void MakeVec(vector<Money>& mv, int len)
{
    for (int i = 0; i < len; ++i)
    {
        Money temp(rand() % 500, rand() % 100);
        mv.push_back(temp);
    }
}

float FindMin(vector<float>& vectFl)
{
    float min = vectFl[0];
    for (int i = 0; i < vectFl.size(); ++i)
    {
        if (vectFl[i] < min) min = vectFl[i];
    }
    cout << "\nMin: " << min << "\n\n";
    return min;
}

Money FindMin(vector<Money>& mv)
{
    Money money_min = mv[0];
    for (int i = 0; i < mv.size(); ++i)
    {
        if (!(mv[i] > money_min)) money_min = mv[i];
    }
    cout << "\nMin Money: " << money_min << endl;
    return money_min;
}

void DelFromVec(vector<float>& vectFl, float sr_arifm_fl)
{
    int k = 0;
    while (k < vectFl.size())
    {
        if (vectFl[k] > sr_arifm_fl)
        {
            vectFl.erase(vectFl.begin() + k);
        }
        else ++k;
    }
}

void DelFromVec(vector<Money>& mv, float sred_arifm_m)
{
    int i = 0;
    Money sred_arifm1;
    sred_arifm1.SetRub((int)sred_arifm_m); sred_arifm1.SetCent((sred_arifm_m - (int)sred_arifm_m) * 100);
    while (i < mv.size())
    {
        if (mv[i] > sred_arifm1)
        {
            mv.erase(mv.begin() + i);

        }
        else ++i;
    }
}

float FindMax(vector<float>& vectFl)
{
    float maxim = vectFl[0];
    for (int i = 0; i < vectFl.size(); ++i)
    {
        if (vectFl[i] > maxim) maxim = vectFl[i];
    }
    cout << "\n\nMax: " << maxim << endl;
    return maxim;
}

Money FindMax(vector<Money>& mv)
{
    Money money_max = mv[0];
    for (int i = 0; i < mv.size(); ++i)
    {
        if (mv[i] > money_max) money_max = mv[i];
    }
    cout << "\nMoney Max: " << money_max << endl;
    return money_max;
}

void MultByMaxInVec(vector<float>& vectFl, float max_fl)
{
    for (int i = 0; i < vectFl.size(); ++i)
    {
        vectFl[i] *= max_fl;
    }
}

void MultByMaxInVec(vector<Money>& mv, Money money_max)
{
    float moneymax = stof(to_string(money_max.GetRub()) + "." + to_string(money_max.GetCent()));
    float multiple = 1;
    for (int i = 0; i < mv.size(); ++i)
    {
        multiple = moneymax * stof(to_string(mv[i].GetRub()) + "." + to_string(mv[i].GetCent()));
        mv[i].SetRub((int)multiple);
        mv[i].SetCent((multiple - (int)multiple) * 100);
    }
}

// ADAPTER (TASK 4)

vector<Money> queue_to_vector(priority_queue<Money> q)
{
    vector<Money> v;
    while (!q.empty())
    {
        v.push_back(q.top());
        q.pop();
    }
    return v;
}

priority_queue<Money> vector_to_queue(vector<Money> v)
{
    priority_queue<Money> q;
    for (int i = 0; i < v.size(); ++i)
    {
        q.push(v[i]);
    }
    return q;
}

void MakeQueue(priority_queue<Money>& q, int len)
{
    for (int i = 0; i < len; ++i)
    {
        Money temp(rand() % 500, rand() % 100);
        q.push(temp);
    }
}

void PrintQueue(priority_queue<Money>& q)
{

    vector<Money> v1 = queue_to_vector(q);
    while (!q.empty())
    {
        Money temp = q.top();
        cout << temp << " ";
        q.pop();
    }
    q = vector_to_queue(v1);
}

Money QueueMin(priority_queue<Money>& MoneyPriora)
{
    vector<Money> v1 = queue_to_vector(MoneyPriora);
    Money min_queue;
    int k = MoneyPriora.size();
    while (!MoneyPriora.empty())
    {
        if (k == 1)
        {
            min_queue = MoneyPriora.top();
        }
        MoneyPriora.pop();
        --k;
    }
    cout << endl << min_queue << endl;
    MoneyPriora = vector_to_queue(v1);
    return min_queue;
}

void QueueInsert(priority_queue<Money>& MoneyPriora, int pos)
{
    vector<Money> v1 = queue_to_vector(MoneyPriora);
    v1.insert(v1.begin() + (pos - 1), QueueMin(MoneyPriora));
    cout << endl << "\nInsertion on a vector's position\n";
    PrintVect(v1);
    cout << endl;
    MoneyPriora = vector_to_queue(v1);
}

float QueueSredArifm(priority_queue<Money>& MoneyPriora)
{
    vector<Money> v1 = queue_to_vector(MoneyPriora);
    int l = MoneyPriora.size();
    float sred_arifm_m = 0;
    while (!MoneyPriora.empty())
    {
        Money temp = MoneyPriora.top();
        sred_arifm_m += stof(to_string(temp.GetRub()) + "." + to_string(temp.GetCent())) / (float)l;
        MoneyPriora.pop();
    }
    cout << "\nSred Arifm: " << sred_arifm_m << endl;
    MoneyPriora = vector_to_queue(v1);
    return sred_arifm_m;
}

void QueueDel(priority_queue<Money>& MoneyPriora, float sred_arifm_m)
{
    vector<Money> v1;
    Money sred_arifm;
    sred_arifm.SetRub((int)sred_arifm_m); sred_arifm.SetCent((sred_arifm_m - (int)sred_arifm_m) * 100);
    while (!MoneyPriora.empty())
    {
        Money temp = MoneyPriora.top();
        if (!(temp > sred_arifm)) v1.push_back(temp);
        MoneyPriora.pop();
    }
    MoneyPriora = vector_to_queue(v1);
}

void QueueMultByMax(priority_queue<Money>& MoneyPriora, Money& money_max)
{
    vector<Money> v1;
    float moneymax = stof(to_string(money_max.GetRub()) + "." + to_string(money_max.GetCent()));
    float multiple = 1;
    while (!MoneyPriora.empty())
    {
        Money temp = MoneyPriora.top();
        multiple = moneymax * stof(to_string(temp.GetRub()) + "." + to_string(temp.GetCent()));
        temp.SetRub((int)multiple); temp.SetCent((multiple - (int)multiple) * 100);
        v1.push_back(temp);
        MoneyPriora.pop();
    }
    MoneyPriora = vector_to_queue(v1);
}


//

// 18.12

void MakeMap(multimap<int, float>& mfl)
{
    cout << "\nEnter a size of multimap: "; int len; cin >> len; cout << endl;
    for (int i = 0; i < len; ++i)
    {
        mfl.insert(make_pair(rand() % 10, 7.6 + (50 - rand() % 101) + i / 4.2));
    }
}

void MakeMap(multimap<int, Money>& mM)
{
    cout << "\nEnter a size of multimap: "; int len; cin >> len; cout << endl;
    for (int i = 0; i < len; ++i)
    {
        Money temp(rand() % 500, rand() % 100);
        mM.insert(make_pair(rand() % 10, temp));
    }
}

void PrintMap(multimap<int, float>& mfl)
{
    for (multimap<int, float>::iterator mflIt = mfl.begin(); mflIt != mfl.end(); ++mflIt)
    {
        cout << "\nKey: " << mflIt->first << "\nParam: " << mflIt->second;
    }
    cout << endl;
}

void PrintMap(multimap<int, Money>& mM)
{
    for (multimap<int, Money>::iterator mMIt = mM.begin(); mMIt != mM.end(); ++mMIt)
    {
        cout << "\nKey: " << mMIt->first << "\nParam: " << mMIt->second;
    }
}

float MinMap(multimap<int, float>& mfl)
{
    float minFl = mfl.begin()->second;
    for (multimap<int, float>::iterator mflIt = mfl.begin(); mflIt != mfl.end(); ++mflIt)
    {
        if (mflIt->second < minFl) minFl = mflIt->second;
    }
    cout << "\nMin: " << minFl << endl;
    return minFl;
}

Money MinMap(multimap<int, Money>& mM)
{
    Money money_min = mM.begin()->second;
    for (multimap<int, Money>::iterator mMIt = mM.begin(); mMIt != mM.end(); ++mMIt)
    {
        if (mMIt->second < money_min) money_min = mMIt->second;
    }
    cout << "\nMin: " << money_min << endl;
    return money_min;
}

float SredArifmMap(multimap<int, float>& mfl)
{
    float sred_arifm = 0;
    for (multimap<int, float>::iterator mflIt = mfl.begin(); mflIt != mfl.end(); ++mflIt)
    {
        sred_arifm += mflIt->second;
    }
    sred_arifm /= (float)mfl.size();
    cout << "\nSred Arifm: " << sred_arifm << endl;
    return sred_arifm;
}

float SredArifmMap(multimap<int, Money>& mM)
{
    float sred_arifm_m = 0;
    for (multimap<int, Money>::iterator mMIt = mM.begin(); mMIt != mM.end(); ++mMIt)
    {
        sred_arifm_m += stof(to_string(mMIt->second.GetRub()) + "." + to_string(mMIt->second.GetCent())) / (float)mM.size();
    }
    cout << "\nSred_Arifm = " << sred_arifm_m << "\n\n";
    return sred_arifm_m;
}

void DelMap(multimap<int, float>& mfl)
{
    cout << "\nAfter Del > Sred Arifm\n";
    float sred_arifm = SredArifmMap(mfl);
    for (multimap<int, float>::iterator mflIt = mfl.begin(); mflIt != mfl.end(); )
    {
        if (mflIt->second > sred_arifm)
        {
            mfl.erase(mflIt++);
        }
        else ++mflIt;
    }
}

void DelMap(multimap<int, Money>& mM)
{
    cout << "\nAfter Del > Sred Arifm\n";
    float sred_arifm_m = SredArifmMap(mM);
    Money sred_arifm1;
    sred_arifm1.SetRub((int)sred_arifm_m); sred_arifm1.SetCent((sred_arifm_m - (int)sred_arifm_m) * 100);
    for (multimap<int, Money>::iterator mMIt = mM.begin(); mMIt != mM.end();)
    {
        if (mMIt->second > sred_arifm1) mM.erase(mMIt++);
        else ++mMIt;
    }
}

float MaxMap(multimap<int, float>& mfl)
{
    float maxFl = mfl.begin()->second;
    for (multimap<int, float>::iterator mflIt = mfl.begin(); mflIt != mfl.end(); ++mflIt)
    {
        if (mflIt->second > maxFl) maxFl = mflIt->second;
    }
    cout << "\nMax: " << maxFl << endl;
    return maxFl;
}

Money MaxMap(multimap<int, Money>& mM)
{
    Money money_max = mM.begin()->second;
    for (multimap<int, Money>::iterator mMIt = mM.begin(); mMIt != mM.end(); ++mMIt)
    {
        if (mMIt->second > money_max) money_max = mMIt->second;
    }
    cout << "\nMax: " << money_max << endl;
    return money_max;
}

void MultByMaxMap(multimap<int, float>& mfl)
{
    cout << "\nAfter MultByMax\n";
    float maxFl = MaxMap(mfl);
    for (multimap<int, float>::iterator mflIt = mfl.begin(); mflIt != mfl.end(); ++mflIt)
    {
        mflIt->second *= maxFl;
    }
}

void MultByMaxMap(multimap<int, Money>& mM)
{
    cout << "\nAfter MultBymax\n";
    Money money_max = MaxMap(mM);
    float moneymax = stof(to_string(money_max.GetRub()) + "." + to_string(money_max.GetCent()));
    float multiple = 1;
    for (multimap<int, Money>::iterator mMIt = mM.begin(); mMIt != mM.end(); ++mMIt)
    {
        multiple = moneymax * stof(to_string(mMIt->second.GetRub()) + "." + to_string(mMIt->second.GetCent()));
        mMIt->second.SetRub((int)multiple);
        mMIt->second.SetCent((multiple - (int)multiple) * 100);
    }
}

//

// 18.13
void Mult(Money maxim, Money& elem)
{
    elem.SetRub(1);
}

int main()
{
    srand(time(NULL));

    int choice;
    bool go = true;
    while (go)
    {
        cout << "It is the menu! Choose one of the labs below:\n\n";
        cout << "1. Lab 18.1\n2. Lab 18.2\n3. Lab 18.3\n4. Lab 18.4\n5. Lab 18.5\n6(7). Lab 18.6\n8. Lab 18.8\n9. Lab 18.9\n10. Lab 18.10\n11. Lab 18.11\n12. Lab 18.12\n\n";
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

            Money much(105120, 1);
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
            cout << "\nnums1: " << nums1;
            nums = nums1;
            cout << "\nnums = nums1: " << nums;

            Date bday;
            cin >> bday;
            cout << "\nbday: " << bday;

            // subs
            subs1(bday);
            nums = subs2();
            cout << "\nnums: " << nums << endl;

            break;
        }
        case 5:
        {
            Vector vect(2);
            DATE bday(2001, 9, 5);
            cout << bday << "\nbday: " << &bday << endl;
            TRIAD* pntr = &bday;
            vect.Add();
            cout << vect;

            break;
        }

        case 6:
        {
            // also for 18.7
            Set<double> set1(5);
            cout << "\nSet1: " << set1 << endl;
            Set<double> set2(10);
            cout << "\nSet2: " << set2 << endl;
            Set<double> set3;
            set3 = set1 - set2;
            cout << "\nSet3: " << set3 << endl;
            cout << "\nSet3[1]: " << set3[1] << endl;
            set3[1] = 43345455;
            cout << "\nSet3: " << set3 << endl;
            cout << "\nLength of Set1: " << set1() << endl;

            cout << "\n\n";

            break;
        }

        case 8:
        {
            Dialog EventMenu;
            EventMenu.Execute();

            break;
        }

        case 9:
        {
#define FIRST_VARIANT 0
#define SECOND_VARIANT 1

#if FIRST_VARIANT == 1 // 1st variant of realization

            cout << "\n\n--1ST VARIANT--\n\n";
            // проверка на превышение определенной МАКС. длины массива
            try { Set<double> set1(25); }
            catch (int& exc) { cout << "\nSize > MAX_SIZE\n"; }

            // проверка на пустой вывод
            try
            {
                Set<double> set1;
                cout << "\nSet1: " << set1 << endl;
            }
            catch (int& exc) { cout << "\nNothing to be printed!\n"; }

            // проверка на вычитание пустого множества или вычитание из пустого множества
            try
            {
                Set<double> set1(5);
                Set<double> set2;

                if (set1() == 0 && set2() > 0) cout << "\nSet1: Void\n\nSet2: " << set2 << endl;
                else if (set1() > 0 && set2() == 0) cout << "\nSet1: " << set1 << "\nSet2: Void\n";

                Set<double> set3;
                set3 = set1 - set2;
                cout << endl << set1 << endl << set2 << endl << set3 << endl;
            }
            catch (int& exc)
            {
                if (exc == 6) cout << "\nSets can't be differed > Set1 is empty\n";
                else if (exc == 7) cout << "\nSets can't be differed > Set2 is empty\n";
            }

            // проверка на задание индекса в диапазоне 0 <= i < size
            try
            {
                Set<double> set1(5);
                cout << "\nSet1: " << set1[-1] << endl;
            }
            catch (int& exc)
            {
                if (exc == 2) cout << "\nIndex >= Size\n";
                else if (exc == 3) cout << "\nIndex < 0\n";
            }

            // проверка на удаление элемента из УЖЕ пустого множества
            try
            {
                Set<double> set1;
                set1.Del();
            }
            catch (int& exc) { cout << "\nNothing to be deleted!\n"; }

            cout << "\n\n";

#elif SECOND_VARIANT == 1 // 2nd variant of realization

            cout << "\n\n--2ND VARIANT--\n\n";
            // проверка на превышение определенной МАКС. длины массива
            try { Set<double> set1(25); }
            catch (Error err) { err.PrintError(); }

            // проверка на пустой вывод
            try
            {
                Set<double> set1;
                cout << "\nSet1: " << set1 << endl;
            }
            catch (Error err) { err.PrintError();; }

            // проверка на вычитание пустого множества или вычитание из пустого множества
            try
            {
                Set<double> set1;
                Set<double> set2(10);

                if (set1() == 0 && set2() > 0) cout << "\nSet1: Void\n\nSet2: " << set2 << endl;
                else if (set1() > 0 && set2() == 0) cout << "\nSet1: " << set1 << "\n\nSet2: Void\n";

                Set<double> set3;
                set3 = set1 - set2;
            }
            catch (Error err)
            {
                err.PrintError();
            }

            // проверка на задание индекса в диапазоне 0 <= i < size
            try
            {
                Set<double> set1(5);
                cout << "\nSet1: " << set1[5] << endl;
            }
            catch (Error err)
            {
                err.PrintError();
            }

            // проверка на удаление элемента из УЖЕ пустого множества
            try
            {
                Set<double> set1;
                set1.Del();
            }
            catch (Error err) { err.PrintError(); }

            cout << "\n\n";


#endif

            break;
        }

        case 10:
        {

            // fill sequence
            ofstream outfile("test.txt");
            cout << "\nEnter a quantity of objects: ";
            int n; cin >> n;
            for (int i = 0; i < n; ++i)
            {
                infile(outfile);
            }
            outfile.close();


            // PrintSequence
            ifstream infile("test.txt");
            PrintSequence(infile);
            infile.close();

            // insertion K elements
            cout << "\nEnter a position to insert K objects after: "; int pos; cin >> pos; cout << endl << "Enter K: "; int K; cin >> K; cout << endl;
            infile.open("test.txt");
            Insert(infile, K, pos, n);
            infile.close();

            // PrintSequence
            infile.open("help_test.txt");
            PrintSequence(infile);
            infile.close();
            //

            // delete

            infile.open("help_test.txt");
            Money somuch;
            cout << "\nEnter a definite object: "; cin >> somuch; cout << endl;

            Delete(infile, somuch);

            infile.close();

            // PrintSequence
            infile.open("woDeleted.txt");
            PrintSequence(infile);
            infile.close();

            // file rename
            remove("help_test.txt");
            cout << rename("woDeleted.txt", "help_test.txt") << endl;
            //

            // increasing values

            infile.open("help_test.txt");

            cout << "\nEnter a value which should be increased "; cin >> somuch; cout << endl;
            Increase(infile, somuch);

            infile.close();

            // PrintSequence
            infile.open("increased_values.txt");
            PrintSequence(infile);
            infile.close();

            // file rename
            remove("help_test.txt");
            cout << rename("increased_values.txt", "help_test.txt") << endl;
            //

            break;
        }

        case 11:
        {

            // FLOAT VEC done

            typedef vector<float> VectorFl;
            VectorFl vectFl;

            // making a vector
            int len_vectorFl;
            cout << "\nEnter length of a vector: "; cin >> len_vectorFl;
            MakeVec(vectFl, len_vectorFl);
            PrintVect(vectFl);
            cout << "\n\n";

            // add min elem on a position
            int pos; cout << "Enter a position to insert an element there: "; cin >> pos;
            vectFl.insert(vectFl.begin() + (pos - 1), FindMin(vectFl));
            //
            cout << "\nAfter insertion\n";
            PrintVect(vectFl);

            // del elems
            cout << "\n\nAfter Del Elems\n";
            DelFromVec(vectFl, SredArifm(vectFl));
            cout << endl;
            //
            PrintVect(vectFl);

            // multiplying by max elem
            float max_fl = FindMax(vectFl);
            MultByMaxInVec(vectFl, max_fl);

            cout << "\n\nResult: ";
            PrintVect(vectFl);
            cout << "\n\n";

            // FLOAT VEC done

            // PARAM CLASS VECTOR done // 

            cout << "\n\nParam class\n\n";
            Vect<int> v(len_vectorFl);
            v.Print();
            //
            cout << "\nEnter a position to insert an element there: "; cin >> pos;
            v.AddMin(pos, v.Min());
            cout << endl << "After insertion of Min elem:\n";
            v.Print();
            //
            v.Del(v.SredArifm());
            cout << endl << "After Del elems > SredArifm:\n";
            v.Print();
            //
            v.MultByMax(v.Max());
            cout << endl << "MultbyMax:\n";
            v.Print();
            // PARAM CLASS VECTOR done //

            // VECT TYPE MONEY done //
            cout << "\n\nVECT TYPE MONEY\n\n";

            typedef vector<Money> MoneyVec;
            MoneyVec mv;

            // make vec
            MakeVec(mv, len_vectorFl);
            PrintVect(mv);
            cout << endl;
            //

            // add min on pos
            cout << "\nEnter a position to insert an element there: "; cin >> pos;
            mv.insert(mv.begin() + (pos - 1), FindMin(mv));
            cout << "\nAfter Insertion\n";
            PrintVect(mv);
            cout << endl;

            // del > sr arifm
            cout << "\nAfter Del Elems\n";
            DelFromVec(mv, SredArifm(mv));
            PrintVect(mv);
            cout << endl;
            //

            // mult all by money max
            cout << "After Mult all by Money Max\n";
            Money money_max = FindMax(mv);
            MultByMaxInVec(mv, money_max);

            PrintVect(mv);
            cout << endl;

            // VECT TYPE MONEY done //

            // ADAPTER (TASK 4) PRIORITY_QUEUE done
            cout << "\n\nADAPTER (TASK 4) PRIORITY_QUEUE\n\n";


            priority_queue<Money> MoneyPriora;
            vector<Money> v1;

            // make queue
            MakeQueue(MoneyPriora, len_vectorFl);
            // print queue
            PrintQueue(MoneyPriora);
            //

            // Insertion of min elem
            cout << "\nEnter a position to insert an element there: "; cin >> pos;
            QueueInsert(MoneyPriora, pos);
            //

            // print queue
            cout << "\nInsertion in a queue\n";
            PrintQueue(MoneyPriora);
            //

            // Del > Sred Arifm
            QueueDel(MoneyPriora, QueueSredArifm(MoneyPriora));
            //

            // print queue
            cout << "\nAfter Del > Sred Arifm\n";
            PrintQueue(MoneyPriora);
            //

            // Max Elem
            money_max = MoneyPriora.top();
            cout << "\nMax Elem: " << money_max << endl;
            //

            // MultByMax
            QueueMultByMax(MoneyPriora, money_max);
            //

            // print queue
            cout << "\nAfter MultByMax\n";
            PrintQueue(MoneyPriora);
            //

            // ADAPTER (TASK 4) PRIORITY_QUEUE done

            // ADAPTER (TASK 5) done
            cout << "\n\nADAPTER (TASK 5) PRIORITY_QUEUE\n\n";

            // make queue
            PrioQueue<double> qq(len_vectorFl);
            qq.Print();
            //

            // Add Min
            cout << "\nEnter a position to insert an element there: "; cin >> pos;
            qq.AddMin(pos, qq.Min());
            cout << "\nInsertion in a queue\n";
            qq.Print();
            //

            // Del > Sred Arifm
            qq.Del(qq.SredArifm());
            cout << "\nAfter Del > Sred Arifm\n";
            qq.Print();
            //

            // MultByMax
            qq.MultByMax(qq.Max());
            cout << "\nAfter MultByMax\n";
            qq.Print();
            //

            // ADAPTER (TASK 5) done





            break;
        }

        case 12:
        {
            // multimap FLOAT done
            cout << "\n\nmultimap FLOAT\n\n";

            typedef multimap<int, float> mmFl;
            mmFl mfl;

            // make map
            MakeMap(mfl);
            //

            // print
            PrintMap(mfl);
            //

            // Insertion on a pos
            cout << "\nEnter a position to insert an element there: "; int pos; cin >> pos; cout << "\nAfter Insertion on a position\n";
            mfl.insert(make_pair(pos, MinMap(mfl)));
            //

            // print
            PrintMap(mfl);
            //

            // Del > Sred Arifm
            DelMap(mfl);
            //

            // print
            PrintMap(mfl);
            //

            // MultByMax
            MultByMaxMap(mfl);
            //

            // print
            PrintMap(mfl);
            //

            // multimap FLOAT done

            // multimap MONEY done
            cout << "\n\nmultimap MONEY\n\n";

            typedef multimap<int, Money> mmMoney;
            mmMoney mM;

            // make multimap
            MakeMap(mM);
            //

            // print
            PrintMap(mM);
            //

            // Insertion on a pos
            cout << "\nEnter a position to insert an element there: "; cin >> pos; cout << "\nAfter Insertion on a position\n";
            mM.insert(make_pair(pos, MinMap(mM)));
            //

            // print 
            PrintMap(mM);
            //

            // Del > Sred Arifm
            DelMap(mM);
            //

            // print 
            PrintMap(mM);
            //

            // MultByMax
            MultByMaxMap(mM);
            //

            // print
            PrintMap(mM);
            //

            // multimap MONEY done

            // multimap PARAM CLASS done
            cout << "\n\nmultimap PARAM CLASS\n\n";

            // make map
            Multimap<int> mapa(5);
            //

            // print
            mapa.Print();
            //

            // add min
            cout << "\n\nEnter a position to insert an element there: "; cin >> pos; cout << "\nAfter Insertion on a position\n";
            mapa.AddMin(pos, mapa.Min());
            //

            // print
            mapa.Print();
            //

            // Del > Sred Arifm
            mapa.Del(mapa.SredArifm());
            //

            // print
            mapa.Print();
            //

            // MultByMax
            mapa.MultByMax(mapa.Max());
            //

            // print
            mapa.Print();
            //

            // multimap PARAM CLASS done

            break;
        }

        case 13:
        {
            typedef vector<Money> MoneyVec;
            MoneyVec vec;
            int len; cout << "\nEnter a length of a vector: "; cin >> len; cout << endl;
            // make vec
            for (int i = 0; i < len; ++i)
            {
                Money temp(rand() % 500, rand() % 100);
                vec.push_back(temp);
            }
            //

            // print
            for (int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
            cout << endl;
            //

            // Min elem
            MoneyVec::iterator it_min = min_element(vec.begin(), vec.end());
            cout << "\nMin Elem: " << *it_min << endl;
            //

            // Replace with Min 
            int pos; cout << "\nEnter a pos: "; cin >> pos;
            replace(vec.begin() + (pos - 1), vec.begin() + pos, *(vec.begin() + (pos - 1)), *it_min);
            cout << endl;
            //

            // print
            for (int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
            cout << endl;
            //

            // Remove if > Sred Arifm ((remove_if doesnt delete elems. it moves them to the end of a container and returns iterator on the first pointer of deleting elements)
            float sred_ar = SredArifm(vec);
            Money sr_ar;
            sr_ar.SetRub((int)sred_ar); sr_ar.SetCent((sred_ar - (int)sred_ar) * 100);

            MoneyVec::iterator it = vec.begin();
            vec.erase(remove_if(it, it + vec.size(), bind2nd(greater<Money>(), sr_ar)), vec.end());
            //

            // print
            for (int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
            cout << endl;
            //

            // Max Elem
            MoneyVec::iterator max_it = max_element(vec.begin(), vec.end());
            cout << "\nMax Element: " << *max_it << endl;
            //

            // MultByMax // dodelat
            it = vec.begin();
            for_each(it, it + vec.size(), [max_it](Money& t){t.SetRub((t.GetRub()*100+t.GetCent())); });
            //
            
            // print
            for (int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
            cout << endl;
            //


            break;
        }

        default:
        {
            cout << "Such lab doesnt exist! Try again:\n\n";
        }

        }

        cout << "\n\nContinue? Enter 1 or 0: ";
        cin >> go;
        cout << endl;
    }




    return 0;
}
