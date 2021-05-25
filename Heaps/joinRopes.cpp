#include <iostream>
#include <queue>
using namespace std;

int joinRopes(int ropes[], int n)
{
    // min heap -> greater<int>

    // declare like this to directly make a min heap outta the array
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);

    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int newRope = a + b;
        cost += newRope;

        pq.push(newRope);
    }

    return cost;
}

int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = 4;

    cout << joinRopes(ropes, n) << endl;
}
