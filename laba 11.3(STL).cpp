#include <iostream>
#include <stack>
using namespace std;

void deleteLast(stack<int>& st, int n, int curr = 0)

{

    // ïîêà íå äîñòèãíåì êîíöà ñòåêà, ïîòîì âîçâðàùàåì ïîñë. ýë-òó ñòåêà çíà÷åíèé è ñ íåãî èäåì ïî äðóãèì ýë-òàì
    // (ñíèçó ââåðõ òèïà)

    if (st.empty() || curr == n)

        return;



    // Óäàëåíèå òåêóùåãî ýë-òà ñòåêà è ñîõðàíåíåíèå â îäíîé èç ðåêóðñ. ô-èé äëÿ îáðàùåíèÿ ê íåìó ïîòîì

    int x = st.top();


    st.pop();



    // Îïóñòîøåíèå ñòåêà

    deleteLast(st, n, curr + 1);



    // Âåðíóòü âñå , êðîìå ïîñëåäíåãî ýë-òà ñòåêà (åñëè îí ÷åòíûé)

    if (curr != n-1 || x % 2 != 0)

        st.push(x);

}


int main()

{
    setlocale(LC_ALL, "Rus");
    stack<int> st;

    int elem;
    int i = 1;
    cout << "Ââåäèòå ýëåìåíòû äëÿ ïîìåùåíèÿ â ñòåê:\n";
    cout << i++ << ") ";
    cin >> elem;
    while (elem != 0)
    {
        st.push(elem);
        cout << i++ << ") ";
        cin >> elem;
    }


    deleteLast(st, st.size());

  
    cout << endl << "Èçìåíåííûé ñòåê:\n";
    i = 1;
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << i++ << ") " << p << endl;
    }

    return 0;

}
