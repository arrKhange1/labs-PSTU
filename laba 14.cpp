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

int BoyerandMurr(string txt, string pat, DataBase*arr)
{
	int sourcelen = txt.length();
	int templen = pat.length();
	int offset_table[256];
	for (int i = 0; i <= 255; i++)
	{
		offset_table[i] = templen;
	}

	for (int i = 0; i < templen - 1; i++)
	{
		offset_table[(int)pat[i]] = templen - i - 1;
	}

	int i = templen - 1;
	int j = i;
	int k = i;
	int cnt = 0;
	while (i <= sourcelen - 1)
	{
		j = templen - 1;
		k = i;
		while (j >= 0 && txt[k] == pat[j])
		{
			k--;
			j--;
			cnt++;
		}
		if (j == -1)  cout << arr[(k + 1) / 10] << endl;
		if (i == templen - 1 && j == -1)
		{
			i++;
		}
		else if (j == -1) i++;
		else i += offset_table[(int)txt[k]] - cnt;
		cnt = 0;
	}
	if (j != -1) return -1;
	




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
	arr[0].birth_date = "09.06.2020";
	arr[3].birth_date = "09.06.2020";
	arr[1].birth_date = "09.06.2020";

	List* head = nullptr;
	ListFill(head, arr, random);
	ListPrint(head);

	DataBase* new_arr = new DataBase[MAX];
	int random_help = random;
	int cnt = 0;
	string close;
	while (close != "íåò")  // Menu
	{
		cout << endl;
		cout << "Ìåíþ\n\n";
		cout << "1. Ïîêàçàòü Áàçó Äàííûõ\n2. Íàéòè ëþäåé ïî äàòå ðîæäåíèÿ ñ ïîìîùüþ ÊÌÏ\n3. Íàéòè ëþäåé ïî äàòå ðîæäåíèÿ ñ ïîìîùüþ Ïðÿìîãî ïîèñêà\n4. Äîáàâèòü äàííûå î ÷åëîâåêå â êîíåö ÁÄ\n";
		cout << "5. Äîáàâèòü äàííûå î ÷åëîâåêå â íà÷àëî ÁÄ\n6. Äîáàâèòü äàííûå î ÷åëîâåêå íà çàäàííîå ìåñòî â ÁÄ\n7. Óäàëÿòü, ïîêà íå ïðåâûñèò ïîëîâèíó ÁÄ\n8. Îòìåíèòü ïîñëåäíåå óäàëåíèå\n";
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
			string key;
			cout << "Ââåäèòå äàòó: ";
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
				cout << endl << arr[*it / 10] << endl;




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
			BoyerandMurr(buffer, key, arr);
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
			cin >> arr[pos - 1].birth_date;
			cout << "\n2) Ôàìèëèÿ, èìÿ: ";
			cin.get();
			getline(cin, arr[pos - 1].FIO);
			cout << "\n3) Íîìåð ïàñïîðòà: ";
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

		default: cout << "Òàêîãî ïóíêòà íåò!\n";
		}

		cout << "\n\nÏðîäîëæèòü? äà/íåò: ";
		cin >> close;
		if (close == "äà") continue;
	}



	return 0;
}
