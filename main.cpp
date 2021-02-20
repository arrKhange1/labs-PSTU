#include <iostream>
#include <list>
#include <iterator>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	list <char> DoubleDirList;
	list <char> ::iterator it;
	int ListLen;
	char elem_after_add;
	cout << "enter elem_after_del: ";
	cin >> elem_after_add;
	cout << "enter ListLen: ";
	cin >> ListLen;
	cout << "enter elems:\n";
	int cnt = 1;
	for (int i = 0; i < ListLen; i++)
	{
		char elem;
		cout << cnt++ << ") ";
		cin >> elem;
		DoubleDirList.push_back(elem);
		if (elem == elem_after_add) DoubleDirList.push_back('B');
	}
	cout << endl;
	
	cout << "Добавление после " << elem_after_add << " с начала:\n\n";
	cnt = 1;
	for (it = DoubleDirList.begin(); it != DoubleDirList.end(); it++)
	{
		cout << cnt++ << ") " << (*it) << "\n";
	}

	DoubleDirList.reverse();
	cout << "\nДобавление после " << elem_after_add << " с конца:\n";

	for (it = DoubleDirList.begin(); it != DoubleDirList.end(); it++)
	{
		if ((*it == elem_after_add)) DoubleDirList.insert(it, 'E');
	}

	cout << endl;
	cnt = 1;
	for (it = DoubleDirList.begin(); it != DoubleDirList.end(); it++)
	{
		cout << cnt++ << ") " << (*it) << "\n";
	}

	DoubleDirList.clear();
	return 0;
}