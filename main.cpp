#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int>& st, int n, int curr = 0)

{

    // ���� �� ��������� ����� �����, ����� ���������� ����. ��-�� ����� �������� � � ���� ���� �� ������ ��-���
    // (����� ����� ����)

    if (st.empty() || curr == n)

        return;



    // �������� �������� ��-�� ����� � ������������ � ����� �� ������. �-�� ��� ��������� � ���� �����

    int x = st.top();


    st.pop();



    // ����������� �����

    deleteMid(st, n, curr + 1);



    // ������� ��� , ����� ���������� ��-�� ����� (���� �� ������)

    if (curr != n-1 || x % 2 != 0)

        st.push(x);

}


int main()

{
    setlocale(LC_ALL, "Rus");
    stack<int> st;

    int elem;
    int i = 1;
    cout << "������� �������� ��� ��������� � ����:\n";
    cout << i++ << ") ";
    cin >> elem;
    while (elem != 0)
    {
        st.push(elem);
        cout << i++ << ") ";
        cin >> elem;
    }


    deleteMid(st, st.size());

  
    cout << endl << "���������� ����:\n";
    i = 1;
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << i++ << ") " << p << endl;
    }

    return 0;

}