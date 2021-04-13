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

class Stack
{

    Node *head;

    int sz;

public:
    Stack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "There are no nodes in the Linked List!" << endl;
            return 9999;
        }

        int res = head->data;

        Node *temp = head;
        head = head->next;
        delete (temp);

        sz--;
        return res;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    int peek()
    {

        if (head == NULL)
        {
            cout << "There are no nodes in the Linked List!" << endl;
            return 9999;
        }
        return head->data;
    }
};

int main()
{

    Stack s;

    Node *head;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;
    cout << s.peek() << endl;
}