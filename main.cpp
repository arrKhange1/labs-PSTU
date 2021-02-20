#include <iostream>
#include <iterator>
#include <queue>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
	queue <char> q;
	queue <char> q_new;

    setlocale(LC_ALL, "Rus");

    char elem_after_add;
    cout << "¬ведите эл-т, после которого вставл€ть: ";
    cin >> elem_after_add;
    char elem;
    int i = 1;
    cout << "\n¬ведите эл-ты очереди:\n";
    cout << i++ << ") ";
    cin >> elem;
    while (elem != '0')
    {
        q.push(elem);
        cout << i++ << ") ";
        cin >> elem;
    }

    while (!q.empty())
    {
        q_new.push(q.front());
        if (q.front() == elem_after_add)
        {
            q_new.push('B');
        }
        q.pop();
    }
    
    cout << endl << "»змененна€ очередь:\n";
    i = 1;
    while (!q_new.empty())
    {
        cout << i++ << ") " << q_new.front() << endl;
        q_new.pop();
    }


	
	return 0;
}