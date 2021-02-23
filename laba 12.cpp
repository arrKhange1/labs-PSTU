#include <iostream>
#include<windows.h>
#include <time.h>
#include <string>
#define MAX 100   //rand()%101+100
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
			int buff = arr[k-1];
			arr[k - 1] = arr[k];
			arr[k] = buff;
			k--;
		}
	}
}

int InterpolSearch(int*arr, int key, int Len)
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

int* strDates_to_intDates(DataBase*arr, int Len)
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

void StraightSearch(string str, string patt, DataBase*arr)
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	DataBase* arr = new DataBase[10];
	
	//int Len;
	//cout << "vvedi Len: ";
	//cin >> Len;
	int random = rand() % 3 + 5;
	for (int i = 0; i < random; i++)
	{
		random_date(arr[i]); // 97 - 122
		random_FIO(arr[i]);
		arr[i].pass_num = rand() % 900000 + 100000;
	}
	arr[2].birth_date = "09.06.2020";
	arr[0].birth_date = "09.06.2020";

	List* head = nullptr;
	ListFill(head,arr,random);
	ListPrint(head);

	/*string a = "12";
	string b = "71";
	int c = atoi(string({ (char)a[0] }).c_str());
	int l = atoi(string({ (char)b[0] }).c_str());
	if (c < l) cout << true << endl;*/
	
	
	DataBase* new_arr = new DataBase[10];
	int random_help = random;
	string close;
	while (close != "íåò")  // Menu
	{
		cout << endl;
		cout << "Ìåíþ\n\n";
		cout << "1. Ïîêàçàòü Áàçó Äàííûõ\n2. Íàéòè ëþäåé ïî äàòå ðîæäåíèÿ ñ ïîìîùüþ Èíòåðïîëà\n3. Íàéòè ëþäåé ïî äàòå ðîæäåíèÿ ñ ïîìîùüþ Ïðÿìîãî ïîèñêà\n4. Äîáàâèòü äàííûå î ÷åëîâåêå â êîíåö ÁÄ\n";
		cout << "5. Äîáàâèòü äàííûå î ÷åëîâåêå â íà÷àëî ÁÄ\n6. Äîáàâèòü äàííûå î ÷åëîâåêå íà çàäàííîå ìåñòî â ÁÄ\n7. Óäàëèòü äàííûå î ÷åëîâåêå ïî èíäåêñó\n";
		int choice;
		cout << "\nÂâîäèòå ïóíêò: ";
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
			int* new_arr = strDates_to_intDates(arr, random);
			string key;
			cout << "Ââåäèòå äàòó: ";
			cin >> key;
			int key_int = strKey_to_intKey(key);

			if (InterpolSearch(new_arr, key_int, random) != -1)
			{
				cout << "\nÏðåäñòàâëÿþ ñâîä äàííûõ î ëþäÿõ ñ çàäàííûì Âàìè ïîëåì: \n\n";
				for (int i = 0; i < random; i++) // Linear Search
				{
					if (arr[i].birth_date == key) cout << arr[i] << endl;
				}
			}
			else cout << "Äàííûå î ëþäÿõ ñ çàäàííûì ïîëåì îòñóòñòâóþò!\n";
			break;
		}
		case 3:
		{
			string key;
			cout << "Ââåäèòå äàòó: ";
			cin >> key;
			string buffer;
			for (int i = 0; i < random; i++)
			{
				buffer += arr[i].birth_date;
			}
			cout << "\nÏðåäñòàâëÿþ ñâîä äàííûõ î ëþäÿõ ñ çàäàííûì Âàìè ïîëåì: \n\n";
			StraightSearch(buffer,key,arr);
			break;
		}
		case 4:
		{
			cout << "Ââåäèòå äàííûå î ÷åëîâåêå:\n\n1) Äàòà ðîæäåíèÿ: ";
			cin >> arr[random].birth_date;
			cout << "\n2) Ôàìèëèÿ, èìÿ: ";
			cin.get();
			getline(cin, arr[random].FIO);
			cout << "\n3) Íîìåð ïàñïîðòà: ";
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
			cout << "random 4. " << random << endl;
			break;
		}
		case 5:
		{
			for (int i = random - 1; i >= 0; i--)
			{
				arr[i + 1] = arr[i];
			}
			cout << "Ââåäèòå äàííûå î ÷åëîâåêå:\n\n1) Äàòà ðîæäåíèÿ: ";
			cin >> arr[0].birth_date;
			cout << "\n2) Ôàìèëèÿ, èìÿ: ";
			cin.get();
			getline(cin, arr[0].FIO);
			cout << "\n3) Íîìåð ïàñïîðòà: ";
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
			cout << "Ââåäèòå ïîçèöèþ â ÁÄ, êóäà âñòàâèòü íîâûå äàííûå î ÷åëîâåêå: ";
			int pos;
			cin >> pos;
			while (pos < 1 || pos > random)
			{
				cout << "\nÒàêîãî íîìåðà â ÁÄ íåò! Ââåäèòå ïîçèöèþ çàíîâî: ";
				cin >> pos;
				cout << "\n";
			}
			for (int i = random - 1; i >= pos - 1; i--)
			{
				arr[i + 1] = arr[i];
			}
			cout << "Ââåäèòå äàííûå î ÷åëîâåêå:\n\n1) Äàòà ðîæäåíèÿ: ";
			cin >> arr[pos-1].birth_date;
			cout << "\n2) Ôàìèëèÿ, èìÿ: ";
			cin.get();
			getline(cin, arr[pos-1].FIO);
			cout << "\n3) Íîìåð ïàñïîðòà: ";
			cin >> arr[pos-1].pass_num;

			int cnt = 0;
			List* now_ptr = head;
			List* prenow_ptr = now_ptr;
			while (now_ptr != nullptr)
			{
				if (cnt == pos - 1)
				{
					List* new_elem = new List;
					new_elem->object.birth_date = arr[pos-1].birth_date;
					new_elem->object.FIO = arr[pos-1].FIO;
					new_elem->object.pass_num = arr[pos-1].pass_num;
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
			new_arr = new DataBase[10];
			for (int i = 0; i < random; i++)
			{
				new_arr[i] = arr[i];
				cout << "new_arr[i] 7. =  " << new_arr[i] << endl;
			}
			random_help = random;
			
			cout << "random help " << random_help << endl;

			int cnt = 0;
			while (cnt <= random / 2)
			{
				int for_del;
				cout << "Ââåäèòå íîìåð äàííûõ äëÿ óäàëåíèÿ: ";
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
			cout << "rand_help 7.(êîíåö) = " << random_help << endl;
			List* now_ptr = head;
			while (now_ptr != nullptr)
			{
				cout << now_ptr->IsDeleted << endl;
				now_ptr = now_ptr->next;
			}

			delete[] arr;
			arr = new DataBase[10];
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
			cout << "rand_help 7.(êîíåö) = " << random_help << endl;
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
			arr = new DataBase[10];
			for (int i = 0; i < random_help;i++)
			{
				arr[i] = new_arr[i];
			}
			delete[] new_arr;
			random = random_help;
			break;
		}
		default: cout << "Òàêîãî ïóíêòà íåò!\n";
		}
		
		cout << "\n\nÏðîäîëæèòü? äà/íåò: ";
		cin >> close;
		if (close == "äà") continue;
	}

	// Â ðàçðàáîòêå!
	

	return 0;
}
