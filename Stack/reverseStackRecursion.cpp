#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int data = s.top();
    s.pop();
    insertAtBottom(s, x);

    s.push(data);
}

void revRec(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    // pop out the top element and insert it at the bottom of reversed smaller stack
    int x = s.top();
    s.pop();

    // rec reverse the smaller stack
    revRec(s);

    insertAtBottom(s, x);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    revRec(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}