#include <iostream>
using namespace std;

struct Queue
{
	char data;
	Queue* next;
};

void QueueFill(Queue*& head)
{
	Queue* now_elem = new Queue;
	char elem;
	cin >> elem;
	now_elem->data = elem;
	head = now_elem;
	Queue* now_ptr = head;
	now_ptr->next = nullptr;
	cin >> elem;
	while (elem != '0')
	{
		Queue* next_elem = new Queue;
		now_ptr->next = next_elem;
		now_ptr = next_elem;
		now_ptr->data = elem;
		now_ptr->next = nullptr;
		cin >> elem;
	}
	
}

void QueuePrint(Queue*& head)
{
	Queue* now_ptr = head;
	while (now_ptr != nullptr)
	{
		cout << now_ptr->data << endl;
		now_ptr = now_ptr->next;
	}
}

int main()
{
	char elem_after_del;
	cin >> elem_after_del;
	Queue* head = nullptr;
	QueueFill(head);
	cout << endl;

	QueuePrint(head);

	return 0;
}
