#include <iostream>
using namespace std;

struct Stack
{
	int data;
	Stack* prev;
};

void StackFill(Stack*& head)
{
	int elem;
	int i = 1;
	cout << i++ << ") ";
	cin >> elem;
	while (elem != 0)
	{
		Stack* new_elem = new Stack;
		new_elem->data = elem;
		new_elem->prev = head;
		head = new_elem;
		cout << i++ << ") ";
		cin >> elem;
	}
	
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
	Stack* head_help = nullptr;
	Stack* now_ptr_help = head_help;
	bool flag = false;

	while (now_ptr->prev != nullptr)
	{
		if (flag == false)
		{
			Stack* new_elem_help = new Stack;
			new_elem_help->data = now_ptr->data;
			head_help = new_elem_help;
			now_ptr_help = new_elem_help;
			flag = true;
			Stack* del_ptr = now_ptr;
			now_ptr = now_ptr->prev;
			delete del_ptr;
		}
		else
		{
			Stack* new_elem_help = new Stack;
			new_elem_help->data = now_ptr->data;
			now_ptr_help->prev = new_elem_help;
			now_ptr_help = new_elem_help;
			Stack* del_ptr = now_ptr;
			now_ptr = now_ptr->prev;
			delete del_ptr;
		}
	}
	
	if (now_ptr->data % 2 != 0)
	{
		Stack* new_elem_help = new Stack;
		new_elem_help->data = now_ptr->data;
		now_ptr_help->prev = new_elem_help;
		now_ptr_help = new_elem_help;
	}
	now_ptr_help->prev = nullptr;
	delete now_ptr;
	head = head_help;
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
	
	cout << "enter elems while not the 0 digit: \n";

	StackFill(head);

	StackDelLast(head);
	cout << endl;

	StackPrint(head);

	StackDel(head);


	return 0;
}
