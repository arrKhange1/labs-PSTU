#include <iostream>
using namespace std;

//#include <iostream>
//#include <time.h>
//using namespace std;
//
//struct OneDirList
//{
//	int data;
//	OneDirList* next;
//};
//
//void ListFill(OneDirList*& head, int ListLen)
//{
//	head = nullptr;
//	OneDirList* now_ptr = new OneDirList;
//	now_ptr->data = rand() % 100;
//	now_ptr->next = nullptr;
//	head = now_ptr;
//	for (int i = 1; i < ListLen; i++)
//	{
//		OneDirList* next_ptr = new OneDirList;
//		now_ptr->next = next_ptr;
//		now_ptr = now_ptr->next;
//		now_ptr->data = rand() % 100;
//		now_ptr->next = nullptr;
//	}
//}
//
//void ListPrint(OneDirList*& head)
//{
//	if (head != nullptr)
//	{
//		OneDirList* now_ptr = head;
//		int i = 1;
//		while (now_ptr != nullptr)
//		{
//			cout << i++ << " element: " << now_ptr->data << endl;
//			now_ptr = now_ptr->next;
//
//		}
//	}
//}
//
//void ListDelete(OneDirList*& head)
//{
//	if (head != nullptr)
//	{
//		while (head != nullptr)
//		{
//			OneDirList* now_ptr = head;
//			head = head->next;
//			delete now_ptr;
//		}
//	}
//	else cout << "an empty List\n";
//}
//
//void ListDelLast(OneDirList*& head)
//{
//	OneDirList* now_ptr = head;
//	while (now_ptr->next->next != nullptr)
//	{
//		now_ptr = now_ptr->next;
//	}
//	if (now_ptr->next->data % 2 == 0)
//	{
//		cout << "\nthe last even element " << now_ptr->next->data << " gonna be deleted\n";
//		delete now_ptr->next;
//		now_ptr->next = nullptr;
//	}
//	else cout << "\nthe last element is not even\n";
//}
//
//int main()
//{
//	srand(time(NULL));
//	OneDirList* head;
//	int ListLen;
//	cout << "Enter an amount of list elements: ";
//	cin >> ListLen;
//
//	ListFill(head, ListLen);
//	cout << endl;
//
//	ListPrint(head);
//
//	ListDelLast(head);
//	cout << endl;
//
//	ListPrint(head);
//
//	ListDelete(head);
//
//	return 0;
//}

struct DoubleDirList
{
	char data;
	DoubleDirList* next;
	DoubleDirList* prev;
};

DoubleDirList* ListFill(DoubleDirList*& head, int& ListLen)
{
	head = nullptr;
	DoubleDirList* now_ptr = new DoubleDirList;
	now_ptr->next = nullptr;
	cin >> now_ptr->data;
	head = now_ptr;
	for (int i = 1; i < ListLen; i++)
	{
		DoubleDirList* next_elem = new DoubleDirList;
		now_ptr->next = next_elem;
		next_elem->prev = now_ptr;
		now_ptr = next_elem;
		//now_ptr->prev = previous;
		cin >> now_ptr->data;

	}
	now_ptr->next = head;
	head->prev = now_ptr;
	return now_ptr;
}
void ListPrintFromBegin(DoubleDirList*& head)
{
	DoubleDirList* now_ptr = head;
	int i = 1;
	while (now_ptr->next != head)
	{
		cout << i++ << ". " << now_ptr->data << endl;
		now_ptr = now_ptr->next;
	}
	cout << i++ << ". " << now_ptr->data << endl;
}

void ListPrintFromEnd(DoubleDirList*& tail, int ListLen)
{
	DoubleDirList* now_ptr = tail;
	while (now_ptr->prev != tail)
	{
		cout << ListLen-- << ". " << now_ptr->data << endl;
		now_ptr = now_ptr->prev;
	}
	cout << ListLen-- << ". " << now_ptr->data << endl;
}

void ListAddAfterFromBeg(DoubleDirList*& head, DoubleDirList*& tail, char* data_ptr)
{
	DoubleDirList* now_ptr_beg = new DoubleDirList;
	//DoubleDirList* now_ptr_end = new DoubleDirList;
	now_ptr_beg = head;
	//now_ptr_end = tail;
	while (now_ptr_beg->next != head)
	{
		if (now_ptr_beg->data == *data_ptr)
		{
			DoubleDirList* new_elem = new DoubleDirList;
			//DoubleDirList* new_elem_ptr = new_elem;
			new_elem->data = 'B';
			new_elem->next = now_ptr_beg->next;
			now_ptr_beg->next->prev = new_elem;
			new_elem->prev = now_ptr_beg;
			//if (new_elem->next == head) tail = new_elem->next;
			now_ptr_beg->next = new_elem;
			now_ptr_beg = new_elem->next;
		}
		else now_ptr_beg = now_ptr_beg->next;
	}
	if (now_ptr_beg->next == head && now_ptr_beg->data == *data_ptr)
	{
		DoubleDirList* new_elem = new DoubleDirList;
		new_elem->data = 'B';
		new_elem->next = head;
		//head->prev = new_elem;
		//tail = new_elem;
		now_ptr_beg->next = new_elem;
		now_ptr_beg = new_elem;
	}
	tail = now_ptr_beg;
	//head->prev = tail;

}

void ListAddBeforeFromEnd(DoubleDirList*& head, DoubleDirList*& tail, char* data_ptr)
{
	DoubleDirList* now_ptr = tail;
	while (now_ptr->prev != tail)
	{
		if (now_ptr->data == *data_ptr)
		{
			DoubleDirList* new_elem = new DoubleDirList;
			new_elem->data = 'E';
			DoubleDirList* temp = now_ptr->prev;
			now_ptr->prev = new_elem;
			new_elem->prev = temp;
			now_ptr = new_elem;
		}
		else now_ptr = now_ptr->prev;
	}
	if (now_ptr->prev == tail && now_ptr->data == *data_ptr)
	{
		DoubleDirList* new_elem = new DoubleDirList;
		new_elem->data = 'E';
		new_elem->prev = tail;
		new_elem->next = now_ptr;
		tail = new_elem->prev;
		//now_ptr = new_elem->prev;
	}
	
}

int main()
{
	int ListLen;
	cout << "enter a lentgh: ";
	cin >> ListLen;

	DoubleDirList* head;

	DoubleDirList* tail = ListFill(head, ListLen);
	cout << endl;

	ListPrintFromBegin(head);
	cout << endl;

	ListPrintFromEnd(tail, ListLen);
	cout << endl;

	char data;
	cout << "enter data for setting sth after: ";
	cin >> data;
	char* data_ptr = &data;

	ListAddAfterFromBeg(head, tail, data_ptr);

	ListPrintFromBegin(head);
	cout << endl;

	ListAddBeforeFromEnd(head, tail, data_ptr);

	ListPrintFromEnd(tail, ListLen);
	cout << endl;

	return 0;
}
