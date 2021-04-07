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

void oddEven(Node *&head)
{
    Node *oddHead = NULL;
    Node *evenHead = NULL;
    Node *lastEven = NULL;
    Node *lastOdd = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data % 2 != 0)
        {
            if (oddHead == NULL)
            {
                oddHead = lastOdd = curr;
            }
            else
            {
                lastOdd->next = curr;
                lastOdd = curr;
            }
        }

        else
        {
            if (evenHead == NULL)
            {
                evenHead = lastEven = curr;
            }
            else
            {
                lastEven->next = curr;
                lastEven = curr;
            }
        }
        curr = curr->next;
    }

    if (head != NULL)
    {
        head = oddHead;
        lastOdd->next = evenHead;
    }
    else
        head = evenHead;

    lastEven->next = NULL;
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

    oddEven(head);
    print(head);
}