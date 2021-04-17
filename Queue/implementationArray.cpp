#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, curr_size, max_size;

public:
    Queue(int default_size = 5)
    {

        arr = new int[default_size];
        curr_size = 0;
        max_size = default_size;
        front = 0;
        rear = max_size - 1;
    }

    bool full()
    {
        return curr_size == max_size;
    }

    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % max_size;
            arr[rear] = data;
            curr_size++;
        }
    }

    bool empty()
    {
        return curr_size == 0;
    }

    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % max_size;
            curr_size--;
        }
    }

    int front2()
    {
        if (!empty())
        {
            return arr[front];
        }
    }

    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{

    Queue q(100);

    for (size_t i = 0; i <= 6; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    q.push(7);

    while (!q.empty())
    {
        cout << q.front2() << " ";
        q.pop();
    }
}
