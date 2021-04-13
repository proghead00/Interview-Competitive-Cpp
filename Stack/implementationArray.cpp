#include <iostream>
using namespace std;

class Stack
{

    int *arr;
    int cap;
    int top;

public:
    Stack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        return arr[top];
    }

    int size()
    {
        return (top + 1);
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
}