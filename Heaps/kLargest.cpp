#include <iostream>
#include <queue>
using namespace std;

int kLargest(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int c = 0;

    for (size_t i = 0; i < v.size(); i++)
    {
        if (c < k) // we're gonna keep only 3 elements in the heap and pop/push when necessary; thus we need a count variable
        {
            pq.push(v[i]);
            c++;
        }
        else
        {
            if (v[i] > pq.top())
            {
                pq.pop();
                pq.push(v[i]);
            }
        }
    }

    return pq.top();
}

int main()
{

    vector<int> v{2, 4, 1, 7, 5, 3};

    int k;
    cin >> k;

    cout << kLargest(v, k) << " ";
}
