#include <iostream>
using namespace std;

class Node
{

public:
	int data;
	Node *next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

void create(Node *&head, int d)
{
	if (head == NULL)
	{
		head = new Node(d);
		return;
	}

	Node *tail = head;

	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	Node *t = new Node(d);

	tail->next = t;
	t->next = NULL;
	return;
}

int length(Node *head)
{
	int c = 1;
	while (head != NULL)
	{
		c++;
		head = head->next;
	}

	return c;
}

Node *kAppend(Node *&head, int k)
{
	k += 1;
	Node *newHead;
	Node *newTail;
	Node *tail = head;

	int l = length(head);
	k = k % l; // in case k>l
	int cnt = 1;

	while (tail->next != NULL)
	{
		if (cnt == l - k)
		{
			newTail = tail;
		}

		if (cnt == l - k + 1)
		{
			newHead = tail;
		}

		tail = tail->next;
		cnt++;
	}

	newTail->next = NULL;
	tail->next = head;

	return newHead;
}

void print(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{

	Node *head = NULL;
	create(head, 1);
	create(head, 2);
	create(head, 3);
	create(head, 4);
	create(head, 5);
	create(head, 6);
	create(head, 7);

	print(head);

	Node *newHead = kAppend(head, 3);

	print(newHead);
}
