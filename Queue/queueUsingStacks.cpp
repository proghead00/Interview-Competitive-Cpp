#include <iostream>
#include <stack>
using namespace std;

// stack<int> s1;
// stack<int> s2;

void enq(stack<int> s1, int x)
{
    s1.push(x);
}

void deq(stack<int> s1, stack<int> s2)
{
    if (s1.empty())
        return;

    while (s1.size() > 1)
    {
        int ts1 = s1.top();
        s2.push(ts1);

        s1.pop();
    }

    cout << s1.top() << " ";
    s1.pop();

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
}

int main()
{
    stack<int> s1;
    stack<int> s2;

    enq(s1, 10);
    enq(s1, 20);
    enq(s1, 30);
    enq(s1, 40);


    deq(s1, s2);


}
