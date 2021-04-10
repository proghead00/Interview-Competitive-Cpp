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

	return;
}

int len(Node *head)
{
	Node *temp = head;
	int c = 1;

	while (temp->next != NULL)
	{
		c++;
		temp = temp->next;
	}

	return c;
}

void makeIntersection(Node *&head1, Node *&head2, int pos)
{
	Node *t1 = head1;
	pos--;
	while (pos--)
	{
		t1 = t1->next;
	}

	Node *t2 = head2;

	while (t2->next != NULL)
	{
		t2 = t2->next;
	}

	t2->next = t1;
}

int intersection(Node *&head1, Node *&head2)
{
	int l1 = len(head1);
	int l2 = len(head2);

	int d = 0;

	Node *p1;
	Node *p2;

	if (l1 > l2)
	{
		d = l1 - l2;
		p1 = head1;
		p2 = head2;
	}
	else
	{
		d = l2 - l1;
		p1 = head1;
		p2 = head2;
	}

	while (d--)
	{
		p1 = p1->next;
		if (p1 == NULL)
		{
			return -1;
		}
	}
	while (p1 != NULL and p2 != NULL)
	{
		if (p1 == p2)
			return p1->data;

		p1 = p1->next;
		p2 = p2->next;
	}

	return -1;
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

	Node *head1 = NULL;
	create(head1, 1);
	create(head1, 2);
	create(head1, 3);
	create(head1, 4);
	create(head1, 5);

	Node *head2 = NULL;
	create(head2, 9);
	create(head2, 10);

	makeIntersection(head1, head2, 3);

	print(head1);
	print(head2);

	int p = intersection(head1, head2);

	cout << p << endl;
}