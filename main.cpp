#include <iostream>
#include <string>
using namespace std;

struct Government
{
	string name;
	string gov_lang;
	string monetary_unit;
	int rate;
};
istream& operator >> (istream& ci, Government& arr)
{
	ci >> arr.name >> arr.gov_lang >> arr.monetary_unit >> arr.rate;
	return ci;
}
void gov_fill(Government* arr, int lenArr)
{
	cout << "вводи " << lenArr << " государства:\n";
	for (int i = 0; i < lenArr; i++)
	{
		cin >> arr[i];
	}
}

ostream& operator << (ostream& co, Government& arr)
{
	co << arr.name << " " << arr.gov_lang << " " << arr.monetary_unit << " " << arr.rate << endl;
	return co;
}




void gov_out(Government* arr, int lenArr)
{
	for (int i = 0; i < lenArr; i++)
	{
		cout << arr[i];
	}
}
void gov_elem_del(Government* arr, int& lenArr, string gov_num)
{
	for (int i = 0; i < lenArr; i++)
	{
		if (arr[i].name == gov_num)
		{
			for (int j = i + 1; j < lenArr; j++)
			{
				arr[j - 1].gov_lang = arr[j].gov_lang;
				arr[j - 1].name = arr[j].name;
				arr[j - 1].monetary_unit = arr[j].monetary_unit;
				arr[j - 1].rate = arr[j].rate;
			}
			lenArr--;
		}
	}
}











void gov_elem_add(Government* arr, int lenArr, Government* arr2, int lenArr2)
{
	int i = 0;
	for (; i < lenArr; i++)
	{
		arr2[i].gov_lang = arr[i].gov_lang;
		arr2[i].rate = arr[i].rate;
		arr2[i].name = arr[i].name;
		arr2[i].monetary_unit = arr[i].monetary_unit;

	}
	for (int j = lenArr; j < lenArr2; j++)
	{
		cin >> arr2[j];
	}

}



















int main()s
{
	system("color F0");
	setlocale(LC_ALL, "Rus");
	int gov_num;
	cout << "enter an amount of govs: ";
	cin >> gov_num;

	Government* gov_arr = new Government[gov_num];
	gov_fill(gov_arr, gov_num);
	cout << endl;
	gov_out(gov_arr, gov_num);
	cout << endl;

	string del_name;
	cout << "введите страну для удаления: ";
	cin >> del_name;
	cout << endl;

	gov_elem_del(gov_arr, gov_num, del_name);
	gov_out(gov_arr, gov_num);
	cout << endl;

	cout << "введите еще 2 государства для добавления в конец:\n";
	Government* arr_helper = new Government[gov_num + 2];
	gov_elem_add(gov_arr, gov_num, arr_helper, gov_num + 2);
	delete[]gov_arr;
	cout << endl;

	gov_out(arr_helper, gov_num + 2);

	delete[]arr_helper;


	return 0;
}