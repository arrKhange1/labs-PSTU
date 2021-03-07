#include <iostream>
#include <string>
#include <time.h>
#include <list>
#include <iterator>
using namespace std;

struct HashEl
{
	string FIO;
	string birth;
	int pass;
	HashEl* next;
	bool NoElem;
	list<HashEl> lst;
};

string random_date(HashEl* arr)
{
	(*arr).birth = to_string(rand() % 2) + to_string(rand() % 9 + 1) + ".";
	if (rand() % 2 == 0) (*arr).birth += "0" + to_string(rand() % 9 + 1) + "." + to_string(rand() % 121 + 1900);
	else (*arr).birth += "1" + to_string(rand() % 3) + "." + to_string(rand() % 121 + 1900);
	return (*arr).birth;
}

void random_FIO(HashEl* arr)
{
	for (int j = 0; j < rand() % 4 + 2; j++)
	{
		if (j == 0) (*arr).FIO += toupper((char)(rand() % 26 + 97));
		else (*arr).FIO += (char)(rand() % 26 + 97);
	}
	(*arr).FIO += " ";
	for (int j = 0; j < rand() % 3 + 7; j++)
	{
		if (j == 0) (*arr).FIO += toupper((char)(rand() % 26 + 97));
		else (*arr).FIO += (char)(rand() % 26 + 97);
	}
}

void random_pass(HashEl* arr)
{
	(*arr).pass = rand() % 800001 + 100000;
}

int stringKeytointKey(string key)
{
	int res = 0;
	const int c = 15;
	for (int i = 0; i < key.length(); i++)
	{
		res += ((int)key[i] * pow(c, i)) / 1000000;
	}
	
	return res;
}

int HashFunc(int key, int arr_size)
{
	float A = 0.153;
	float k = key * A;
	return (int)(arr_size*(k - (int)(k)));
	
}

void IsMatch(HashEl* arr,int arr_len, string to_find)
{
	list <HashEl> ::iterator it;
	int cnt = 1; int list_counter = 1;
	int index = HashFunc(stringKeytointKey(to_find), arr_len) % arr_len;
	if (to_find == arr[index].birth && arr[index].lst.size() == 0)
	{
		cout << "(the only person) (" << index << " index) " << arr[index].birth << " " << arr[index].FIO << " " << arr[index].pass << endl;
	}
	else if (to_find == arr[index].birth || to_find != arr[index].birth)
	{
		bool nomatch = true;
		if (to_find == arr[index].birth)
		{
			nomatch = false;
			cout << cnt++ << ") (" << index << " index) " << arr[index].birth << " " << arr[index].FIO << " " << arr[index].pass << endl;
		}

		for (it = arr[index].lst.begin(); it != arr[index].lst.end(); it++)
		{
			if ((*it).birth == to_find)
			{
				nomatch = false;
				cout << cnt++ << ") (" << list_counter << " element in the LIST of the " << index << " index of array) " << (*it).birth << " " << (*it).FIO << " " << (*it).pass << endl;
			}
			list_counter++;
		}
		if (nomatch == true) cout << "No match :(\n";
		list_counter = 0;
	}
}

void PrintDataBase(HashEl*arr,int arr_len)
{
	cout << "\nThe whole array with its elements:\n======================================" << endl;
	list <HashEl> ::iterator it;
	int global_colls = 0; int local_colls = 0; int cnt_coll_index = 0;
	for (int i = 0; i < arr_len; i++)
	{
		if (arr[i].lst.size() != 0)
		{
			cout << i << " index: " << arr[i].birth << " " << arr[i].FIO << " " << arr[i].pass << "\t\tcollision on " << i << " index with:" << "\n";
			for (it = arr[i].lst.begin(); it != arr[i].lst.end(); it++)
			{
				cout << "\t\t\t\t\t\t" << (*it).birth << " " << (*it).FIO << " " << (*it).pass << endl;
				local_colls++;
			}
			if (local_colls != 0) cout << "\n\t\t\t\t\t\tindex " << i << " has " << local_colls << " local collisions\n\n";
		}
		else cout << i << " index: " << arr[i].birth << " " << arr[i].FIO << " " << arr[i].pass << endl;
		global_colls += local_colls;
		if (local_colls != 0) cnt_coll_index++;
		local_colls = 0;

	}
	cout << "=====================================";
	if (global_colls != 0) cout << "\nquantity of all collisions from " << cnt_coll_index << " indexes is " << global_colls << endl;
	else cout << "\nquantity of all collisions is zero\n";
}

void FillArray(HashEl* arr, int arr_len, int ElAmount)
{
	cout << "Elements with their custom indexes:\n\n";
	int index;
	for (int i = 0; i < ElAmount; i++)
	{
		HashEl* new_elem = new HashEl;
		random_FIO(new_elem);
		string date = random_date(new_elem);
		random_pass(new_elem);
		int keyInt = stringKeytointKey(date);
		index = (HashFunc(keyInt, arr_len)) % arr_len;
		cout << index << " index: " << new_elem->FIO << endl;
		if (arr[index].NoElem)
		{
			arr[index] = *new_elem;
			arr[index].NoElem = false;
		}
		else
		{
			arr[index].lst.push_back(*new_elem);
		}


		delete new_elem;
	}
}

int main()
{
	srand(time(NULL));

	int ElAmount = 100;
	int arr_len = 40;
	HashEl*arr = new HashEl[arr_len];

	FillArray(arr, arr_len, ElAmount);

	// DataBase with collision counting
	PrintDataBase(arr, arr_len);
	

	// string match
	cout << "\n\nenter a birth date u'd like to find: ";
	string birth_date;
	cin >> birth_date;
	IsMatch(arr, arr_len, birth_date);
	
	delete[] arr;
	return 0;
}
