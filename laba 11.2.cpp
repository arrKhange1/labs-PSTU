#include <iostream>
using namespace std;

struct DoubleDirList
{
	char data;
	DoubleDirList* next;
	DoubleDirList* prev;
};

DoubleDirList* ListFill(DoubleDirList*& head, int ListLen)
{
	head = nullptr;
	DoubleDirList* now_ptr = new DoubleDirList;
	now_ptr->next = nullptr;
	cout << endl;
	cin >> now_ptr->data;
	head = now_ptr;
	for (int i = 1; i < ListLen; i++)
	{
		DoubleDirList* next_elem = new DoubleDirList;
		now_ptr->next = next_elem;
		next_elem->prev = now_ptr;
		now_ptr = next_elem;
		cin >> now_ptr->data;

	}
	ListLen != 1 ? now_ptr->next = head : now_ptr->prev = now_ptr;
	head->prev = now_ptr;
	return now_ptr;
}
int ListPrintFromBegin(DoubleDirList*& head)
{
	DoubleDirList* now_ptr = head;
	int i = 1;
	while (now_ptr->next != head)
	{
		cout << i++ << ". " << now_ptr->data << endl;
		now_ptr = now_ptr->next;
	}
	cout << i++ << ". " << now_ptr->data << endl;
	return i-1;
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

int ListAddAfterFromBeg(DoubleDirList*& head, DoubleDirList*& tail, char* data_ptr)
{
	int cnt = 0;
	DoubleDirList* now_ptr_beg = new DoubleDirList;
	now_ptr_beg = head;
	while (now_ptr_beg->next != head)
	{
		if (now_ptr_beg->data == *data_ptr)
		{
			cnt++;
			DoubleDirList* new_elem = new DoubleDirList;
			new_elem->data = 'B';
			new_elem->next = now_ptr_beg->next;
			now_ptr_beg->next->prev = new_elem;
			new_elem->prev = now_ptr_beg;
			now_ptr_beg->next = new_elem;
			now_ptr_beg = new_elem->next;
		}
		else now_ptr_beg = now_ptr_beg->next;
	}
	if (now_ptr_beg->next == head && now_ptr_beg->data == *data_ptr)
	{
		cnt++;
		DoubleDirList* new_elem = new DoubleDirList;
		new_elem->data = 'B';
		new_elem->next = head;
		now_ptr_beg->next = new_elem;
		new_elem->prev = now_ptr_beg;
		now_ptr_beg = new_elem;
	}
	tail = now_ptr_beg;
	head->prev = tail;
	return cnt;
}

int ListAddBeforeFromEnd(DoubleDirList*& head, DoubleDirList*& tail, char* data_ptr)
{
	int cnt = 0;
	DoubleDirList* now_ptr = tail;
	while (now_ptr->prev != tail)
	{
		if (now_ptr->data == *data_ptr)
		{
			cnt++;
			DoubleDirList* new_elem = new DoubleDirList;
			new_elem->data = 'E';
			new_elem->prev = now_ptr->prev;
			now_ptr->prev = new_elem;
			now_ptr = new_elem;
		}
		else now_ptr = now_ptr->prev;
	}
	if (now_ptr->prev == tail && now_ptr->data == *data_ptr)
	{
		cnt++;
		DoubleDirList* new_elem = new DoubleDirList;
		new_elem->data = 'E';
		now_ptr->prev = new_elem;
		new_elem->prev = tail;
		new_elem->next = now_ptr;
		now_ptr = new_elem;
	}
	head = now_ptr;
	return cnt;
}

int main()
{
	int ListLen;	
	cout << "enter a lentgh: ";
	cin >> ListLen;
	while (ListLen == 1) cin >> ListLen;

	DoubleDirList* head;

	cout << "enter " << ListLen << " symbols: ";
	DoubleDirList* tail = ListFill(head, ListLen);
	cout << endl;

	ListLen = ListPrintFromBegin(head);
	cout << endl;

	ListPrintFromEnd(tail, ListLen);
	cout << endl;

	char data;
	cout << "enter data for setting sth after: ";
	cin >> data;
	char* data_ptr = &data;

	ListLen += ListAddAfterFromBeg(head, tail, data_ptr);

	ListPrintFromBegin(head);
	cout << endl;

	ListLen += ListAddBeforeFromEnd(head, tail, data_ptr);

	ListPrintFromEnd(tail, ListLen);
	cout << endl;

	return 0;
}
