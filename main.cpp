#include <iostream>
#include <ctime>
using namespace std;

void mergeSortNaturalMain(int* v, int r, int t)
{
	int p = 1;
	int k = 1;
	int i = 0;
	bool flag = false;
	while (v[i] <= v[i + 1] && i < r - 1)
	{
		p++;
		i++;
	}
	if (v[i] > v[i + 1] && i < r - 1)
	{
		i++;
		flag = true;
		while (v[i] <= v[i + 1] && i < r - 1)
		{
			k++;
			i++;
		}
	}
	int num = i + 1;
	int* a = new int[p];
	int* b = new int[k];
	
	for (i = 0; i < p; ++i)
	{
		a[i] = v[i];
	}

	int g = 0;
	if (flag == true)
	{
		for (i = p; i < p + k; ++i)
		{
			b[g] = v[i];
			g++;
		}
	}

	int j = 0;
	int l = 0;

	if (flag == true)
	{
		for (i = 0; i < num; ++i)
		{
			if ((a[l] < b[j] || j >= k) && l < p)
			{
				v[i] = a[l];
				l++;
			}
			else if ((a[l] > b[j] || l >= p) && j < k)
			{
				v[i] = b[j];
				j++;
			}
			else if (a[l] == b[j] && j < k && l < p)
			{
				v[i] == a[l];
				v[i + 1] = b[j];
				l++;
				j++;
				i++;
			}

		}
	}
	delete[] a;
	delete[] b;
}

void mergeSortNatural(int* v, int r, int i)
{
	if (i < r)
	{
		mergeSortNaturalMain(v, r, i);
		mergeSortNatural(v, r, i + 1);
	}
}
 
void mergeSortBalancedMain(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; ++j)
	{
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
		
	}
	for (j = first; j <= last; ++j) A[j] = mas[j];
	delete[] mas;
}

void mergeSortBalanced(int* A, int first, int last)
{
	if (first < last)
	{
		mergeSortBalanced(A, first, (first + last) / 2);
		mergeSortBalanced(A, (first + last) / 2 +1, last);
		mergeSortBalancedMain(A, first, last);

	}
}


int main()
{
	cout << "give a size of an array to sort it in the increasing way: ";
	int size;
	cin >> size;
	cout << endl;
	
	int* arr = new int[10];
	
	srand(time(NULL));
	
	setlocale(LC_ALL, "Rus");
	
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = size-1 - i;
		cout << arr[i] << " ";
	}
	cout << "\n\n";
	
	cout << "choose a type of sorting:\n\n1. mergeSortNatural\n2. mergeSortBalanced\n\n";
	int choice;
	cin >> choice;
	cout << endl;
	if (choice == 1) mergeSortNatural(arr, 10, 0);
	else if (choice == 2) mergeSortBalanced(arr, 0, size - 1);
	
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	

	return 0;
}