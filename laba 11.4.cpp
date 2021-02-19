#include <iostream>
using namespace std;

struct Queue
{
	char data;
	Queue* next;
};

void QueueFill(Queue*& head)
{
	Queue* now_elem = new Queue; // 1st elem
	int i = 1;
	char elem;
	cout << i++ << ") ";
	cin >> elem;
	now_elem->data = elem;
	head = now_elem;
	Queue* now_ptr = head;
	now_ptr->next = nullptr;
	
	cout << i++ << ") ";
	cin >> elem;
	while (elem != '0')
	{
		Queue* next_elem = new Queue;
		now_ptr->next = next_elem;
		now_ptr = next_elem;
		now_ptr->data = elem;
		now_ptr->next = nullptr;
		cout << i++ << ") ";
		cin >> elem;
	}

}

void QueueAddAfter(Queue*& head, char elem_after_add)
{
	Queue* now_ptr = head;
	Queue* head_help = nullptr;
	Queue* now_ptr_help = head_help;
	bool flag = false;

	while (now_ptr != nullptr)
	{
		if (now_ptr->data == elem_after_add)
		{
			if (flag == false) // 1st elem
			{
				Queue* new_elem = new Queue;     // элемент для переноса
				head_help = new_elem;
				now_ptr_help = new_elem;
				now_ptr_help->data = now_ptr->data;
				flag = true;
				Queue* new_elem1 = new Queue;    // тк в условии добавления то после надо еще добавить эл-т
				new_elem1->data = 'B';
				now_ptr_help->next = new_elem1;
				now_ptr_help = new_elem1;
			}
			else // не 1 эл-т
			{
				Queue* new_elem = new Queue;   // элемент для переноса
				new_elem->data = now_ptr->data;
				now_ptr_help->next = new_elem;
				now_ptr_help = new_elem;
				 
				Queue* new_elem2 = new Queue;  // тк в условии добавления то после надо еще добавить эл-т
				new_elem2->data = 'B';
				now_ptr_help->next = new_elem2;
				now_ptr_help = new_elem2;
			}
			
		}
		else
		{
			if (flag == false) // 1st elem
			{
				Queue* new_elem = new Queue;     // перенос эл-та 
				head_help = new_elem;
				now_ptr_help = new_elem;
				now_ptr_help->data = now_ptr->data;
				flag = true;
			}
			else
			{
				Queue* new_elem = new Queue;    // перенос эл-та
				new_elem->data = now_ptr->data;
				now_ptr_help->next = new_elem;
				now_ptr_help = new_elem;
			}
			
		}
		Queue* del_ptr = now_ptr;
		now_ptr = now_ptr->next;
		delete del_ptr;
	}
	head = head_help;
	now_ptr_help->next = nullptr;
}

void QueuePrint(Queue*& head)
{
	Queue* now_ptr = head;
	int i = 1;
	while (now_ptr != nullptr)
	{
		cout << i++ << ") " << now_ptr->data << endl;
		now_ptr = now_ptr->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char elem_after_add;
	cout << "Введите элемент, после которого вставлять символы: ";
	cin >> elem_after_add;
	Queue* head = nullptr;
	
	cout << "Вводите символы, пока не 0:\n";
	QueueFill(head);
	cout << endl;

	QueueAddAfter(head, elem_after_add);

	QueuePrint(head);

	return 0;
}
