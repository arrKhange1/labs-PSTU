#include <iostream>
#include <string>
using namespace std;


void pop(string*& arr, int& size, int index)
{
	size--;
	int j = 0;
	string* new_arr = new string[size];
	for (int i = 0; i < size+1; i++)
	{

		if (i != index)
		{
			new_arr[j] = arr[i];
			j++;
		}
	}
	delete[] arr;
	arr = new_arr;
}

void arr_print(string* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << " element of the massive = " << arr[i] << endl;
	}
}

void arr_fill(string* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "enter a string: ";
		getline(cin, arr[i]);
		while (arr[i] == "")
		{
			getline(cin, arr[i]);
		}
	}
}

int main()
{
	int size;
	cout << "enter a size of a massive: ";
	cin >> size;
	string* arr = new string[size];

	arr_fill(arr,size);
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (arr[i][0] == arr[i][arr[i].length() - 1] && (!isdigit(arr[i][0]) && !isdigit(arr[i][arr[i].length() - 1])))
		{
			pop(arr, size, i);
			
		}
	}

	arr_print(arr,size);

	delete[] arr;
	return 0;
}
