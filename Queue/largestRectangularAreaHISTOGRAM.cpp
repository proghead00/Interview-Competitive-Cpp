#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    stack<int> s;
    int res = 0;
    int n = 5;
    int curr = -1;
    int tp = -1;
    for (size_t i = 0; i < n; i++)
    {
        while (!s.empty() and arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();

            curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));

            res = max(res, curr);
        }

        s.push(i);
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();

        curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));

        res = max(res, curr);
    }

    cout << res;
}
