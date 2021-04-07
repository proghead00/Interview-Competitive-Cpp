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

	Node *n = new Node(d);

	tail->next = n;

	return;
}

Node *merge(Node *a, Node *b)
{

	if (a == NULL)
		return b;

	if (b == NULL)
		return a;

	Node *c;

	if (a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a, b->next);
	}

	return c;
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

	Node *h1 = NULL;
	create(h1, 1);
	create(h1, 3);
	create(h1, 5);
	create(h1, 7);
	create(h1, 9);

	Node *h2 = NULL;
	create(h2, 2);
	create(h2, 4);
	create(h2, 6);
	create(h2, 8);
	create(h2, 10);

	print(h1);
	print(h2);

	// cout << merge(h1, h2) << endl;
	Node *m = merge(h1, h2);
	print(m);
	// cout << m << endl;
}