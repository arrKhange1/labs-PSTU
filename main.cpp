#include <iostream>
#include <time.h>
using namespace std;

struct OneDirList
{
	int data;
	OneDirList* next;
};

void ListFill(OneDirList*& head, int ListLen)
{
	head = nullptr;
	OneDirList* now_ptr = new OneDirList;
	now_ptr->data = rand() % 100;
	now_ptr->next = nullptr;
	head = now_ptr;
	for (int i = 1; i < ListLen;i++)
	{
		OneDirList* next_ptr = new OneDirList;
		now_ptr->next = next_ptr;
		now_ptr = now_ptr->next;
		now_ptr->data = rand() % 100;
		now_ptr->next = nullptr;
	}
}

void ListPrint(OneDirList*& head)
{
	if (head != nullptr)
	{
		OneDirList* now_ptr = head;
		int i = 1;
		while (now_ptr != nullptr)
		{
			cout << i++ << " element: " << now_ptr->data << endl;
			now_ptr = now_ptr->next;
			
		}
	}
}

void ListDelete(OneDirList*& head)
{
	if (head != nullptr)
	{
		while (head != nullptr)
		{
			OneDirList* now_ptr = head;
			head = head->next;
			delete now_ptr;
		}
	}
	else cout << "an empty List\n";
}

void ListDelLast(OneDirList*& head)
{
	OneDirList* now_ptr = head;
	while (now_ptr->next->next != nullptr)
	{
		now_ptr = now_ptr->next;
	}
	if (now_ptr->next->data % 2 == 0)
	{
		cout << "\nthe last even element " << now_ptr->next->data << " gonna be deleted\n";
		delete now_ptr->next;
		now_ptr->next = nullptr;
	}
	else cout << "\nthe last element is not even\n";
}

int main()
{
	srand(time(NULL));
	OneDirList* head;
	int ListLen;
	cout << "Enter an amount of list elements: ";
	cin >> ListLen;

	ListFill(head,ListLen);
	cout << endl;

	ListPrint(head);

	ListDelLast(head);
	cout << endl;

	ListPrint(head);

	ListDelete(head);

	return 0;
}
