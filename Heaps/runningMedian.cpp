#include <iostream>
#include <queue>
using namespace std;

int main()
{

    priority_queue<int> leftHeap;                             // max heap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // min heap

    int d;
    cin >> d;
    leftHeap.push(d);

    float median = d;
    cout << median << " ";

    cin >> d;

    while (d != -1)
    {
        // either left heap or right will be bigger or they'll be equal

        if (leftHeap.size() > rightHeap.size())
        {
            if (d < median)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }

            else
                rightHeap.push(d);

            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }

        else if (leftHeap.size() == rightHeap.size())
        {
            if (d < median)
            {
                leftHeap.push(d);
                median = leftHeap.top();
            }

            else
            {
                rightHeap.push(d);
                median = rightHeap.top();
            }
        }

        else // if leftHeap.size() < rightHeap.size()
        {
            if (d < median)
                leftHeap.push(d);

            else // if d > median, push it to right heap
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }

            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }

        cout << median << " ";
        cin >> d;
    }
}
