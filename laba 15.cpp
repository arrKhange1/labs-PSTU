#include <iostream>
#include <string>
#include <time.h>
using namespace std;

struct Lake
{
	string name;
	float sq;
};

istream& operator >> (istream& ci, Lake& structure)
{
	cout << "Name of the Lake: ";
	ci >> structure.name;
	cout << "Square of the Lake: ";
	ci >> structure.sq;
	cout << endl;
	return ci;
}

ostream& operator << (ostream& co, Lake& structure)
{
	cout << structure.name << " " << structure.sq << "\n\n";
	return co;
}

void QuickSort(Lake* arr, int left, int right)
{
	int i = left, j = right;
	Lake temp; int barrier = arr[(left + right) / 2].sq;

	while (i <= j)
	{
		while (arr[i].sq > barrier) i++;
		while (arr[j].sq < barrier) j--;

		if (i <= j)
		{
			if (arr[i].sq < arr[j].sq)
			{
				temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
			}

			i++; j--;
		}

	};

	if (left < j) qsort(arr, left, j);
	if (i < right) qsort(arr, i, right);
}

void ShellSort(Lake*arr, int len) 
{
	int j, d; Lake temp;
	d = len / 2;
	while (d > 0)
	{
		for (int i = 0; i < len - d; i++)
		{
			j = i;
			while (j >= 0 && arr[j].sq < arr[j + d].sq)
			{
				temp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = temp;
				j--;
			}
		}
		d = d / 2;
	}
	
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	int LakeAmount;
	cout << "Enter Amount of Lakes: ";
	cin >> LakeAmount;
	cout << "\n\n";
	Lake* arr = new Lake[LakeAmount];
	
	cout << "Enter name of a lake and its square:\n\n";
	for (int i = 0; i < LakeAmount; i++)
	{
		cout << "The Lake #" << i + 1 << ":\n";
		cin >> arr[i];
	}

	cout << endl;
	for (int i = 0; i < LakeAmount; i++)
	{
		cout << "The Lake #" << i+1 << ":" << endl << arr[i];
	}

	cout << "Change a method of sorting Lakes by their square:\n\n1. QuickSort\n2. ShellSort\n\n";
	int method;
	cin >> method;
	while (method > 2 || method < 1)
	{
		cout << "\nChange a method of sorting Lakes by their square:\n\n1. QuickSort\n2. ShellSort\n\n";
		cin >> method;
	}
	
	if (method == 1) QuickSort(arr, 0, LakeAmount - 1); else ShellSort(arr, LakeAmount);

	cout << endl;
	for (int i = 0; i < LakeAmount; i++)
	{
		cout << "The Lake #" << i + 1 << ":" << endl << arr[i];
	}

}
