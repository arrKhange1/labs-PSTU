#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int>& st, int n, int curr = 0)

{

    // пока не достигнем конца стека, потом возвращаем посл. эл-ту стека значений и с него идем по другим эл-там
    // (снизу вверх типа)

    if (st.empty() || curr == n)

        return;



    // Удаление текущего эл-та стека и сохраненение в одной из рекурс. ф-ий для обращения к нему потом

    int x = st.top();


    st.pop();



    // Опустошение стека

    deleteMid(st, n, curr + 1);



    // Вернуть все , кроме последнего эл-та стека (если он четный)

    if (curr != n-1 || x % 2 != 0)

        st.push(x);

}


int main()

{
    setlocale(LC_ALL, "Rus");
    stack<int> st;

    int elem;
    int i = 1;
    cout << "Введите элементы для помещения в стек:\n";
    cout << i++ << ") ";
    cin >> elem;
    while (elem != 0)
    {
        st.push(elem);
        cout << i++ << ") ";
        cin >> elem;
    }


    deleteMid(st, st.size());

  
    cout << endl << "Измененный стек:\n";
    i = 1;
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        cout << i++ << ") " << p << endl;
    }

    return 0;

}