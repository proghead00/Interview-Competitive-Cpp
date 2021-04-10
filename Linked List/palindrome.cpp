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

Node *reverse(Node *&sHead)
{
	Node *r = NULL;
	Node *q = NULL;

	while (sHead != NULL)
	{
		r = q;
		q = sHead;
		sHead = sHead->next;

		q->next = r;
	}

	return q; // q = head of the reversed link
}

bool palindrome(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}

	Node *slow = head;
	Node *fast = head;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverse(slow->next);

	slow = slow->next; // move slow to the head of the reversed LL

	// slow is now the head of the second part of the reversed LL
	while (slow != NULL)
	{
		if (head->data != slow->data)
		{
			return false;
		}
		slow = slow->next;
		head = head->next;
	}

	return true;
}

void print(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{

	Node *head = NULL;

	create(head, 1);
	create(head, 3);
	create(head, 5);

	create(head, 5);
	create(head, 3);
	create(head, 1);

	print(head);

	bool isPal = palindrome(head);
	cout << endl;

	if (isPal == true)
		cout << "YES";

	else
		cout << "NO";
}