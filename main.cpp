#include <iostream>
using namespace std;

struct Stack
{
	int data;
	Stack* next;
	
};

void StackAdd(Stack*& head, int elem)
{
	Stack* now_elem = new Stack;
	now_elem->data = elem;
	now_elem->next = head;
	head = now_elem;
}

void StackPrint(Stack*& head)
{
	Stack* now_ptr = head;
	int i = 1;
	while (now_ptr != nullptr)
	{
		cout << i++ << ". " << now_ptr->data << endl; 
		now_ptr = now_ptr->next;
	}
}

int main()
{
	int StackLen;
	Stack* head = nullptr;
	
	int elem;
	while (cin >> elem)
	{
		if (elem == 0) break;
		StackAdd(head, elem);
	}

	StackPrint(head);


	return 0;
}