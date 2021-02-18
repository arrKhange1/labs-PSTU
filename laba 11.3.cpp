#include <iostream>
using namespace std;

struct Stack
{
	int data;
	Stack* prev;
};

void StackAdd(Stack*& head, int elem)
{
	Stack* new_elem = new Stack;
	new_elem->data = elem;
	new_elem->prev = head;
	head = new_elem;
}

void StackPrint(Stack*& head)
{
	Stack* now_ptr = head;
	int i = 1;
	while (now_ptr != nullptr)
	{
		cout << i++ << ") " << now_ptr->data << endl;
		now_ptr = now_ptr->prev;
	}
}

void StackDelLast(Stack*& head)
{
	Stack* now_ptr = head;
	Stack* help = head;
	while (now_ptr->prev != nullptr)
	{
		help = now_ptr;
		now_ptr = now_ptr->prev;
	}
	if (now_ptr->data % 2 == 0)
	{
		delete now_ptr;
		help->prev = nullptr;
	}
}

void StackDel(Stack*& head)
{
	while (head != nullptr)
	{
		Stack* del_ptr = head;
		head = head->prev;
		delete del_ptr;
	}
}

int main()
{
	int StackLen;
	Stack* head = nullptr;
	
	cout << "enter elems while not the 0 digit: ";
	int elem;
	int cnt = 1;
	cout << endl << cnt++ << ") ";
	cin >> elem;
	while (elem != 0)
	{
		cout << cnt++ << ") ";
		if (elem == 0) break;
		else StackAdd(head, elem);
		cin >> elem;
	}

	StackDelLast(head);
	cout << endl;

	StackPrint(head);

	StackDel(head);


	return 0;
}
