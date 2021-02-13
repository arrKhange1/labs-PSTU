#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

bool string_suit(string str)
{
	string str_1st;
	int cnt = 0;
	int k = 0;
	int k1;
	int l;
	bool found = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') cnt++;
	}
	for (int i = 0; i < cnt && found == false; i++)
	{
		for (int j = i; j < cnt + 1 && found == false; j++)
		{
			if (j == i)
			{
				str_1st = "";
				while (str[k] != ' ')
				{
					str_1st += str[k];
					k++;
				}
				k += 1;
				k1 = k;
			}

			else
			{
				string str_next = "";
				for (l = k1; str[l] != ' ' && l != str.length(); l++)
				{
					str_next += str[l];
				}
				if (str_1st == str_next) found = true;
				k1 = l + 1;
			}

		}
	}
	return found;
}

void F1_and_F2_fill(ofstream& F1, int F1_len, ofstream& F2)
{
	for (int i = 0; i < F1_len; i++)
	{
		string temp;
		cout << "enter the " << i + 1 << " string of " << 5 << ": ";
		getline(cin, temp);
		F1 << temp << '\n';
		if (string_suit(temp)) F2 << temp << '\n';
	}
}

int vowel_letter(string temp)
{
	int cnt = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == 'à' || temp[i] == 'î' || temp[i] == 'ó' || temp[i] == 'ý' || temp[i] == 'û' || temp[i] == 'ÿ' || temp[i] == '¸' || temp[i] == 'þ' || temp[i] == 'å' || temp[i] == 'è') cnt++;
	}
	cout << "amount of vowel letters in the last string is " << cnt << endl;
	return cnt;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);               
	SetConsoleOutputCP(1251);


	ofstream F2;
	F2.open("F2.txt");
	if (!F2.is_open()) cout << "problems with opening the file F2.txt\n";

	ofstream F1;
	int F1_len = 5;
	
	F1.open("F1.txt");

	if (F1.is_open() && F2.is_open())
	{
		F1_and_F2_fill(F1,F1_len,F2);
	}
	else cout << "problems with opening the file F1.txt\n";
	
	F1.close();
	F2.close();

	ifstream F3;
	F3.open("F2.txt");
	int cnt = 0;
	string temp;
	string temp1;
	while (!F3.eof())
	{
		getline(F3, temp1);
		if (temp1 != "")
		{
			cnt++;
			temp = temp1;
		}
	}
	if (cnt != 0)
	{
		cout << "\nthe last string: " << temp << endl;
		vowel_letter(temp);
	}
	else cout << "F2.txt is an empty file\n";

	F3.close();
	
	
	
	
	return 0;
}