#include <iostream>
using namespace std;

int BoyerandMurr(string txt, string pat)
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
	while (j >= 0 && i <= sourcelen - 1)
	{
		j = templen - 1;
		k = i;
		while (j >= 0 && txt[k] == pat[j])
		{
			k--;
			j--;
			cnt++;
		}
		i += offset_table[(int)txt[k]] - cnt;
		cnt = 0;
	}
	if (j != -1) return -1;
	else return i - templen +1;




}



int main()
{
	string txt = "money";
	string pat = "on";
	cout << BoyerandMurr(txt, pat);
	return 0;
}