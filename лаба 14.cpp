#include <iostream>
#include <vector>
#include <fstream>
#include<windows.h>
#include <time.h>
#include <string>
#define MAX 200   //rand()%101+100
using namespace std;

struct DataBase
{
	string birth_date;
	string FIO;
	int pass_num;
};

struct List
{
	DataBase object;
	bool IsDeleted;
	List* next;
};


ostream& operator << (ostream& co, DataBase& object)
{
	co << object.birth_date << " " << object.FIO << " " << object.pass_num << "\n";
	return co;
}

void Print(DataBase* arr, int Len)
{
	for (int i = 0; i < Len; i++)
	{
		cout << i + 1 << ")\n";
		cout << "Birth Date | \tFIO\t| Passport number\n\n";
		cout << arr[i] << "\n\n";
	}
}

void random_date(DataBase& arr)
{
	arr.birth_date = to_string(rand() % 2) + to_string(rand() % 9 + 1) + ".";
	if (rand() % 2 == 0) arr.birth_date += "0" + to_string(rand() % 9 + 1) + "." + to_string(rand() % 121 + 1900);
	else arr.birth_date += "1" + to_string(rand() % 3) + "." + to_string(rand() % 121 + 1900);
}

void random_FIO(DataBase& arr)
{
	for (int j = 0; j < rand() % 4 + 2; j++)
	{
		if (j == 0) arr.FIO += toupper((char)(rand() % 26 + 97));
		else arr.FIO += (char)(rand() % 26 + 97);
	}
	arr.FIO += " ";
	for (int j = 0; j < rand() % 3 + 7; j++)
	{
		if (j == 0) arr.FIO += toupper((char)(rand() % 26 + 97));
		else arr.FIO += (char)(rand() % 26 + 97);
	}
}

void InsertSort(int* arr, int Len)
{
	for (int i = 1; i < Len; i++)
	{
		int k = i;
		while (k > 0 && arr[k] < arr[k - 1])
		{
			int buff = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = buff;
			k--;
		}
	}
}

int InterpolSearch(int* arr, int key, int Len)
{
	InsertSort(arr, Len);
	int mid, left = 0, right = Len - 1;
	while (arr[left] <= key && arr[right] >= key)
	{
		mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
		if (arr[mid] < key) left = mid + 1;
		else if (arr[mid] > key) right = mid - 1;
		else return mid;
	}
	if (arr[left] == key) return left;
	else return -1;
}

int* strDates_to_intDates(DataBase* arr, int Len)
{
	int* new_arr = new int[Len];
	for (int i = 0; i < Len; i++)
	{
		string buff;
		for (int j = 0; j < arr[i].birth_date.size(); j++)
		{
			if (arr[i].birth_date[j] != '.') buff += arr[i].birth_date[j];
		}
		new_arr[i] = atoi(string({ (string)buff }).c_str());
	}
	return new_arr;
}

int strKey_to_intKey(string key)
{
	string buff;
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i] != '.') buff += key[i];
	}
	int key_int = atoi(string({ (string)buff }).c_str());
	return key_int;
}

void StraightSearch(string str, string patt, DataBase* arr)
{
	for (int i = 0; i < str.size(); i++)
	{
		int i_helper = i;
		for (int j = 0; j < patt.size(); j++)
		{
			if (str[i_helper] != patt[j]) break;
			else if (j == patt.size() - 1)
			{
				cout << arr[i / 10] << endl;
			}
			i_helper++;
		}
	}
}

void ListFill(List*& head, DataBase* arr, int Len)
{
	List* new_elem = new List;
	new_elem->object = arr[0];
	List* now_ptr = new_elem;
	head = now_ptr;
	for (int i = 1; i < Len; i++)
	{
		List* next_elem = new List;
		next_elem->object = arr[i];
		now_ptr->next = next_elem;
		now_ptr = next_elem;
		now_ptr->next = nullptr;
	}
}

void ListPrint(List*& head)
{
	List* now_ptr = head;
	while (now_ptr != nullptr)
	{
		cout << now_ptr->object << endl;
		now_ptr = now_ptr->next;
	}
}

void ListDelete(List*& head)
{
	while (head != nullptr)
	{
		List* del_ptr = head;
		head = head->next;
		delete del_ptr;
	}
}


int* max_border_array(string T) {

	int i, n = T.length(), t;

	int* br = new int[n];

	br[0] = 0;

	for (i = 1; i < n; i++) {

		t = br[i - 1];

		while ((t > 0) && (T[i] != T[t])) {

			t = br[t - 1];

		}

		if (T[i] == T[t]) {

			br[i] = t + 1;

		}
		else {

			br[i] = 0;

		}

	}

	return br;

}

vector<int> KMP(string str, string sub, int* br) {

	vector<int> solution;

	int poz = 0;

	for (int i = 0; i < str.size(); i++) {

		while (poz == sub.size() || (poz > 0 && sub[poz] != str[i])) {

			poz = br[poz - 1];

			if (sub.size() - poz > str.size() - i)

				break;

		}

		if (str[i] == sub[poz]) {

			poz++;

		}

		if (poz == sub.size()) {

			solution.push_back(i - poz + 1);

		}

	}

	return solution;

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	DataBase* arr = new DataBase[MAX];

	int random = rand() % 3 + 5;
	for (int i = 0; i < random; i++)
	{
		random_date(arr[i]); // 97 - 122
		random_FIO(arr[i]);
		arr[i].pass_num = rand() % 900000 + 100000;
	}
	arr[3].birth_date = "09.06.2020";
	arr[0].birth_date = "09.06.2020";

	List* head = nullptr;
	ListFill(head, arr, random);
	ListPrint(head);

	DataBase* new_arr = new DataBase[MAX];
	int random_help = random;
	int cnt = 0;
	string close;
	while (close != "нет")  // Menu
	{
		cout << endl;
		cout << "Меню\n\n";
		cout << "1. Показать Базу Данных\n2. Найти людей по дате рождения с помощью КМП\n3. Найти людей по дате рождения с помощью Прямого поиска\n4. Добавить данные о человеке в конец БД\n";
		cout << "5. Добавить данные о человеке в начало БД\n6. Добавить данные о человеке на заданное место в БД\n7. Удалять, пока не превысит половину БД\n8. Отменить последнее удаление\n";
		int choice;
		cout << "\nВводите пункт: ";
		cin >> choice;
		cout << "\n\n";

		switch (choice)
		{
		case 1:
		{
			Print(arr, random);
			break;
		}
		case 2:
		{
			string key;
			cout << "Введите дату: ";
			cin >> key;
			string buffer;
			for (int i = 0; i < random; i++)
			{
				buffer += arr[i].birth_date;
			}
			max_border_array(key);
			vector<int>a;

			a = KMP(buffer, key, max_border_array(key));
			for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
				cout << endl << arr[*it/10] << endl;

			

			
			break;
		}
		case 3:
		{
			string key;
			cout << "Введите дату: ";
			cin >> key;
			string buffer;
			for (int i = 0; i < random; i++)
			{
				buffer += arr[i].birth_date;
			}
			cout << "\nПредставляю свод данных о людях с заданным Вами полем: \n\n";
			StraightSearch(buffer, key, arr);
			break;
		}
		case 4:
		{
			cout << "Введите данные о человеке:\n\n1) Дата рождения: ";
			cin >> arr[random].birth_date;
			cout << "\n2) Фамилия, имя: ";
			cin.get();
			getline(cin, arr[random].FIO);
			cout << "\n3) Номер паспорта: ";
			cin >> arr[random].pass_num;

			int cnt = 0;
			List* now_ptr = head;
			while (now_ptr->next != nullptr)
			{
				now_ptr = now_ptr->next;
			}
			List* new_elem = new List;
			new_elem->object.birth_date = arr[random].birth_date;
			new_elem->object.FIO = arr[random].FIO;
			new_elem->object.pass_num = arr[random].pass_num;
			now_ptr->next = new_elem;
			now_ptr = new_elem;
			now_ptr->next = nullptr;
			ListPrint(head);

			random++;
			break;
		}
		case 5:
		{
			for (int i = random - 1; i >= 0; i--)
			{
				arr[i + 1] = arr[i];
			}
			cout << "Введите данные о человеке:\n\n1) Дата рождения: ";
			cin >> arr[0].birth_date;
			cout << "\n2) Фамилия, имя: ";
			cin.get();
			getline(cin, arr[0].FIO);
			cout << "\n3) Номер паспорта: ";
			cin >> arr[0].pass_num;

			List* new_elem = new List;
			new_elem->next = head;
			new_elem->object.birth_date = arr[0].birth_date;
			new_elem->object.FIO = arr[0].FIO;
			new_elem->object.pass_num = arr[0].pass_num;
			head = new_elem;
			ListPrint(head);

			random++;
			break;

		}
		case 6:
		{
			cout << "Введите позицию в БД, куда вставить новые данные о человеке: ";
			int pos;
			cin >> pos;
			while (pos < 1 || pos > random)
			{
				cout << "\nТакого номера в БД нет! Введите позицию заново: ";
				cin >> pos;
				cout << "\n";
			}
			for (int i = random - 1; i >= pos - 1; i--)
			{
				arr[i + 1] = arr[i];
			}
			cout << "Введите данные о человеке:\n\n1) Дата рождения: ";
			cin >> arr[pos - 1].birth_date;
			cout << "\n2) Фамилия, имя: ";
			cin.get();
			getline(cin, arr[pos - 1].FIO);
			cout << "\n3) Номер паспорта: ";
			cin >> arr[pos - 1].pass_num;

			int cnt = 0;
			List* now_ptr = head;
			List* prenow_ptr = now_ptr;
			while (now_ptr != nullptr)
			{
				if (cnt == pos - 1)
				{
					List* new_elem = new List;
					new_elem->object.birth_date = arr[pos - 1].birth_date;
					new_elem->object.FIO = arr[pos - 1].FIO;
					new_elem->object.pass_num = arr[pos - 1].pass_num;
					prenow_ptr->next = new_elem;
					new_elem->next = now_ptr;
					break;
				}
				prenow_ptr = now_ptr;
				now_ptr = now_ptr->next;
				cnt++;

			}
			ListPrint(head);

			random++;
			break;
		}
		case 7:
		{
			new_arr = new DataBase[MAX];
			for (int i = 0; i < random; i++)
			{
				new_arr[i] = arr[i];
			}
			random_help = random;


			cnt = 0;
			while (cnt <= random / 2)
			{
				int for_del;
				cout << "Введите номер данных для удаления: ";
				cin >> for_del;
				List* now_ptr = head;
				int index = 0;
				while (now_ptr != nullptr)
				{
					if (index == for_del - 1)
					{
						now_ptr->IsDeleted = true;
						cnt++;
					}
					else if (now_ptr->IsDeleted != true) now_ptr->IsDeleted = false;

					now_ptr = now_ptr->next;
					index++;
				}
			}
			random -= cnt;
			List* now_ptr = head;
			while (now_ptr != nullptr)
			{
				now_ptr = now_ptr->next;
			}

			delete[] arr;
			arr = new DataBase[MAX];
			now_ptr = head;
			int i = 0;
			while (now_ptr != nullptr)
			{
				if (now_ptr->IsDeleted != true)
				{
					arr[i] = now_ptr->object;
					i++;
				}
				now_ptr = now_ptr->next;

			}

			Print(arr, random);
			ListDelete(head);
			ListFill(head, arr, random);
			cout << endl;


			break;
		}
		case 8:
		{
			ListDelete(head);
			ListFill(head, new_arr, random_help);
			for (int i = 0; i < random_help; i++)
			{
				cout << "new_arr[i] 8. = " << new_arr[i] << endl;
			}
			delete[] arr;
			arr = new DataBase[MAX];
			for (int i = 0; i < random_help; i++)
			{
				arr[i] = new_arr[i];
			}
			delete[] new_arr;
			random = random_help;
			break;
		}

		default: cout << "Такого пункта нет!\n";
		}

		cout << "\n\nПродолжить? да/нет: ";
		cin >> close;
		if (close == "да") continue;
	}



	return 0;
}