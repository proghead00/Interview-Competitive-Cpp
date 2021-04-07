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

void printapp(Node *r, Node *q)
{

	while (r != NULL && r != q)
	{
		cout << r->data << " ";
		r = r->next;
	}
	// cout << endl;
}

void append(Node *&head, int k, int n)
{
	Node *p = head;
	int x = 1;
	for (size_t i = 1; i < n - k; i++)
	{
		if (p->next != NULL)
		{
			x++;
			p = p->next;
		}
	}
	Node *r = p->next;
	Node *q = p->next;
	p->next = NULL;
	// Node *r = NULL;

	for (size_t i = x + 1; i < n; i++)
	{
		if (q->next != NULL)
		{
			// r = q;
			q = q->next;
		}
	}

	q->next = head;

	printapp(r, q);
	// return;
	// return q;
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

	append(head, 3, 7);
	// Node *m = append(head, 3, 7);
	// print(m);
	print(head);
}
