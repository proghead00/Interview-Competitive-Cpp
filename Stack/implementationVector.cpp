#include <iostream>
using namespace std;
#include <vector>

class Stack
{
private:
    vector<int> v;

public:
    void push(int data)
    {
        v.push_back(data);
    }

    bool empty()
    {
        return v.size() == 0;
    }

    void pop()
    {
        if (!empty())
            v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack s;

    for (size_t i = 0; i < 5; i++)
    {
        s.push(i);
    }

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}